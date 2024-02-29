#include <iostream>
#include <vector>

template<typename T>
void bubbleSort(T rand_array[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (rand_array[j] > rand_array[j + 1]) {
                T t = rand_array[j];
                rand_array[j] = rand_array[j + 1];
                rand_array[j + 1] = t;
            }
        }
    }
}

template<typename T>
void printRand_array(T rand_array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "  " << rand_array[i];
    }
    std::cout << "\n";
}

int main() {
    int size;
    std::cout << "Enter number of elements: ";
    std::cin >> size;

    std::vector<double> rand_array(size);

    
    for (int i = 0; i < size; ++i) {
        rand_array[i] = rand() % 10000 + 1;;
    }

    std::cout << "Array elements:\n";
    printRand_array(rand_array.data(), size);

    bubbleSort(rand_array.data(), size);

    std::cout << "Sorted array:\n";
    printRand_array(rand_array.data(), size);

    return 0;
}