#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<std::vector<int>> getRandom2DVector(int range, int rows, int columns) {
    std::vector<std::vector<int>> random2DVector;
    srand((unsigned) time(NULL));
    for (unsigned int i = 0; i < rows; i++) {
        std::vector<int> temp;
        for (unsigned int j = 0; j < columns; j++) {
            int random_number = 1 + rand() % range;;
            temp.push_back(random_number);
        }
        random2DVector.push_back(temp);
    }
    return random2DVector;
}