#include "vector.h"

template <typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 0;
    dynamicArray = nullptr;
}

template <typename T>
Vector<T>::Vector(int sizeOffArray) {
    if (sizeOffArray <= 0) {
        size = 0;
        capacity = 0;
        dynamicArray = nullptr;
    } else {
        size = sizeOffArray;
        capacity = static_cast<std::size_t>(sizeOffArray);
        dynamicArray = new T[capacity]{};
    }
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
    size = other.size;
    capacity = other.capacity;
    if (capacity > 0) {
        dynamicArray = new T[capacity];
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
    capacity = other.capacity;
    if (capacity > 0) {
        dynamicArray = new T[capacity];
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
        capacity = 0;
        return;
    }

    if (static_cast<std::size_t>(newSize) > capacity) {
        std::size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        if (newCapacity < static_cast<std::size_t>(newSize)) {
            newCapacity = static_cast<std::size_t>(newSize);
        }

        T* newData = new T[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = dynamicArray[i];
        }

        delete[] dynamicArray;
        dynamicArray = newData;
        capacity = newCapacity;
    }

    size = newSize;
}

template <typename T>
void Vector<T>::grow() {
    std::size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[newCapacity];

    for (int i = 0; i < size; ++i) {
        newData[i] = dynamicArray[i];
    }

    delete[] dynamicArray;
    dynamicArray = newData;
    capacity = newCapacity;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (static_cast<std::size_t>(size) == capacity) {
        grow();
    }

    dynamicArray[size] = value;
    ++size;
}

template <typename T>
void Vector<T>::reserve(std::size_t newCapacity) {
    if (newCapacity <= capacity) {
        return;
    }

    T* newData = new T[newCapacity];

    for (int i = 0; i < size; ++i) {
        newData[i] = dynamicArray[i];
    }

    delete[] dynamicArray;
    dynamicArray = newData;
    capacity = newCapacity;
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
std::size_t Vector<T>::getCapacity() const {
    return capacity;
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
