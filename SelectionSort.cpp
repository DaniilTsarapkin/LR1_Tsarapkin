#include <iostream>
#include <vector>

template <typename T>
void selectionSort(std::vector<T>& massiv, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
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
    int size;
    std::cout << "Введите размер массива:";
    std::cin >> size;

    std::vector<double> massiv(size);

    std::cout << "Введите элементы массива:";
    for (int i = 0; i < size; i++)
        std::cin >> massiv[i];

    selectionSort(massiv, size);

    std::cout << "Отсортированный массив:\n";
    printMassiv(massiv);

    return 0;
}