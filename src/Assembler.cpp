//
// Created by vadim on 07.11.20.
//

#include "Assembler.hpp"

namespace pdp{
    Assembler::Assembler():
            rom_(nullptr),
            rom_file_name_()
    {}

    Assembler::Assembler(const std::string& filename):
        rom_file_name_(filename)
    {
        rom_ = new mem_type[MEM_SIZE];
        ReadFile(filename);
    }

    Assembler::~Assembler() {
        delete[] rom_;
    }


    void Assembler::ReadFile(const std::string& filename){
        std::ifstream rom_file;
        rom_file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try {
            rom_file.open(filename);
            std::cout << "I'm here!\n";

            // get length of file:
            rom_file.seekg (0, rom_file.end);
            long length = rom_file.tellg();
            rom_file.seekg (0, rom_file.beg);

            std::cout << "Reading " << length << " characters... ";
            // read data as a block:
            rom_file.read ((char*)rom_, length);

            if (rom_file)
                std::cout << "all characters read successfully.\n";
            else
                std::cout << "error: only " << rom_file.gcount() << " could be read\n";

            std::cout << "Rom file contents: " << rom_ << std::endl;

            rom_file.close();
        }
        catch (std::ifstream::failure& e) {
            std::cerr << "Exception opening/reading/closing file\n";
        }
    }
}
