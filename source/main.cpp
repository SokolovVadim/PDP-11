#include <iostream>
#include "Emulator.hpp"
#include "Assembler.hpp"

int main()
{
    std::cout << "Hello!\n";
    pdp::Assembler assembler{};
    assembler.Init("input.txt");
    assembler.ParseRom();
    assembler.FillPtrArr();
}