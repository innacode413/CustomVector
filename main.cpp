#include <iostream>
#include <sstream>
#include "vector.h"
#include "static_array.h"
#include "sort.h"

int main() {
    std::cout << "=== Тестування capacity-логіки ===\n\n";

    Vector<int> v;
    std::cout << "empty: size=" << v.getSize() << ", capacity=" << v.getCapacity() << "\n";

    for (int i = 0; i < 10; ++i) {
        v.push_back((9 - i) * 10);
        std::cout << "push_back(" << (9 - i) * 10 << "): size=" << v.getSize()
                  << ", capacity=" << v.getCapacity() << "\n";
    }

    std::cout << "\nelements before sort: " << v << "\n";
    insertion_sort(v);
    std::cout << "elements after sort:  " << v << "\n";

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
    a[0] = 3;
    a[1] = 1;
    a[2] = 2;

    std::cout << "operator<<: " << a << "\n";
    insertion_sort(a);
    std::cout << "sorted:      " << a << "\n";

    std::stringstream ss("42 43 44");
    Vector<int> b;
    ss >> b;
    ss >> b;
    ss >> b;
    std::cout << "operator>> (з stringstream): " << b << "\n";
    insertion_sort(b);
    std::cout << "sorted:                       " << b << "\n";

    std::cout << "\n=== Тестування шаблонного Vector<double> ===\n\n";

    Vector<double> d;
    d.push_back(3.3);
    d.push_back(1.1);
    d.push_back(2.2);
    std::cout << "Vector<double> before sort: " << d << "\n";
    insertion_sort(d);
    std::cout << "Vector<double> after sort:  " << d << "\n";

    return 0;
}
