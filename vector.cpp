#include "vector.h"

vector::vector(int sizeOffArray) {
    if (sizeOffArray <= 0) {
        size = 0;
        dynamicArray = nullptr;
    } else {
        size = sizeOffArray;
        dynamicArray = new int[size]{};
    }
}

vector::vector(const vector& other) {
    size = other.size;
    if (size > 0) {
        dynamicArray = new int[size];
        for (int i = 0; i < size; ++i) {
            dynamicArray[i] = other.dynamicArray[i];
        }
    } else {
        dynamicArray = nullptr;
    }
}

vector::~vector() {
    delete[] dynamicArray;
}

vector& vector::operator=(const vector& other) {
    if (this == &other) {
        return *this;
    }

    delete[] dynamicArray;

    size = other.size;
    if (size > 0) {
        dynamicArray = new int[size];
        for (int i = 0; i < size; ++i) {
            dynamicArray[i] = other.dynamicArray[i];
        }
    } else {
        dynamicArray = nullptr;
    }

    return *this;
}

void vector::resize(int newSize) {
    if (newSize <= 0) {
        size = 0;
        delete[] dynamicArray;
        dynamicArray = nullptr;
        return;
    }

    int* tempArray = new int[newSize]{};

    int elementsToCopy = (newSize < size) ? newSize : size;
    for (int i = 0; i < elementsToCopy; ++i) {
        tempArray[i] = dynamicArray[i];
    }

    delete[] dynamicArray;
    dynamicArray = tempArray;
    size = newSize;
}

void vector::set(int index, int newValue) {
    if (index >= 0 && index < size) {
        dynamicArray[index] = newValue;
    }
}

int vector::get(int index) const {
    if (index >= 0 && index < size) {
        return dynamicArray[index];
    }
    return -1;
}

int vector::getSize() const {
    return size;
}

int& vector::operator[](int index) {
    return dynamicArray[index];
}

const int& vector::operator[](int index) const {
    return dynamicArray[index];
}

bool vector::operator==(const vector& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (dynamicArray[i] != other.dynamicArray[i]) {
            return false;
        }
    }
    return true;
}

bool vector::operator!=(const vector& other) const {
    return !(*this == other);
}
