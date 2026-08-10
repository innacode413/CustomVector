#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T, std::size_t N>
class StaticArray {
public:
    StaticArray() = default;
    StaticArray(const StaticArray& other) = default;
    StaticArray& operator=(const StaticArray& other) = default;
    ~StaticArray() = default;

    void set(std::size_t index, const T& newValue) {
        if (index >= N) {
            throw std::out_of_range("Індекс поза межами масиву!");
        }
        data_[index] = newValue;
    }

    T get(std::size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Індекс поза межами масиву!");
        }
        return data_[index];
    }

    std::size_t getSize() const {
        return N;
    }

    T& operator[](std::size_t index) {
        if (index >= N) {
            throw std::out_of_range("Індекс поза межами масиву!");
        }
        return data_[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Індекс поза межами масиву!");
        }
        return data_[index];
    }

    bool operator==(const StaticArray& other) const {
        for (std::size_t i = 0; i < N; ++i) {
            if (data_[i] != other.data_[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const StaticArray& other) const {
        return !(*this == other);
    }

    explicit operator bool() const {
        return N > 0;
    }

private:
    T data_[N]{};
};
