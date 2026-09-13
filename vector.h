#pragma once

#include <iostream>
#include <iterator>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Vector {
public:
    class Iterator {
    private:
        T* ptr_;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(T* ptr = nullptr)
            : ptr_(ptr) {
        }

        reference operator*() const {
            return *ptr_;
        }

        pointer operator->() const {
            return ptr_;
        }

        Iterator& operator++() {
            ++ptr_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++ptr_;
            return temp;
        }

        Iterator& operator--() {
            --ptr_;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            --ptr_;
            return temp;
        }

        Iterator& operator+=(difference_type n) {
            ptr_ += n;
            return *this;
        }

        Iterator& operator-=(difference_type n) {
            ptr_ -= n;
            return *this;
        }

        Iterator operator+(difference_type n) const {
            return Iterator(ptr_ + n);
        }

        Iterator operator-(difference_type n) const {
            return Iterator(ptr_ - n);
        }

        difference_type operator-(const Iterator& other) const {
            return ptr_ - other.ptr_;
        }

        reference operator[](difference_type n) const {
            return ptr_[n];
        }

        bool operator==(const Iterator& other) const {
            return ptr_ == other.ptr_;
        }

        bool operator!=(const Iterator& other) const {
            return ptr_ != other.ptr_;
        }

        bool operator<(const Iterator& other) const {
            return ptr_ < other.ptr_;
        }

        bool operator>(const Iterator& other) const {
            return ptr_ > other.ptr_;
        }

        bool operator<=(const Iterator& other) const {
            return ptr_ <= other.ptr_;
        }

        bool operator>=(const Iterator& other) const {
            return ptr_ >= other.ptr_;
        }
    };

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

    Iterator begin();
    Iterator end();
    const Iterator begin() const;
    const Iterator end() const;

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