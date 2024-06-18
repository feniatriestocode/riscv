/*IMPLEMENTATION OF A PARAMETRIZED INSTRUCTION CACHE ON RISC-V*/

/*Asyc Read: rst=1, en=1, memWen=0, blockAddr=[TAG,INDEX], dataIn=don't care*/
/*Syc Write: rst=1, en=1, memWen=1, blockAddr=[TAG,INDEX], dataIn=don't care
  Write in memory in the next cycle from the write signals' arrival*/

`timescale 1ns/1ps
`include "constants.vh"

module Icache_SRAM(clk, rst, en, memWen, blockAddr, dataIn, hit, dataOut);
    //input ports//
    input clk, rst;
    input en, memWen; 
    input [`IBLOCK_SIZE_BITS-1:0] dataIn;
    input [`IMEM_BLOCK_ADDR_SIZE-1:0] blockAddr;
    //output ports//
    output wire hit;
    output reg [`IBLOCK_SIZE_BITS-1:0] dataOut;

    //SRAM'S columns declaration
    reg [`ICACHE_ASSOCIATIVITY-1:0]   valid_col  [`ICACHE_SIZE_SETS-1:0];
    reg [`ICACHE_ASSOCIATIVITY-1:0]   status_col [`ICACHE_SIZE_SETS-1:0]; 

    reg [`ITAG_SIZE-1:0]        tag_col    [`ICACHE_SIZE_SETS-1:0][`ICACHE_ASSOCIATIVITY-1:0];
    reg [`IBLOCK_SIZE_BITS-1:0] data_col   [`ICACHE_SIZE_SETS-1:0][`ICACHE_ASSOCIATIVITY-1:0];

    //blockAddr = [tag][index]
    wire [`ISET_INDEX_SIZE-1:0] index;
    wire [`ITAG_SIZE-1:0] tag;
    
    assign index = blockAddr[`ISET_INDEX_SIZE-1:0];
    assign tag   = blockAddr[`ITAG_SIZE+`ISET_INDEX_SIZE-1:`ISET_INDEX_SIZE]; 

    integer m,k;

    //*******************************ASYNCHRONOUS HIT/READ DATA*******************************//
    reg [`ICACHE_ASSOCIATIVITY-1:0] hitReg;
    
    always @(rst or en or index or tag)begin
        //default values
        dataOut = {`IBLOCK_SIZE_BITS{1'b0}};
        hitReg = {`ICACHE_ASSOCIATIVITY{1'b0}};

        //check all blocks in the expected set to find a possible hit
        if(rst && en)begin
            for(m=0;m<`ICACHE_ASSOCIATIVITY; m=m+1)begin
                hitReg[m] = (tag_col[index][m] == tag) && valid_col[index][m];

                //in case of a hit read the data
                if(hitReg[m])begin
                    dataOut = data_col[index][m];
                end
            end
        end
    end

    //if any of the blocks is a hit output the result
    assign hit = |hitReg;

    //*******************************ASYCHRONOUS PLRU IMPLEMENTANTION*******************************//

    reg found;
    reg [`ICACHE_ASSOCIATIVITY-1:0] blockToEvict;
    reg [`ICACHE_ASSOCIATIVITY-1:0] statusCol;

    always @(rst or en or index)begin
        // default values
        found = 1'b0;
        blockToEvict = {`ICACHE_ASSOCIATIVITY{1'b0}};
        statusCol = {`ICACHE_ASSOCIATIVITY{1'b0}};
        
        if(rst && en)begin
            for(m=0; m<`ICACHE_ASSOCIATIVITY; m=m+1)begin
                // PLRU should access the first block with status=0 or the first invalid one
                if((valid_col[index][m] == 1'b0 || status_col[index][m] == 1'b0) && found==1'b0)begin
                    found = 1'b1;
                    blockToEvict[m] = 1'b1;
                    // keeping the status col in regs to test it later
                    statusCol[m] = 1'b1;
                end else begin
                    statusCol[m] = status_col[index][m];
                end
            end
        end
    end

    //*******************************SYNCHRONOUS WRITE DATA*******************************//
   
    
    
    always @(posedge clk or negedge rst)begin
        // rst the cache
        if(!rst)begin
            for(m=0; m<`ICACHE_SIZE_SETS; m=m+1)begin
                valid_col [m] <= {`ICACHE_ASSOCIATIVITY{1'b0}}; 
                status_col[m] <= {`ICACHE_ASSOCIATIVITY{1'b0}};  
                for(k=0; k<`ICACHE_ASSOCIATIVITY; k=k+1)begin
                   tag_col [m][k] <= 1'b0;  
                   data_col[m][k] <= 1'b0;
                end
            end
        end
        else begin
            if(en)begin //cache enabled
                if(hit)begin //block hit
                    for(m=0; m<`ICACHE_ASSOCIATIVITY; m=m+1)begin
                        if(hitReg[m])begin 
                            data_col  [index][m] <= dataIn;
                            status_col[index][m]  <= 1'b1; //last accessed: status=1
                                
                            //check if all sets have status 1
                            if(&statusCol)begin
                                for(k=0; k<`ICACHE_ASSOCIATIVITY; k=k+1)
                                    if(k != m)
                                        status_col[index][k] <= 1'b0;
                                end
                        end
                    end
                end 
                //write cache block from the main memory
                else if(memWen)begin 
                    for(m=0; m<`ICACHE_ASSOCIATIVITY; m=m+1)
                        //evicting block
                        if(blockToEvict[m])begin
                            valid_col [index][m] <= 1'b1; 
                            status_col[index][m] <= 1'b1;
                            tag_col   [index][m] <= tag; 
                            data_col  [index][m] <= dataIn;

                            //check if all sets have status 1
                            if(&statusCol)
                                for(k=0; k<`ICACHE_ASSOCIATIVITY; k=k+1)
                                    if(k != m)
                                        status_col[index][k] <= 1'b0;

                        end             
                end //end of memWen if
            end //end of EN if
        end //end of rst==1 if
    end //end of always

endmodule