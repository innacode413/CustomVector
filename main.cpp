#include <iostream>
#include <sstream>
#include "vector.h"
#include "static_array.h"

int main() {
    std::cout << "=== Тестування capacity-логіки ===\n\n";

    Vector<int> v;
    std::cout << "empty: size=" << v.getSize() << ", capacity=" << v.getCapacity() << "\n";

    for (int i = 0; i < 10; ++i) {
        v.push_back(i * 10);
        std::cout << "push_back(" << i * 10 << "): size=" << v.getSize()
                  << ", capacity=" << v.getCapacity() << "\n";
    }

    std::cout << "\nelements: ";
    for (int i = 0; i < v.getSize(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    std::cout << "\n--- reserve ---\n";
    v.reserve(50);
    std::cout << "after reserve(50): size=" << v.getSize()
              << ", capacity=" << v.getCapacity() << "\n";

    std::cout << "\n--- resize(5) ---\n";
    v.resize(5);
    std::cout << "after resize(5): size=" << v.getSize()
              << ", capacity=" << v.getCapacity() << "\n";

    std::cout << "\n=== Тестування операторів << і >> ===\n\n";

    Vector<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    std::cout << "operator<<: " << a << "\n";

    std::stringstream ss("42 43 44");
    Vector<int> b;
    ss >> b;
    ss >> b;
    ss >> b;
    std::cout << "operator>> (з stringstream): " << b << "\n";

    Vector<double> d;
    d.push_back(1.5);
    d.push_back(2.25);
    std::cout << "Vector<double>: " << d << "\n";

    return 0;
}
