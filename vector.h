#pragma once

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
    void set(int index, const T& newValue);
    T get(int index) const;
    int getSize() const;

    T& operator[](int index);
    const T& operator[](int index) const;

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    explicit operator bool() const;

private:
    int size;
    T* dynamicArray;
};
