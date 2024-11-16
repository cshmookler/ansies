// Standard includes
#include <iostream>

// Package includes
#include <ansies/version.hpp>

int main() {
    std::cout << "\nCompiletime Version: \t"
              << esc::compiletime_version << "\nRuntime Version: \t"
              << esc::get_runtime_version()
              << "\n\nThe test succeeded!\n";
}