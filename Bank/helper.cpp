#include "helper.h"

#include <iostream>
#include <limits>

void correct(int &checkNumber) {
  while (true) {
    std::cout << "Please enter a valid number: ";
    if (std::cin >> checkNumber) {
      break;
    } else if (std::cin.eof()) {
      std::cout << "End of input detected. Exiting...\n";
      exit(EXIT_FAILURE);
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}
