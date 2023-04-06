CC = iverilog
FLAGS = -Wall -Winfloop
EXE = lab7b.out
SRCS = control.v library.v cpu.v testbench.v

all:
	$(CC) $(FLAGS) -o $(EXE) $(SRCS)
	vvp $(EXE)
	gtkwave tb_dumpfile.vcd waveform.gtkw

clean:
	rm -rf $(EXE)
