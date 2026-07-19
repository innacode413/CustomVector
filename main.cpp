#include <iostream>
#include "vector.h"

int main() {
    std::cout << "=== Тестування класу vector ===\n\n";

    vector v(5);
    std::cout << "Initial size: " << v.getSize() << "\n\n";

    v.set(0, 10);
    v.set(4, 40);

    std::cout << "Element at index 0: " << v.get(0) << "\n";
    std::cout << "Element at index 4: " << v.get(4) << "\n\n";

    std::cout << "--- Resizing to 10 ---\n";
    v.resize(10);
    std::cout << "New size after resize: " << v.getSize() << "\n\n";

    v.set(5, 50);
    std::cout << "Element at index 5: " << v.get(5) << "\n\n";

    std::cout << "--- Resizing to 3 ---\n";
    v.resize(3);
    std::cout << "New size after resize: " << v.getSize() << "\n\n";

    std::cout << "Final element at index 0: " << v.get(0) << "\n";
    std::cout << "Final element at index 2: " << v.get(2) << "\n\n";

    std::cout << "=== Тестування копіювання та операторів ===\n\n";

    vector a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    vector b(a);
    std::cout << "b created via copy ctor, b[1] = " << b[1] << "\n";

    vector c(3);
    c = a;
    std::cout << "c assigned via operator=, c[2] = " << c[2] << "\n";

    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != c: " << (a != c) << "\n";

    b[1] = 99;
    std::cout << "after b[1] = 99 -> a == b: " << (a == b) << "\n";
    std::cout << "after b[1] = 99 -> a != b: " << (a != b) << "\n";

    vector d(2);
    std::cout << "a == d (different size): " << (a == d) << "\n";

    return 0;
}
