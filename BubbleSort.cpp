#include <iostream>
#include <vector>

template<typename T>
void bubbleSort(T massiv[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (massiv[j] > massiv[j + 1]) {
                T t = massiv[j];
                massiv[j] = massiv[j + 1];
                massiv[j + 1] = t;
            }
        }
    }
}

template<typename T>
void printMassiv(T massiv[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "  " << massiv[i];
    }
    std::cout << std::endl;
}

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::vector<double> massiv(size);

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        std::cin >> massiv[i];
    }

    bubbleSort(massiv.data(), size);

    std::cout << "Отсортированный массив:\n";
    printMassiv(massiv.data(), size);

    return 0;
}