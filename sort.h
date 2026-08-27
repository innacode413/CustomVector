#pragma once

#include "vector.h"

template <typename T>
void insertion_sort(Vector<T>& arr) {
    for (int i = 1; i < arr.getSize(); ++i) {
        T value = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = value;
    }
}
