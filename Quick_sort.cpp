#include <iostream>
#include <vector>
#include <random>

template <typename T>
int partition(std::vector<T>& rand_array, int low, int high) {
    T pivot = rand_array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (rand_array[j] < pivot) {
            i++;
            std::swap(rand_array[i], rand_array[j]);
        }
    }

    std::swap(rand_array[i + 1], rand_array[high]);
    return i + 1;
}

template <typename T>
int randomPartition(std::vector<T>& rand_array, int low, int high) {
    srand(time(0));
    int random_index = low + rand() % (high - low);
    std::swap(rand_array[random_index], rand_array[high]);
    return partition(rand_array, low, high);
}

template <typename T>
void quickSort(std::vector<T>& rand_array, int low, int high) {
    if (low < high) {
        int pi = randomPartition(rand_array, low, high);

        quickSort(rand_array, low, pi - 1);
        quickSort(rand_array, pi + 1, high);
    }
}

template <typename T>
void printRand_array(const std::vector<T>& rand_array) {
    for (const T& element : rand_array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<double> rand_array(n);


    for (int i = 0; i < n; i++) {
        rand_array[i] = rand() % 10000 + 1;;
    }

    std::cout << "Array elements: ";
    printRand_array(rand_array);

    quickSort(rand_array, 0, rand_array.size() - 1);

    std::cout << "Sorted array: ";
    printRand_array(rand_array);

    return 0;
}