// Standard includes
#include <iostream>

// Package includes
#include <ansies/ansies.hpp>
#include <ansies/version.hpp>

int main() {
  ansies::enable();

  std::cout << ansies::bold << ansies::green_fg
            << "\nIf this text is green, then the test succeeded!"
            << ansies::reset << "\n";

  ansies::disable();
}