#include <vector>

// Przykładowe macierze 2-wymiarowe.
// Jedna liczba się powtarza : 5.
std::vector<std::vector<int>> example1 = {
        {2, 4, 3, 8, 5},
        {4, 7, 1, 3, 5},
        {3, 5, 2, 1, 5},
        {4, 5, 0, 2, 5}
};

// Dwie lub więcej liczb się powtarza: 2, 3.
std::vector<std::vector<int>> example2 = {
        {3, 2, 3, 3, 9},
        {4, 2, 1, 3, 6},
        {3, 2, 2, 1, 3},
        {4, 2, 0, 2, 3}
};

// Jedna liczba się powtarza: 3. Inny rozmiar tablicy.
std::vector<std::vector<int>> example3 = {
        {1, 2, 3},
        {1, 5, 3},
        {7, 1, 3},
        {1, 3, 13},
        {3, 15, 1},
        {17, 1, 3},
        {3, 3, 22}
};

// Żadna liczba się nie powtarza.
std::vector<std::vector<int>> example4 = {
        {7, 2, 8, 2, 9},
        {4, 2, 1, 3, 6},
        {3, 0, 5, 1, 3},
        {4, 5, 0, 2, 3}
};

// W tablicy jest tylko jeden wiersz => wszystkie liczby się powtarzają.
std::vector<std::vector<int>> example5 = {{7, 2, 8, 9}};

// Pusta tablica => żadna liczba się nie powtarza.
std::vector<std::vector<int>> example6 = {{}};