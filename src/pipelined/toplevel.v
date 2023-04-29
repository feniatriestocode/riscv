`include "constants.vh"
`include "config.vh"
`include "cpu.v"

module toplevel(
    input clock,
    input reset,
    output MemWriteEnable, 
    output [31:0] MemAddr,
    output [31:0] WriteData
);

cpu cpu(.clock(clock),
        .reset(reset),
        .MemWriteEnable(MemWriteEnable),
        .MemAddr(MemAddr),
        .WriteData(WriteData));

endmodule