/*****************************************************************************************/
/* Implementation of the 5-stage MIPS pipeline that supports the following instructions: */
/*  R-format: add, sub, and, or, xor, slt                                                */
/*  addi, lw, sw, beq, j                                                                 */
/*****************************************************************************************/
module cpu(input clock, input reset);
 reg [31:0] PC; 
 reg [31:0] IFID_PCplus4, IFID_instr;
 wire [31:0] instr;
 reg [31:0] IDEX_signExtend;
 wire [31:0] IDEX_rdA, IDEX_rdB;
 reg [31:0] IDEX_PCplus4;
 reg [4:0]  IDEX_instr_rs2, IDEX_instr_rs1, IDEX_instr_rd;                            
 reg        IDEX_RegDst, IDEX_ALUSrc;
 reg [1:0]  IDEX_ALUcntrl;
 reg        IDEX_BranchZ, IDEX_BranchNZ, IDEX_MemRead, IDEX_MemWrite; 
 reg        IDEX_MemToReg, IDEX_RegWrite;                
 reg [4:0]  EXMEM_RegWriteAddr;
 reg [31:0] EXMEM_ALUOut;
 reg [31:0] EXMEM_BranchALUOut;
 reg        EXMEM_Zero;
 reg [31:0] EXMEM_MemWriteData;
 reg        EXMEM_BranchZ, EXMEM_BranchNZ, EXMEM_MemRead, EXMEM_MemWrite, EXMEM_RegWrite, EXMEM_MemToReg;
 reg [31:0] MEMWB_DMemOut;
 reg [4:0]  MEMWB_RegWriteAddr;
 reg [31:0] MEMWB_ALUOut;
 reg        MEMWB_MemToReg, MEMWB_RegWrite;
 wire [31:0] ALUInA, ALUInB, ALUOut, BranchALUOut, bypassOutB, DMemOut, wRegData;
 wire [31:0] PCplus4, JumpAddress, PC_br, PC_new;
 wire Zero, RegDst, MemRead, MemWrite, MemToReg, ALUSrc, PCSrc, RegWrite, BranchZ, BranchNZ, Jump;
 wire bubble_ifid, bubble_idex, bubble_exmem, bubble_memwb;   // create a NOP in respective stages
 wire write_ifid, write_idex, write_exmem, write_memwb, write_pc;  // enable/disable pipeline registers
 wire [6:0] opcode;
 wire [2:0] funct3; 
 wire [6:0] funct7;
 wire [4:0] instr_rs1, instr_rs2, instr_rd, RegWriteAddr;
 wire [3:0] ALUOp;
 wire [1:0] ALUcntrl, bypassA, bypassB;
 wire [31:0] imm_i, imm_s, imm_b, imm_u, imm_j;

/********************** Instruction Fetch Unit (IF)  **********************/
 always @(posedge clock or negedge reset)
  begin 
    if (reset == 1'b0)     
       PC <= -1;     
    else if (PC == -1)
       PC <= 0;
    else if (write_pc == 1'b1)
       PC <= PC_new;
  end
  
 // PC adder
  assign PCplus4 = PC + 32'd4;

  // PCSrc multiplexer (branch or not)
  assign PC_new = (PCSrc == 1'b0) ? ((Jump == 1'b0) ? PCplus4 : JumpAddress) : EXMEM_BranchALUOut;

  // IFID pipeline register
 always @(posedge clock or negedge reset)
  begin 
    if ((reset == 1'b0) || (bubble_ifid == 1'b1))    
      begin
        IFID_PCplus4 <= 32'b0;    
        IFID_instr <= 32'b0;
      end 
    else if (write_ifid == 1'b1)
      begin
        IFID_PCplus4 <= PCplus4;
        IFID_instr <= instr;
    end
  end
  
// Instruction memory
Memory cpu_IMem(clock, reset, write_ifid, 1'b0, PC>>2, 32'b0, instr);
  

  
/***************************** Instruction Decode Unit (ID)  *******************/
assign opcode = IFID_instr[6:0];
assign funct3 = IFID_instr[14:12];
assign funct7 = IFID_instr[31:25];
assign instr_rs1 = IFID_instr[19:15];
assign instr_rs2 = IFID_instr[24:20];
assign instr_rd = IFID_instr[11:7];
assign imm_i = {20{IFID_instr[31]}, IFID_instr[31:20]};
assign imm_s = {20{IFID_instr[31]}, IFID_instr[31:25], IFID_instr[11:7]};
assign imm_b = {19{IFID_instr[31]}, IFID_instr[31], IFID_instr[7], IFID_instr[30:25], IFID_instr[11:8], 0};
assign imm_u = {IFID_instr[31:12], 12{0}};
assign imm_j = {20{IFID_instr[31]}, IFID_instr[31], IFID_instr[19:12], IFID_instr[20], IFID_instr[30:21], 0};

wire [31:0] rda, rdb;
// Register file
RegFile cpu_regs(clock, reset, instr_rs1, instr_rs2, MEMWB_RegWriteAddr, 
                 MEMWB_RegWrite, wRegData, IDEX_rdA, IDEX_rdB);

  // IDEX pipeline register
 always @(posedge clock or negedge reset)
  begin 
    if ((reset == 1'b0) || (bubble_idex == 1'b1))
      begin
       IDEX_signExtend <= 32'b0;
       IDEX_instr_rd <= 5'b0;
       IDEX_instr_rs1 <= 5'b0;
       IDEX_instr_rs2 <= 5'b0;
       IDEX_instr_shamt <= 5'b0;
       IDEX_RegDst <= 1'b0;
       IDEX_ALUcntrl <= 2'b0;
       IDEX_ALUSrc <= 1'b0;
       IDEX_BranchZ <= 1'b0;
       IDEX_BranchNZ <= 1'b0;
       IDEX_MemRead <= 1'b0;
       IDEX_MemWrite <= 1'b0;
       IDEX_MemToReg <= 1'b0;                  
       IDEX_RegWrite <= 1'b0;
       IDEX_PCplus4 <= 32'b0;
    end 
    else if (write_idex == 1'b1)
      begin
       IDEX_signExtend <= signExtend;
       IDEX_instr_rd <= instr_rd;
       IDEX_instr_rs1 <= instr_rs1;
       IDEX_instr_rs2 <= instr_rs2;
       IDEX_instr_shamt <= instr_shamt;
       IDEX_RegDst <= RegDst;
       IDEX_ALUcntrl <= ALUcntrl;
       IDEX_ALUSrc <= ALUSrc;
       IDEX_BranchZ <= BranchZ;
       IDEX_BranchNZ <= BranchNZ;
       IDEX_MemRead <= MemRead;
       IDEX_MemWrite <= MemWrite;
       IDEX_MemToReg <= MemToReg;                  
       IDEX_RegWrite <= RegWrite;
       IDEX_PCplus4 <= IFID_PCplus4;
    end
  end

// Main Control Unit 
control_main control_main (RegDst,
                  BranchZ,
                  BranchNZ,
                  MemRead,
                  MemWrite,
                  MemToReg,
                  ALUSrc,
                  RegWrite,
                  Jump, 
                  ALUcntrl,
                  opcode);

// Control Unit that generates stalls and bubbles to pipeline stages
control_stall_id control_stall_id(bubble_ifid, bubble_idex, bubble_exmem, bubble_memwb, 
                          write_ifid, write_idex, write_exmem, write_memwb, write_pc, 
                          instr_rs1,  instr_rs2, IDEX_instr_rs2, IDEX_MemRead, Jump, PCSrc);

/************************ Execution Unit (EX)  ***********************************/
assign bypassOutB = (bypassB==2'b00) ? IDEX_rdB : 
                    ((bypassB==2'b01) ? wRegData : 
                    EXMEM_ALUOut);
                 
assign ALUInA = (bypassA==2'b00) ? IDEX_rdA : 
                ((bypassA==2'b01) ? wRegData : 
                 EXMEM_ALUOut);
                 
assign ALUInB = (IDEX_ALUSrc == 1'b0) ? bypassOutB : IDEX_signExtend;


// Branch ALU
ALU  #32 branch_alu(BranchALUOut, , IDEX_PCplus4, IDEX_signExtend<<2, ,4'b0010);

//  ALU
ALU  #32 cpu_alu(ALUOut, Zero, ALUInA, ALUInB, IDEX_instr_shamt, ALUOp);

assign RegWriteAddr = (IDEX_RegDst==1'b0) ? IDEX_instr_rs2 : IDEX_instr_rd;

 // EXMEM pipeline register
 always @(posedge clock or negedge reset)
  begin 
    if ((reset == 1'b0) || (bubble_exmem == 1'b1))       
      begin
       EXMEM_ALUOut <= 32'b0;    
       EXMEM_BranchALUOut <= 32'b0;
       EXMEM_RegWriteAddr <= 5'b0;
       EXMEM_MemWriteData <= 32'b0;
       EXMEM_Zero <= 1'b0;
       EXMEM_BranchZ <= 1'b0;
       EXMEM_BranchNZ <= 1'b0;
       EXMEM_MemRead <= 1'b0;
       EXMEM_MemWrite <= 1'b0;
       EXMEM_MemToReg <= 1'b0;                  
       EXMEM_RegWrite <= 1'b0;
      end 
    else if (write_exmem == 1'b1)
      begin
       EXMEM_ALUOut <= ALUOut;    
       EXMEM_BranchALUOut <= BranchALUOut;
       EXMEM_RegWriteAddr <= RegWriteAddr;
       EXMEM_MemWriteData <= bypassOutB;
       EXMEM_Zero <= Zero;
       EXMEM_BranchZ <= IDEX_BranchZ;
       EXMEM_BranchNZ <= IDEX_BranchNZ;
       EXMEM_MemRead <= IDEX_MemRead;
       EXMEM_MemWrite <= IDEX_MemWrite;
       EXMEM_MemToReg <= IDEX_MemToReg;                  
       EXMEM_RegWrite <= IDEX_RegWrite;
      end
  end

   // ALU control
  control_alu control_alu(ALUOp, IDEX_ALUcntrl, IDEX_signExtend[5:0]);

  // Bypass control
  control_bypass_ex control_bypass_ex(bypassA, bypassB, 
                              IDEX_instr_rs1, IDEX_instr_rs2, 
                              EXMEM_RegWriteAddr, MEMWB_RegWriteAddr,
                              EXMEM_RegWrite, MEMWB_RegWrite);


      
/*********************************** Memory Unit (MEM)  ********************************************/  

assign PCSrc = (EXMEM_Zero & EXMEM_BranchZ) | (~EXMEM_Zero & EXMEM_BranchNZ);
 
// Data memory 1KB
Memory cpu_DMem(clock, reset, EXMEM_MemRead, EXMEM_MemWrite, EXMEM_ALUOut, EXMEM_MemWriteData, DMemOut);

// MEMWB pipeline register
 always @(posedge clock or negedge reset)
  begin 
    if ((reset == 1'b0) || (bubble_memwb == 1'b1))       
      begin
       MEMWB_DMemOut <= 32'b0;    
       MEMWB_ALUOut <= 32'b0;
       MEMWB_RegWriteAddr <= 5'b0;
       MEMWB_MemToReg <= 1'b0;                  
       MEMWB_RegWrite <= 1'b0;
      end 
    else if (write_memwb == 1'b1)
      begin
       MEMWB_DMemOut <= DMemOut;
       MEMWB_ALUOut <= EXMEM_ALUOut;
       MEMWB_RegWriteAddr <= EXMEM_RegWriteAddr;
       MEMWB_MemToReg <= EXMEM_MemToReg;                  
       MEMWB_RegWrite <= EXMEM_RegWrite;
      end
  end

/**************************** WriteBack Unit (WB) **************************/  
assign wRegData = (MEMWB_MemToReg == 1'b0) ? MEMWB_ALUOut : MEMWB_DMemOut;


endmodule
