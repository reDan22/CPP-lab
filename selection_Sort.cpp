#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
void selectionSort(std::vector<T>& massiv, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (massiv[j] < massiv[min])
                min = j;
        }
        if (min != i)
            std::swap(massiv[i], massiv[min]);
    }
}

template <typename T>
void printMassiv(const std::vector<T>& massiv) {
    for (const T& element : massiv) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter massiv size:";
    std::cin >> n;

    std::vector<double> massiv(n);

    std::cout << "Massiv elements:";
    for (int i = 0; i < n; i++)
        massiv[i] = rand() % 10000 + 1;

    std::cout << "Massiv:";
    printMassiv(massiv);

    selectionSort(massiv, n);

    std::cout << "Sorted massiv: ";
    printMassiv(massiv);

    return 0;
}
