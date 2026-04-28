module vercore_regfile (
    input              clk,
    input              rst_n,
    input      [4:0]   rs1_addr,
    input      [4:0]   rs2_addr,
    output     [31:0]  rs1_rdata,
    output     [31:0]  rs2_rdata,
    input              rd_we,
    input      [4:0]   rd_addr,
    input      [31:0]  rd_wdata
);
    reg [31:0] regs[0:31];
    integer i;

    always @(posedge clk) begin
        if (!rst_n) begin
            for (i = 0; i < 32; i = i + 1) begin
                regs[i] <= 32'b0;
            end
        end else if (rd_we && (rd_addr != 5'd0)) begin
            regs[rd_addr] <= rd_wdata;
        end
    end

    assign rs1_rdata = (rs1_addr == 5'd0) ? 32'b0 :
                       ((rd_we && (rd_addr == rs1_addr) && (rd_addr != 5'd0)) ? rd_wdata : regs[rs1_addr]);
    assign rs2_rdata = (rs2_addr == 5'd0) ? 32'b0 :
                       ((rd_we && (rd_addr == rs2_addr) && (rd_addr != 5'd0)) ? rd_wdata : regs[rs2_addr]);

endmodule
