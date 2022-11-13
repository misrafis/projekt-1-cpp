#include <iostream>
#include <cstdlib>
#include <vector>

// Funkcja generująca losową macierz 2-wymiarową z podanymi w argumentach właściwościami [zakres liczb, liczba wierszy, liczba kolumn].
std::vector<std::vector<int>> getRandom2DVector(int range, int rows, int columns) {
    std::vector<std::vector<int>> random2DVector;
    srand((unsigned) time(NULL));
    for (unsigned int i = 0; i < rows; i++) {
        std::vector<int> temp;
        for (unsigned int j = 0; j < columns; j++) {
            int random_number = 1 + rand() % range;
            temp.push_back(random_number);
        }
        random2DVector.push_back(temp);
    }
    return random2DVector;
}

// Funkcja wypisująca elementy tablicy 2-wymiarowej.
void print2DVector(const std::vector<std::vector<int>> &vector) {
    for (const auto &row : vector) {
        for (const auto &item: row) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

// Funkcja wypisująca klucze i wartości mapy.
void printMap(const std::map<int, bool> &map) {
    for (auto const& [key, value] : map) {
        std::cout << " " << key << ": " << value << "\n";
    }
}
