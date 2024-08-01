#include <iostream>
#include "Functions.cpp"
#include "FIFO.cpp"


int main() {
// Проверка на четность

    int intNumber;
    std::cout << "Enter an integer value:   ";
    std::cin >> intNumber;

    if (isEven(intNumber)) {
        std::cout << "Number  " << intNumber << "  is even." << std::endl;
    }
    else {
        std::cout << "Number  " << intNumber << "  is odd." << std::endl;
    }
// Работа с буферами
 
// Создание объектов циклических буферов
    const size_t bufferSize = 6;
    CBVector bufferVector(bufferSize);
    CBArray bufferArray(bufferSize);

    // Добавление и извлечение элементов
    try {
        // Добавление элементов
        for (int i = 1; i <= bufferSize; ++i) {
            bufferVector.push(i);
            bufferArray.push(i * 10);
        }

        // Извлечение и вывод элементов
        std::cout << " Vector:" << std::ebdl;
        while (!bufferVector.isEmpty()) {
            std::cout << bufferVector.pop() << std::endl;
        }
        std::cout << " Array:" << std::endl;
        while (!bufferArray.isEmpty()) {
            std::cout << bufferArray.pop() << std::endl;
        }
        // Проверка свойств
        std::cout << "Vector is empty: " << (bufferVector.isEmpty() ? "true" : "false") << std::endl;
        std::cout << "Array is full: " << (bufferArray.isFull() ? "true" : "false") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }	
	
// Сортировка
    int A_size;
    std::cout << "Enter a size of array  :   ";
    std::cin >> A_size;
    std::vector<int> array(A_size);
    std::cout << "Enter an integer array :   ";

    std::copy_n(std::istream_iterator<int>(std::cin), A_size, array.begin());



    QuickSort(array, 0, A_size - 1); // вызываем функцию сортировки

    std::cout << "Sorted array: ";
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}