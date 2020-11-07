//
// Created by vadim on 07.11.20.
//

#ifndef PDP_11_ASSEMBLER_HPP
#define PDP_11_ASSEMBLER_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

typedef int8_t mem_type;

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
        Assembler(const std::string& filename);
        void ReadFile(const std::string& filename);

    private:
        mem_type*   rom_;
        std::string rom_file_name_;
    };
}

#endif //PDP_11_ASSEMBLER_HPP
