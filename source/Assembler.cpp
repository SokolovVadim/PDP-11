//
// Created by vadim on 07.11.20.
//

#include "Assembler.hpp"

namespace pdp{
    Assembler::Assembler():
            rom_(nullptr),
            ptr_arr_(nullptr),
            rom_file_name_(),
            code_length_(0),
            line_num_(0)
    {}

    Assembler::~Assembler() {
        delete[] rom_;
        delete[] ptr_arr_;
    }

    void Assembler::Init(const std::string& filename) {
        this->rom_file_name_ = filename;
        ssize_t length = ReadFile();
        this->code_length_ = length;
    }

    ssize_t Assembler::ReadFile(){
        std::ifstream rom_file{};
        rom_file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try {
            rom_file.open(rom_file_name_);
            ssize_t length = GetLengthOfFile(rom_file);

            rom_ = new mem_t[length];

            std::cout << "Reading " << length << " characters... ";
            // read data as a block:
            rom_file.read ((char*)rom_, length);

            if (rom_file)
                std::cout << "all characters read successfully.\n";
            else
                std::cout << "error: only " << rom_file.gcount() << " could be read\n";

            std::cout << "Rom file contents: " << rom_ << std::endl;

            rom_file.close();
            this->code_length_ = length;
            return length;
        }
        catch (std::ifstream::failure& e) {
            std::cerr << "Exception opening/reading/closing file\n";
        }
    }

    ssize_t Assembler::GetLengthOfFile(std::ifstream& file) {
        file.seekg (0, file.end);
        ssize_t length = file.tellg();
        file.seekg (0, file.beg);
        return length;
    }

    void Assembler::ParseRom() {
        assert(code_length_ <= MEM_SIZE);
        for(int i(0); i < code_length_; ++i)
        {
            if(rom_[i] == '\n')
            {
                rom_[i] = '\0';
                line_num_++;
            }
        }
        std::cout << "Line num: " << line_num_ << std::endl;
    }

    void Assembler::FillPtrArr() {
        ptr_arr_ = new mem_t*[line_num_];
        // the beginning of data
        ptr_arr_[0] = &rom_[0];
        int counter(1);
        for(int i(1); i < code_length_; ++i)
        {
            if(rom_[i] == '\0')
            {
                ptr_arr_[counter] = &rom_[i - 1];
                counter++;
            }
        }
        for(int i(0); i < line_num_; ++i)
        {
            printf("line[%d]: %p: %s\n", i, ptr_arr_[i], (char*)ptr_arr_[i]);
        }
    }

    void Assembler::PrintPtrArr() {
        for(int i(0); i < line_num_; ++i)
        {
            printf("line[%d]: %p: %s\n", i, ptr_arr_[i], (char*)ptr_arr_[i]);
        }
    }
}
