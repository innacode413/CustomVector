#include "vector.h"

template <typename T>
Vector<T>::Vector() {
    size = 0;
    dynamicArray = nullptr;
}

template <typename T>
Vector<T>::Vector(int sizeOffArray) {
    if (sizeOffArray <= 0) {
        size = 0;
        dynamicArray = nullptr;
    } else {
        size = sizeOffArray;
        dynamicArray = new T[size]{};
    }
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
    size = other.size;
    if (size > 0) {
        dynamicArray = new T[size];
        for (int i = 0; i < size; ++i) {
            dynamicArray[i] = other.dynamicArray[i];
        }
    } else {
        dynamicArray = nullptr;
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] dynamicArray;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }

    delete[] dynamicArray;

    size = other.size;
    if (size > 0) {
        dynamicArray = new T[size];
        for (int i = 0; i < size; ++i) {
            dynamicArray[i] = other.dynamicArray[i];
        }
    } else {
        dynamicArray = nullptr;
    }

    return *this;
}

template <typename T>
void Vector<T>::resize(int newSize) {
    if (newSize <= 0) {
        size = 0;
        delete[] dynamicArray;
        dynamicArray = nullptr;
        return;
    }

    T* tempArray = new T[newSize]{};

    int elementsToCopy = (newSize < size) ? newSize : size;
    for (int i = 0; i < elementsToCopy; ++i) {
        tempArray[i] = dynamicArray[i];
    }

    delete[] dynamicArray;
    dynamicArray = tempArray;
    size = newSize;
}

template <typename T>
void Vector<T>::set(int index, const T& newValue) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Індекс поза межами масиву!");
    }
    dynamicArray[index] = newValue;
}

template <typename T>
T Vector<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Індекс поза межами масиву!");
    }
    return dynamicArray[index];
}

template <typename T>
int Vector<T>::getSize() const {
    return size;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Індекс поза межами масиву!");
    }
    return dynamicArray[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Індекс поза межами масиву!");
    }
    return dynamicArray[index];
}

template <typename T>
bool Vector<T>::operator==(const Vector& other) const {
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

template <typename T>
bool Vector<T>::operator!=(const Vector& other) const {
    return !(*this == other);
}

template <typename T>
Vector<T>::operator bool() const {
    return size > 0;
}

template class Vector<int>;
template class Vector<double>;
