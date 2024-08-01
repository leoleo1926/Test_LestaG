#include <iostream>
#include <vector>
#include <algorithm> // для std::swap

// Функция проверки числа на четность
bool isEven(int value) {
    return (value & 1) == 0;
    // Используем побитовое И для сравнений двоичных представлений
    // Если результат равен 0, то младший бит числа = 0 (число четное)
}



// Функция разделения
int Divide(std::vector<int>& arr, int low, int high) {
    int base = arr[high]; // выбор последнего элемента в качестве опорного
    int i = low - 1;      // индекс меньшего элемента

    for (int j = low; j < high; j++) {
        if (arr[j] < base) {
            i++; 
            std::swap(arr[i], arr[j]); // перемещаем меньшие элементы влево
        }
    }
    std::swap(arr[i + 1], arr[high]); // помещаем опорный элемент на первое место справа от всех меньших элементов
    return i + 1;                     // возвращаем индекс опорного элемента
}

// Функция быстрой сортировки
void QuickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int Base_i = Divide(arr, low, high); // разделяем массив

        QuickSort(arr, low, Base_i - 1);     // сортируем элементы до опорного
        QuickSort(arr, Base_i + 1, high);    // сортируем элементы после опорного
    }
}


