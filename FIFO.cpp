#include <iostream>
#include <stdexcept>
#include <vector>

//Циклический буфер на основе std::vector

class CBVector {
private:
    std::vector<int> buffer; // Вектор для хранения
    size_t head;             // Индекс начала
    size_t tail;             // Индекс конца
    size_t maxSize;
    size_t currentSize;

public: // Инициализация

    CBVector(size_t size)
        : buffer(size), head(0), tail(0), maxSize(size), currentSize(0) {}
    // Добавление элемента
    void push(int value) {
        if (currentSize == maxSize) {
            throw std::overflow_error("Buffer is full");
        }
        buffer[tail] = value;
        tail = (tail + 1) % maxSize;
        ++currentSize;
    }
    // Извлечение элемента
    int pop() {
        if (currentSize == 0) {
            throw std::underflow_error("Buffer is empty");
        }
        int value = buffer[head];
        head = (head + 1) % maxSize;
        --currentSize;
        return value;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    bool isFull() const {
        return currentSize == maxSize;
    }
};

//Циклический буфер на основе массива

class CBArray {
private:
    int* buffer; // Указатель на массив хранения
    size_t head; // Индекс начала
    size_t tail; // Индекс конца
    size_t maxSize;
    size_t currentSize;

public: // Инициализация
    CBArray(size_t size)
        : maxSize(size), head(0), tail(0), currentSize(0) {
        buffer = new int[maxSize];
    }
    // Освобождение памяти
    ~CBArray() {
        delete[] buffer;
    }
    // Добавление элемента
    void push(int value) {
        if (currentSize == maxSize) {
            throw std::overflow_error("Buffer is full");
        }
        buffer[tail] = value;
        tail = (tail + 1) % maxSize;
        ++currentSize;
    }
    // Извлечение элемента
    int pop() {
        if (currentSize == 0) {
            throw std::underflow_error("Buffer is empty");
        }
        int value = buffer[head];
        head = (head + 1) % maxSize;
        --currentSize;
        return value;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    bool isFull() const {
        return currentSize == maxSize;
    }
};


