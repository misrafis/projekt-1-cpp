#include <iostream>
#include <vector>
#include <map>
#include <chrono>

#include "examples.h"
#include "tests.cpp"

bool linearSearch(int key, std::vector<int> vector){
    for (int item : vector){
        if (item == key) {
            return true;
        }
    }
    return false;
}

void printMap(std::map<int, bool> map) {
    for (auto const& [key, value] : map) {
        std::cout << " " << key << ": " << value << "\n";
    }
}

void printVector(std::vector<int> vector) {
    for (int item : vector) {
        std::cout << item << " ";
    }
    std:: cout << std::endl;
}

void print2DVector(std::vector<std::vector<int>> vector) {
    for (const auto &row : vector) {
        for (const auto &item: row) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<int> transformMapKeysToVector(std::map<int, bool> map) {
    std::vector<int> vector;
    for (auto const& [key, value] : map) {
        if (value) {
            vector.push_back(key);
        }
    }
    return vector;
}

std::vector<int> getCommonElements(std::vector<std::vector<int>> vector) {
    std::map<int, bool> appearanceToElement;
    std::vector<int> commonElements;
    auto start = std::chrono::high_resolution_clock::now();

    for(int item : vector[0]) { // Pętla for iterująca po każdym elemencie w pierwszej tablicy
        for(unsigned int i = 0; i <= (int)vector.size() - 1; i++) { // Pętla for iterująca po każdej tablicy
            if (linearSearch(item, vector[i])) { // Jeśli element występuje w i-tej tablicy
                appearanceToElement[item] = true; // Ustaw jego wartość w mapie na prawdę
            } else { // Jeśli element nie występuje w i-tej tablicy
                appearanceToElement[item] = false; // Ustaw jego wartość w mapie na fałsz
                break; // Przerwij pętlę.
            }
        }
    }
    commonElements = transformMapKeysToVector(appearanceToElement); // Zamiana mapy na tablicę

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Elapsed time: " << duration.count() << "ms" << std::endl;

    return commonElements; // Zwrócenie wyniku
}

int main() {
    printVector(getCommonElements(example1) );
    printVector(getCommonElements(example2) );
    printVector(getCommonElements(example3) );
    printVector(getCommonElements(example4) );
    printVector(getCommonElements(example5) );
    printVector(getCommonElements(example6) );
    printVector(getCommonElements(getRandom2DVector(300, 120, 1000)) );
    return 0;
}
