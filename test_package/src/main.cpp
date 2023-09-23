// Standard includes
#include <iostream>

// Package includes
#include <ansies/ansies.hpp>
#include <ansies/version.hpp>

int main() {
    ansies::Sequencer esr; // Escape SequenceR

    std::cout << esr.bold << esr.green_fg
              << "\nIf this text is green, then the test succeeded!"
              << esr.reset << "\n";
}
