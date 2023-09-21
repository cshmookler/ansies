// Standard includes
#include <iostream>

// Package includes
#include <ansies/ansies.hpp>
#include <ansies/version.hpp>

int main() {
  ansies::Sequencer es;

  std::cout << es.bold << es.green_fg
            << "\nIf this text is green, then the test succeeded!" << es.reset
            << "\n";
}