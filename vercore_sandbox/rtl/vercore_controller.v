module vercore_controller (
    input      [6:0]  opcode_d,
    input      [2:0]  funct3_in_d,
    input      [6:0]  funct7_d,
    input      [4:0]  rs1_d,
    input      [4:0]  rs2_d,
    input      [4:0]  rs1_e,
    input      [4:0]  rs2_e,
    input      [4:0]  rd_e,
    input      [4:0]  rd_m,
    input      [4:0]  rd_w,
    input             regwrite_m,
    input             regwrite_w,
    input             memread_e,
    input             branch_taken_e,
    input             icache_valid,
    input             mem_busy_m,
    output reg        stall_f,
    output reg        stall_d,
    output reg        stall_e,
    output reg        stall_m,
    output reg        flush_d,
    output reg        flush_e,
    output reg [1:0]  fwd_a_sel,
    output reg [1:0]  fwd_b_sel,
    output reg        regwrite_d,
    output reg        memread_d,
    output reg        memwrite_d,
    output reg [1:0]  mem_size_d,
    output reg        alu_src_d,
    output reg [1:0]  wb_sel_d,
    output reg [4:0]  alu_op_d,
    output reg        branch_d,
    output reg        jump_d,
    output reg        jump_reg_d,
    output reg [2:0]  funct3_d
);
    localparam ALU_ADD    = 5'd0;
    localparam ALU_SUB    = 5'd1;
    localparam ALU_AND    = 5'd2;
    localparam ALU_OR     = 5'd3;
    localparam ALU_XOR    = 5'd4;
    localparam ALU_SLT    = 5'd5;
    localparam ALU_SLTU   = 5'd6;
    localparam ALU_SLL    = 5'd7;
    localparam ALU_SRL    = 5'd8;
    localparam ALU_SRA    = 5'd9;
    localparam ALU_COPY_B = 5'd10;
    localparam ALU_MUL    = 5'd11;
    localparam ALU_MULH   = 5'd12;
    localparam ALU_MULHSU = 5'd13;
    localparam ALU_MULHU  = 5'd14;

    wire load_use_hazard;

    assign load_use_hazard = memread_e &&
                             (rd_e != 5'd0) &&
                             ((rd_e == rs1_d) || (rd_e == rs2_d));

    always @(*) begin
        regwrite_d = 1'b0;
        memread_d  = 1'b0;
        memwrite_d = 1'b0;
        mem_size_d = 2'b10;
        alu_src_d  = 1'b0;
        wb_sel_d   = 2'b00;
        alu_op_d   = ALU_ADD;
        branch_d   = 1'b0;
        jump_d     = 1'b0;
        jump_reg_d = 1'b0;
        funct3_d   = funct3_in_d;

        case (opcode_d)
            7'b0110011: begin
                regwrite_d = 1'b1;
                wb_sel_d   = 2'b00;
                case (funct3_in_d)
                    3'b000: begin
                        if (funct7_d == 7'b0100000) begin
                            alu_op_d = ALU_SUB;
                        end else if (funct7_d == 7'b0000001) begin
                            alu_op_d = ALU_MUL;
                        end else begin
                            alu_op_d = ALU_ADD;
                        end
                    end
                    3'b001: begin
                        if (funct7_d == 7'b0000001) begin
                            alu_op_d = ALU_MULH;
                        end else begin
                            alu_op_d = ALU_SLL;
                        end
                    end
                    3'b010: alu_op_d = ALU_SLT;
                    3'b011: begin
                        if (funct7_d == 7'b0000001) begin
                            alu_op_d = ALU_MULHU;
                        end else begin
                            alu_op_d = ALU_SLTU;
                        end
                    end
                    3'b100: begin
                        if (funct7_d == 7'b0000001) begin
                            alu_op_d = ALU_MULHSU;
                        end else begin
                            alu_op_d = ALU_XOR;
                        end
                    end
                    3'b101: begin
                        if (funct7_d == 7'b0100000) begin
                            alu_op_d = ALU_SRA;
                        end else begin
                            alu_op_d = ALU_SRL;
                        end
                    end
                    3'b110: alu_op_d = ALU_OR;
                    3'b111: alu_op_d = ALU_AND;
                    default: alu_op_d = ALU_ADD;
                endcase
            end
            7'b0010011: begin
                regwrite_d = 1'b1;
                alu_src_d  = 1'b1;
                wb_sel_d   = 2'b00;
                case (funct3_in_d)
                    3'b000: alu_op_d = ALU_ADD;
                    3'b010: alu_op_d = ALU_SLT;
                    3'b011: alu_op_d = ALU_SLTU;
                    3'b100: alu_op_d = ALU_XOR;
                    3'b110: alu_op_d = ALU_OR;
                    3'b111: alu_op_d = ALU_AND;
                    3'b001: alu_op_d = ALU_SLL;
                    3'b101: begin
                        if (funct7_d[5]) begin
                            alu_op_d = ALU_SRA;
                        end else begin
                            alu_op_d = ALU_SRL;
                        end
                    end
                    default: alu_op_d = ALU_ADD;
                endcase
            end
            7'b0000011: begin
                regwrite_d = 1'b1;
                memread_d  = 1'b1;
                alu_src_d  = 1'b1;
                wb_sel_d   = 2'b01;
                alu_op_d   = ALU_ADD;
                if (funct3_in_d == 3'b000) begin
                    mem_size_d = 2'b00;
                end else if (funct3_in_d == 3'b001) begin
                    mem_size_d = 2'b01;
                end else begin
                    mem_size_d = 2'b10;
                end
            end
            7'b0100011: begin
                memwrite_d = 1'b1;
                alu_src_d  = 1'b1;
                alu_op_d   = ALU_ADD;
                if (funct3_in_d == 3'b000) begin
                    mem_size_d = 2'b00;
                end else if (funct3_in_d == 3'b001) begin
                    mem_size_d = 2'b01;
                end else begin
                    mem_size_d = 2'b10;
                end
            end
            7'b1100011: begin
                branch_d = 1'b1;
                alu_op_d = ALU_SUB;
            end
            7'b1101111: begin
                jump_d     = 1'b1;
                regwrite_d = 1'b1;
                wb_sel_d   = 2'b10;
            end
            7'b1100111: begin
                jump_d     = 1'b1;
                jump_reg_d = 1'b1;
                regwrite_d = 1'b1;
                wb_sel_d   = 2'b10;
                alu_src_d  = 1'b1;
                alu_op_d   = ALU_ADD;
            end
            7'b0110111: begin
                regwrite_d = 1'b1;
                wb_sel_d   = 2'b00;
                alu_src_d  = 1'b1;
                alu_op_d   = ALU_COPY_B;
            end
            7'b0010111: begin
                regwrite_d = 1'b1;
                wb_sel_d   = 2'b00;
                alu_src_d  = 1'b1;
                alu_op_d   = ALU_ADD;
            end
            default: begin
            end
        endcase
    end

    always @(*) begin
        stall_f = 1'b0;
        stall_d = 1'b0;
        stall_e = 1'b0;
        stall_m = 1'b0;
        flush_d = 1'b0;
        flush_e = 1'b0;

        if (!icache_valid) begin
            stall_f = 1'b1;
        end

        if (load_use_hazard) begin
            stall_f = 1'b1;
            stall_d = 1'b1;
            flush_e = 1'b1;
        end

        if (mem_busy_m) begin
            stall_f = 1'b1;
            stall_d = 1'b1;
            stall_e = 1'b1;
            stall_m = 1'b1;
        end

        if (branch_taken_e) begin
            flush_d = 1'b1;
            flush_e = 1'b1;
        end
    end

    always @(*) begin
        fwd_a_sel = 2'b00;
        fwd_b_sel = 2'b00;

        if (regwrite_m && (rd_m != 5'd0) && (rd_m == rs1_e)) begin
            fwd_a_sel = 2'b01;
        end else if (regwrite_w && (rd_w != 5'd0) && (rd_w == rs1_e)) begin
            fwd_a_sel = 2'b10;
        end

        if (regwrite_m && (rd_m != 5'd0) && (rd_m == rs2_e)) begin
            fwd_b_sel = 2'b01;
        end else if (regwrite_w && (rd_w != 5'd0) && (rd_w == rs2_e)) begin
            fwd_b_sel = 2'b10;
        end
    end

endmodule
