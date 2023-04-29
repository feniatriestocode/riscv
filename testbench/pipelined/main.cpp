// RISC-V SiMPLE SV -- testbench
// BSD 3-Clause License
// (c) 2019, Marek Materzok, University of Wrocław

#include "Vtoplevel.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>

double sc_time_stamp() {return 0;}

int main(int argc, const char **argv, const char **env)
{
    Verilated::commandArgs(argc, argv);

    bool verbose = true;
    const char *str;
    str = Verilated::commandArgsPlusMatch("verbose");
    if (str && str[0]) verbose = true;

    std::unique_ptr<Vtoplevel> top(new Vtoplevel);

    top->reset = 0;

    for (int time = 0; time < 100000; time++) {
        if (time > 9)
            top->reset = 0;
        else if (time > 4)
            top->reset = 1;
        top->clock = time & 1;
        top->eval();


        /*
        if (verbose && top->clock && time > 8) {
            std::cout << std::hex << std::setfill('0')
                      << "pc=" << std::setw(8) << top->pc << " "
                      << "inst=" << std::setw(8) << top->inst << " "
                      << "addr=" << std::setw(8) << top->bus_address << " "
                      << "in=" << std::setw(8) << top->bus_read_data << " "
                      << (top->bus_read_enable ? "1" : "0") << " "
                      << "out=" << std::setw(8) << top->bus_write_data << " "
                      << (top->bus_write_enable ? "1" : "0") << " " 
                      << "fmt=" << (int)top->bus_byte_enable << std::endl;
        }
        */

	std:: cout << top->MemAddr << std::endl;
        if (top->MemWriteEnable && top->MemAddr == 0xfffffff0) {
            if (top->WriteData) {
                std::cout << "PASS" << std::endl;
                return 0;
            } else {
                std::cout << "FAIL" << std::endl;
                return -1;
            }
        }
    }

    std::cout << "TIMEOUT" << std::endl;

    return -1;
}
