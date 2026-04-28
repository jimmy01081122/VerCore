module vercore_pipeline_regs #(
    parameter WIDTH = 32
) (
    input                  clk,
    input                  rst_n,
    input                  stall,
    input                  flush,
    input      [WIDTH-1:0] d,
    output reg [WIDTH-1:0] q
);
    always @(posedge clk) begin
        if (!rst_n) begin
            q <= {WIDTH{1'b0}};
        end else if (flush) begin
            q <= {WIDTH{1'b0}};
        end else if (!stall) begin
            q <= d;
        end
    end
endmodule
