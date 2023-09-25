// Standard includes
#include <array>
#include <iostream>

// Package includes
#include <ansies/ansies.hpp>
#include <ansies/version.hpp>

int main() {
    ansies::Sequencer esc; // escape sequencer

    std::cout << esc.bold << esc.yellow_fg << "\nCompiletime Version: \t"
              << ansies::compiletime_version << "\nRuntime Version: \t"
              << ansies::get_runtime_version() << esc.green_fg
              << "\n\nIf this text is green, then the test succeeded!"
              << esc.reset << '\n';
}
