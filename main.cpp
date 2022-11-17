#include <iostream>
#include <vector>
#include <map>
#include <chrono>

#include "examples.h"
#include "tests.cpp"

/*
 * Sprawdź, które elementy tablicy dwuwymiarowej występują w każdym wierszu tej tablicy.
 */

// Prosta funkcja wyszukiwania liniowego zwracająca prawda/fałsz.
bool linearSearch(int key, const std::vector<int> &vector){
    for (const auto &item : vector){
        if (item == key) {
            return true;
        }
    }
    return false;
}

// Funkcja zwracająca tablicę kluczy z mapy.
std::vector<int> transformMapKeysToVector(const std::map<int, bool> &map) {
    std::vector<int> vector;
    for (auto const& [key, value] : map) {
        if (value) {
            vector.push_back(key);
        }
    }
    return vector;
}

// Funkcja wypisująca elementy tablicy.
void printVector(const std::vector<int> &vector) {
    std::cout << "Powtarzajace sie liczby: ";
    for (const auto &item : vector) {
        std::cout << item << " ";
    }
    std:: cout << std::endl << std::endl;
}

// Funkcja zwracająca tablicę ze wspólnymi elementami wszystkich wierszy.
std::vector<int> getCommonElements(std::vector<std::vector<int>> vector) { // Jako argument przyjmujemy tablicę dwuwymiarową.
    auto start = std::chrono::high_resolution_clock::now(); // Timestamp do obliczenia czasu wykonywania funkcji.
    std::map<int, bool> appearanceToElement; // Deklaracja mapy przechowującej klucze[elementy tablicy] i wartości[prawda/fałsz].
    std::vector<int> commonElements; // Deklaracja tablicy, która będzie zwracana.
    for(const auto &item : vector[0]) { // Pętla for iterująca po każdym elemencie w pierwszej tablicy.
        for(unsigned int i = 0; i <= (int)vector.size() - 1; i++) { // Pętla for iterująca po każdej tablicy.
            if (linearSearch(item, vector[i])) { // Jeśli element występuje w i-tej tablicy.
                appearanceToElement[item] = true; // Ustaw jego wartość w mapie na prawdę.
            } else { // Jeśli element nie występuje w i-tej tablicy.
                appearanceToElement[item] = false; // Ustaw jego wartość w mapie na fałsz.
                break; // Przerwij pętlę.
            }
        }
    }
    commonElements = transformMapKeysToVector(appearanceToElement); // Zamiana kluczy[elementów wspólnych wszystkich tablic] mapy na tablicę do zwrócenia.

    auto stop = std::chrono::high_resolution_clock::now(); // Timestamp do obliczenia czasu wykonywania funkcji.
    auto duration = duration_cast<std::chrono::microseconds>(stop - start); // Obliczenie czasu wykonywania funkcji w ms.
    std::cout << "Czas wykonania: " << duration.count() << "us" << std::endl;

    return commonElements; // Zwrócenie wyniku.
}

int main() {
    printVector(getCommonElements(example1));
    printVector(getCommonElements(example2));
    printVector(getCommonElements(example3));
    printVector(getCommonElements(example4));
    printVector(getCommonElements(example5));
    printVector(getCommonElements(example6));
    printVector(getCommonElements(getRandom2DVector(300, 120, 100)));
    return 0;
}
