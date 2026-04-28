module vercore_alu (
    input      [31:0] a,
    input      [31:0] b,
    input      [4:0]  alu_op,
    output reg [31:0] y
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

    reg [31:0] mul_lo;
    reg [31:0] mulh_hi;
    reg [31:0] mulhu_hi;
    reg [31:0] mulhsu_hi;

    always @(*) begin
        mul_lo = a * b;
        mulh_hi = ($signed(a) * $signed(b)) >>> 32;
        mulhu_hi = (a * b) >> 32;
        /* verilator lint_off WIDTH */
        mulhsu_hi = ($signed(a) * $signed({1'b0, b})) >>> 32;
        /* verilator lint_on WIDTH */

        case (alu_op)
            ALU_ADD:    y = a + b;
            ALU_SUB:    y = a - b;
            ALU_AND:    y = a & b;
            ALU_OR:     y = a | b;
            ALU_XOR:    y = a ^ b;
            ALU_SLT:    y = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
            ALU_SLTU:   y = (a < b) ? 32'd1 : 32'd0;
            ALU_SLL:    y = a << b[4:0];
            ALU_SRL:    y = a >> b[4:0];
            ALU_SRA:    y = $signed(a) >>> b[4:0];
            ALU_COPY_B: y = b;
            ALU_MUL:    y = mul_lo;
            ALU_MULH:   y = mulh_hi;
            ALU_MULHSU: y = mulhsu_hi;
            ALU_MULHU:  y = mulhu_hi;
            default:    y = 32'b0;
        endcase
    end

endmodule
