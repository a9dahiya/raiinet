#include <iostream>
#include "asciiart.h"
#include "blank.h"
#include "studio.h"

int main () {
  AsciiArt *canvas = new Blank;

  Studio s{canvas};

  std::string command;

  while (std::cin >> command) {
    if (command == "render" ) {
      s.render();
    }
    else if (command == "animate") {
      int n;
      std::cin >> n;
      s.animate(n);
    }
    else if (command == "reset") {
      s.reset();
    }
    else if (command == "filledbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;

    }
    else if (command == "blinkingbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;

    }
    else if (command == "movingbox") {
      int top, bottom, left, right;
      char what, dir;
      std::cin >> top >> bottom >> left >> right >> what >> dir;

    }
    else if (command == "maskbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;

    }
  }
}
