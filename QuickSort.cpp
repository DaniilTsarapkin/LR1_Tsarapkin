#include <iostream>
#include <vector>
#include <random>

template <typename T>
int partition(std::vector<T>& massiv, int low, int high) {
    T pivot = massiv[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (massiv[j] < pivot) {
            i++;
            std::swap(massiv[i], massiv[j]);
        }
    }

    std::swap(massiv[i + 1], massiv[high]);
    return i + 1;
}

template <typename T>
int randomPartition(std::vector<T>& massiv, int low, int high) {
    srand(time(0));
    int random_index = low + rand() % (high - low);
    std::swap(massiv[random_index], massiv[high]);
    return partition(massiv, low, high);
}

template <typename T>
void quickSort(std::vector<T>& massiv, int low, int high) {
    if (low < high) {
        int piv = randomPartition(massiv, low, high);

        quickSort(massiv, low, piv - 1);
        quickSort(massiv, piv + 1, high);
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
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::vector<double> massiv(size);

    std::cout << "Введите элементы массива:";
    for (int i = 0; i < size; i++) {
        std::cin >> massiv[i];
    }

    quickSort(massiv, 0, massiv.size() - 1);

    std::cout << "Отсортированный массив:\n";
    printMassiv(massiv);

    return 0;
}