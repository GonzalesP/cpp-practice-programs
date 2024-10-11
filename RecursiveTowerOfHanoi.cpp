#include <iostream>

void TOH(int numDisc, int startingTower, int unusedTower, int targetTower) {
  if (numDisc >= 1) {
    TOH(numDisc - 1, startingTower, targetTower, unusedTower);
    std::cout << startingTower << " to " << targetTower << std::endl;
    TOH(numDisc - 1, unusedTower, startingTower, targetTower);
  }
}

int main() {
  int numDiscs = 3;
  std::cout << "Choose a number of starting discs: ";
  std::cin >> numDiscs;

  TOH(numDiscs, 1, 2, 3);
  return 0;
}