#include <iostream>
#include "vector.h"
#include "static_array.h"

int main() {
    std::cout << "=== Тестування шаблонного Vector<int> ===\n\n";

    Vector<int> v(5);
    std::cout << "Initial size: " << v.getSize() << "\n";

    v.set(0, 10);
    v.set(4, 40);

    std::cout << "Element at index 0: " << v.get(0) << "\n";
    std::cout << "Element at index 4: " << v.get(4) << "\n\n";

    std::cout << "--- Resizing to 10 ---\n";
    v.resize(10);
    std::cout << "New size after resize: " << v.getSize() << "\n";
    v.set(5, 50);
    std::cout << "Element at index 5: " << v.get(5) << "\n\n";

    Vector<int> copy(v);
    std::cout << "copy[0] via copy ctor: " << copy[0] << "\n";
    std::cout << "v == copy: " << (v == copy) << "\n";

    Vector<int> empty;
    std::cout << "empty -> " << (empty ? "не порожній" : "порожній") << "\n";
    std::cout << "v -> " << (v ? "не порожній" : "порожній") << "\n";

    std::cout << "\n=== Тестування шаблонного Vector<double> ===\n\n";

    Vector<double> d(3);
    d[0] = 1.5;
    d[1] = 2.25;
    d[2] = 3.75;
    std::cout << "d[0] = " << d[0] << ", d[1] = " << d[1] << ", d[2] = " << d[2] << "\n";

    try {
        d[10];
    } catch (const std::out_of_range& ex) {
        std::cout << "operator[] некоректний індекс: " << ex.what() << "\n";
    }

    std::cout << "\n=== Тестування StaticArray<int, 5> ===\n\n";

    StaticArray<int, 5> arr;
    arr.set(0, 100);
    arr.set(4, 500);
    std::cout << "arr[0] = " << arr[0] << ", arr[4] = " << arr.get(4) << "\n";
    std::cout << "arr size: " << arr.getSize() << "\n";

    StaticArray<int, 5> arr2;
    arr2[0] = 100;
    arr2[4] = 500;
    std::cout << "arr == arr2: " << (arr == arr2) << "\n";

    arr[0] = 1;
    std::cout << "after arr[0] = 1 -> arr != arr2: " << (arr != arr2) << "\n";

    StaticArray<double, 3> arrD;
    arrD[0] = 1.1;
    arrD[1] = 2.2;
    arrD[2] = 3.3;
    std::cout << "StaticArray<double,3>: " << arrD[0] << ", " << arrD[1] << ", " << arrD[2] << "\n";

    try {
        arr[10];
    } catch (const std::out_of_range& ex) {
        std::cout << "StaticArray operator[] некоректний індекс: " << ex.what() << "\n";
    }

    return 0;
}
