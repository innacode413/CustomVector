#pragma once

#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Vector {
public:
    Vector();
    Vector(int sizeOffArray);
    Vector(const Vector& other);
    ~Vector();

    Vector& operator=(const Vector& other);

    void resize(int newSize);
    void push_back(const T& value);
    void reserve(std::size_t newCapacity);

    void set(int index, const T& newValue);
    T get(int index) const;
    int getSize() const;
    std::size_t getCapacity() const;

    T& operator[](int index);
    const T& operator[](int index) const;

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    explicit operator bool() const;

    friend std::ostream& operator<<(std::ostream& out, const Vector& vector) {
        out << "[";
        for (int i = 0; i < vector.size; ++i) {
            out << vector.dynamicArray[i];
            if (i != vector.size - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Vector& vector) {
        T value;
        in >> value;
        vector.push_back(value);
        return in;
    }

private:
    void grow();

    int size;
    std::size_t capacity;
    T* dynamicArray;
};
