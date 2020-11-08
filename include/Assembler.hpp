//
// Created by vadim on 07.11.20.
//

#ifndef PDP_11_ASSEMBLER_HPP
#define PDP_11_ASSEMBLER_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

typedef int8_t mem_t;

enum MEMORY{
    PAGE_SIZE = 2 << 10,
    PAGE_NUM  = 2 << 10,
    MEM_SIZE  = PAGE_SIZE * PAGE_NUM
};

namespace pdp{
    class Assembler{
    public:
        Assembler();
        ~Assembler();
        // Assembler(const std::string& filename);
        ssize_t GetLengthOfFile(std::ifstream& file);
        ssize_t ReadFile();
        void ParseRom();
        void FillPtrArr();
        void Init(const std::string& filename);
        void PrintPtrArr();
    private:
        mem_t*      rom_;
        mem_t**     ptr_arr_;
        std::string rom_file_name_;
        ssize_t     code_length_;
        ssize_t     line_num_;
    };
}

#endif //PDP_11_ASSEMBLER_HPP
