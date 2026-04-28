module vercore_top (
    input             clk,
    input             rst_n,
    output            icache_req,
    output     [31:0] icache_addr,
    input      [31:0] icache_rdata,
    input             icache_valid,
    output            dcache_req,
    output            dcache_we,
    output     [1:0]  dcache_size,
    output     [31:0] dcache_addr,
    output     [31:0] dcache_wdata,
    input      [31:0] dcache_rdata,
    input             dcache_ready,
    output            dbg_retire_valid,
    output     [31:0] dbg_retire_pc,
    output     [31:0] dbg_retire_instr,
    output            dbg_retire_rd_we,
    output     [4:0]  dbg_retire_rd_addr,
    output     [31:0] dbg_retire_rd_data
);
    localparam RESET_PC = 32'h8000_0000;
    reg [31:0] pc_f;
    reg drop_icache_resp;
    wire [31:0] pc_next_f;
    wire [31:0] pc_plus4_f;
    wire icache_accept_valid;

    wire stall_f;
    wire stall_d;
    wire stall_e;
    wire stall_m;
    wire flush_d;
    wire flush_e;
    wire [1:0] fwd_a_sel;
    wire [1:0] fwd_b_sel;

    wire [64:0] ifid_d;
    wire [64:0] ifid_q;
    wire [31:0] pc_d;
    wire [31:0] instr_d;
    wire        valid_d;

    wire [31:0] rs1_data_d;
    wire [31:0] rs2_data_d;
    wire [4:0] rs1_d;
    wire [4:0] rs2_d;
    wire [4:0] rd_d;
    wire [31:0] imm_d;

    wire regwrite_d;
    wire memread_d;
    wire memwrite_d;
    wire [1:0] mem_size_d;
    wire alu_src_d;
    wire [1:0] wb_sel_d;
    wire [4:0] alu_op_d;
    wire branch_d;
    wire jump_d;
    wire jump_reg_d;
    wire [2:0] funct3_d;

    wire [194:0] idex_d;
    wire [194:0] idex_q;

    wire [31:0] pc_e;
    wire [6:0]  opcode_e;
    wire [31:0] rs1_e_raw;
    wire [31:0] rs2_e_raw;
    wire [31:0] imm_e;
    wire [4:0]  rs1_e;
    wire [4:0]  rs2_e;
    wire [4:0]  rd_e;
    wire [4:0]  alu_op_e;
    wire [2:0]  funct3_e;
    wire [1:0]  mem_size_e;
    wire [1:0]  wb_sel_e;
    wire        regwrite_e;
    wire        memread_e;
    wire        memwrite_e;
    wire        alu_src_e;
    wire        branch_e;
    wire        jump_e;
    wire        jump_reg_e;
    wire        valid_e;

    reg [31:0] op_a_e;
    reg [31:0] op_b_e_fwd;
    wire [31:0] op_b_e;

    wire [31:0] alu_y_e;
    wire [31:0] branch_target_e;
    wire        is_auipc_e;
    reg         branch_taken_e;

    wire [175:0] exmem_d;
    wire [175:0] exmem_q;

    wire [31:0] alu_m;
    wire [31:0] store_data_m;
    wire [31:0] pc_m;
    wire [31:0] pc4_m;
    wire [31:0] instr_m;
    wire [4:0]  rd_m;
    wire [2:0]  funct3_m;
    wire [1:0]  mem_size_m;
    wire [1:0]  wb_sel_m;
    wire        regwrite_m;
    wire        memread_m;
    wire        memwrite_m;
    wire        valid_m;
    wire        mem_busy_m;

    reg [31:0] load_data_m;
    wire [31:0] wb_data_m;

    wire [102:0] memwb_d;
    wire [102:0] memwb_q;

    wire [31:0] wb_data_w;
    wire [31:0] pc_w;
    wire [31:0] instr_w;
    wire [4:0]  rd_w;
    wire        regwrite_w;
    wire        valid_w;

    assign pc_plus4_f = pc_f + 32'd4;
    assign icache_req = 1'b1;
    assign icache_addr = pc_f;

    assign icache_accept_valid = icache_valid && !drop_icache_resp;
    assign ifid_d = {icache_accept_valid, pc_f, icache_rdata};

    assign valid_d = ifid_q[64];
    assign pc_d = ifid_q[63:32];
    assign instr_d = ifid_q[31:0];

    assign rs1_d = instr_d[19:15];
    assign rs2_d = instr_d[24:20];
    assign rd_d = instr_d[11:7];

    assign imm_d = ({32{instr_d[6:0] == 7'b0010011 || instr_d[6:0] == 7'b0000011 || instr_d[6:0] == 7'b1100111}} &
                    {{20{instr_d[31]}}, instr_d[31:20]}) |
                   ({32{instr_d[6:0] == 7'b0100011}} &
                    {{20{instr_d[31]}}, instr_d[31:25], instr_d[11:7]}) |
                   ({32{instr_d[6:0] == 7'b1100011}} &
                    {{19{instr_d[31]}}, instr_d[31], instr_d[7], instr_d[30:25], instr_d[11:8], 1'b0}) |
                   ({32{instr_d[6:0] == 7'b0110111 || instr_d[6:0] == 7'b0010111}} &
                    {instr_d[31:12], 12'b0}) |
                   ({32{instr_d[6:0] == 7'b1101111}} &
                    {{11{instr_d[31]}}, instr_d[31], instr_d[19:12], instr_d[20], instr_d[30:21], 1'b0});

    assign idex_d = {
        pc_d,
        rs1_data_d,
        rs2_data_d,
        imm_d,
        instr_d,
        rs1_d,
        rs2_d,
        rd_d,
        alu_op_d,
        funct3_d,
        mem_size_d,
        wb_sel_d,
        regwrite_d,
        memread_d,
        memwrite_d,
        alu_src_d,
        branch_d,
        jump_d,
        jump_reg_d,
        valid_d
    };

    assign pc_e = idex_q[194:163];
    assign rs1_e_raw = idex_q[162:131];
    assign rs2_e_raw = idex_q[130:99];
    assign imm_e = idex_q[98:67];
    assign opcode_e = idex_q[41:35];
    assign rs1_e = idex_q[34:30];
    assign rs2_e = idex_q[29:25];
    assign rd_e = idex_q[24:20];
    assign alu_op_e = idex_q[19:15];
    assign funct3_e = idex_q[14:12];
    assign mem_size_e = idex_q[11:10];
    assign wb_sel_e = idex_q[9:8];
    assign regwrite_e = idex_q[7];
    assign memread_e = idex_q[6];
    assign memwrite_e = idex_q[5];
    assign alu_src_e = idex_q[4];
    assign branch_e = idex_q[3];
    assign jump_e = idex_q[2];
    assign jump_reg_e = idex_q[1];
    assign valid_e = idex_q[0];
    assign is_auipc_e = (opcode_e == 7'b0010111);

    assign op_b_e = alu_src_e ? imm_e : op_b_e_fwd;
    assign branch_target_e = (jump_e && jump_reg_e) ? ((op_a_e + imm_e) & 32'hffff_fffe) : (pc_e + imm_e);

    assign exmem_d = {
        alu_y_e,
        op_b_e_fwd,
        pc_e,
        pc_e + 32'd4,
        idex_q[66:35],
        rd_e,
        funct3_e,
        mem_size_e,
        wb_sel_e,
        regwrite_e,
        memread_e,
        memwrite_e,
        valid_e
    };

    assign alu_m = exmem_q[175:144];
    assign store_data_m = exmem_q[143:112];
    assign pc_m = exmem_q[111:80];
    assign pc4_m = exmem_q[79:48];
    assign instr_m = exmem_q[47:16];
    assign rd_m = exmem_q[15:11];
    assign funct3_m = exmem_q[10:8];
    assign mem_size_m = exmem_q[7:6];
    assign wb_sel_m = exmem_q[5:4];
    assign regwrite_m = exmem_q[3];
    assign memread_m = exmem_q[2];
    assign memwrite_m = exmem_q[1];
    assign valid_m = exmem_q[0];

    assign mem_busy_m = valid_m && (memread_m || memwrite_m) && !dcache_ready;

    assign dcache_req = valid_m && (memread_m || memwrite_m);
    assign dcache_we = memwrite_m;
    assign dcache_size = mem_size_m;
    assign dcache_addr = alu_m;
    assign dcache_wdata = store_data_m;

    assign wb_data_m = (wb_sel_m == 2'b00) ? alu_m :
                       (wb_sel_m == 2'b01) ? load_data_m :
                       pc4_m;

    assign memwb_d = {
        wb_data_m,
        pc_m,
        instr_m,
        rd_m,
        regwrite_m,
        valid_m && !mem_busy_m
    };

    assign wb_data_w = memwb_q[102:71];
    assign pc_w = memwb_q[70:39];
    assign instr_w = memwb_q[38:7];
    assign rd_w = memwb_q[6:2];
    assign regwrite_w = memwb_q[1];
    assign valid_w = memwb_q[0];

    assign pc_next_f = branch_taken_e ? branch_target_e : pc_plus4_f;
    assign dbg_retire_valid = valid_w;
    assign dbg_retire_pc = pc_w;
    assign dbg_retire_instr = instr_w;
    assign dbg_retire_rd_we = regwrite_w && (rd_w != 5'd0);
    assign dbg_retire_rd_addr = rd_w;
    assign dbg_retire_rd_data = wb_data_w;

    always @(*) begin
        if (is_auipc_e) begin
            op_a_e = pc_e;
        end else begin
            case (fwd_a_sel)
                2'b01: op_a_e = alu_m;
                2'b10: op_a_e = wb_data_w;
                default: op_a_e = rs1_e_raw;
            endcase
        end

        case (fwd_b_sel)
            2'b01: op_b_e_fwd = alu_m;
            2'b10: op_b_e_fwd = wb_data_w;
            default: op_b_e_fwd = rs2_e_raw;
        endcase
    end

    always @(*) begin
        branch_taken_e = 1'b0;
        if (jump_e) begin
            branch_taken_e = 1'b1;
        end else if (branch_e) begin
            case (funct3_e)
                3'b000: branch_taken_e = (op_a_e == op_b_e_fwd);
                3'b001: branch_taken_e = (op_a_e != op_b_e_fwd);
                3'b100: branch_taken_e = ($signed(op_a_e) < $signed(op_b_e_fwd));
                3'b101: branch_taken_e = ($signed(op_a_e) >= $signed(op_b_e_fwd));
                3'b110: branch_taken_e = (op_a_e < op_b_e_fwd);
                3'b111: branch_taken_e = (op_a_e >= op_b_e_fwd);
                default: branch_taken_e = 1'b0;
            endcase
        end
    end

    always @(*) begin
        load_data_m = dcache_rdata;
        case (funct3_m)
            3'b000: begin
                case (alu_m[1:0])
                    2'b00: load_data_m = {{24{dcache_rdata[7]}}, dcache_rdata[7:0]};
                    2'b01: load_data_m = {{24{dcache_rdata[15]}}, dcache_rdata[15:8]};
                    2'b10: load_data_m = {{24{dcache_rdata[23]}}, dcache_rdata[23:16]};
                    default: load_data_m = {{24{dcache_rdata[31]}}, dcache_rdata[31:24]};
                endcase
            end
            3'b001: begin
                if (alu_m[1]) begin
                    load_data_m = {{16{dcache_rdata[31]}}, dcache_rdata[31:16]};
                end else begin
                    load_data_m = {{16{dcache_rdata[15]}}, dcache_rdata[15:0]};
                end
            end
            3'b100: begin
                case (alu_m[1:0])
                    2'b00: load_data_m = {24'b0, dcache_rdata[7:0]};
                    2'b01: load_data_m = {24'b0, dcache_rdata[15:8]};
                    2'b10: load_data_m = {24'b0, dcache_rdata[23:16]};
                    default: load_data_m = {24'b0, dcache_rdata[31:24]};
                endcase
            end
            3'b101: begin
                if (alu_m[1]) begin
                    load_data_m = {16'b0, dcache_rdata[31:16]};
                end else begin
                    load_data_m = {16'b0, dcache_rdata[15:0]};
                end
            end
            default: load_data_m = dcache_rdata;
        endcase
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            pc_f <= RESET_PC;
            drop_icache_resp <= 1'b0;
        end else begin
            if (branch_taken_e) begin
                pc_f <= branch_target_e;
            end else if (!stall_f) begin
                pc_f <= pc_next_f;
            end
            if (branch_taken_e) begin
                drop_icache_resp <= 1'b1;
            end else if (drop_icache_resp && icache_valid) begin
                drop_icache_resp <= 1'b0;
            end
        end
    end

    vercore_regfile u_regfile (
        .clk      (clk),
        .rst_n    (rst_n),
        .rs1_addr (rs1_d),
        .rs2_addr (rs2_d),
        .rs1_rdata(rs1_data_d),
        .rs2_rdata(rs2_data_d),
        .rd_we    (regwrite_w && valid_w),
        .rd_addr  (rd_w),
        .rd_wdata (wb_data_w)
    );

    vercore_alu u_alu (
        .a      (op_a_e),
        .b      (op_b_e),
        .alu_op (alu_op_e),
        .y      (alu_y_e)
    );

    vercore_controller u_controller (
        .opcode_d      (instr_d[6:0]),
        .funct3_in_d   (instr_d[14:12]),
        .funct7_d      (instr_d[31:25]),
        .rs1_d         (rs1_d),
        .rs2_d         (rs2_d),
        .rs1_e         (rs1_e),
        .rs2_e         (rs2_e),
        .rd_e          (rd_e),
        .rd_m          (rd_m),
        .rd_w          (rd_w),
        .regwrite_m    (regwrite_m),
        .regwrite_w    (regwrite_w),
        .memread_e     (memread_e),
        .branch_taken_e(branch_taken_e),
        .icache_valid  (icache_accept_valid),
        .mem_busy_m    (mem_busy_m),
        .stall_f       (stall_f),
        .stall_d       (stall_d),
        .stall_e       (stall_e),
        .stall_m       (stall_m),
        .flush_d       (flush_d),
        .flush_e       (flush_e),
        .fwd_a_sel     (fwd_a_sel),
        .fwd_b_sel     (fwd_b_sel),
        .regwrite_d    (regwrite_d),
        .memread_d     (memread_d),
        .memwrite_d    (memwrite_d),
        .mem_size_d    (mem_size_d),
        .alu_src_d     (alu_src_d),
        .wb_sel_d      (wb_sel_d),
        .alu_op_d      (alu_op_d),
        .branch_d      (branch_d),
        .jump_d        (jump_d),
        .jump_reg_d    (jump_reg_d),
        .funct3_d      (funct3_d)
    );

    vercore_pipeline_regs #(
        .WIDTH(65)
    ) u_if_id (
        .clk  (clk),
        .rst_n(rst_n),
        .stall(stall_d),
        .flush(flush_d),
        .d    (ifid_d),
        .q    (ifid_q)
    );

    vercore_pipeline_regs #(
        .WIDTH(195)
    ) u_id_ex (
        .clk  (clk),
        .rst_n(rst_n),
        .stall(stall_e),
        .flush(flush_e),
        .d    (idex_d),
        .q    (idex_q)
    );

    vercore_pipeline_regs #(
        .WIDTH(176)
    ) u_ex_mem (
        .clk  (clk),
        .rst_n(rst_n),
        .stall(stall_m),
        .flush(1'b0),
        .d    (exmem_d),
        .q    (exmem_q)
    );

    vercore_pipeline_regs #(
        .WIDTH(103)
    ) u_mem_wb (
        .clk  (clk),
        .rst_n(rst_n),
        .stall(1'b0),
        .flush(1'b0),
        .d    (memwb_d),
        .q    (memwb_q)
    );

endmodule
