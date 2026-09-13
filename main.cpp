#include <iostream>
#include <sstream>
#include <algorithm>
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

    std::cout << "\n=== Тестування ітераторів ===\n\n";

    std::cout << "Обхід через begin()/end(): ";
    for (Vector<int>::Iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "Range-for (використовує begin/end): ";
    for (int value : v) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "Ітератори random access:\n";
    Vector<int>::Iterator first = v.begin();
    std::cout << "  *begin = " << *first << "\n";
    std::cout << "  begin[2] = " << first[2] << "\n";
    std::cout << "  *(begin + 3) = " << *(first + 3) << "\n";
    std::cout << "  end - begin = " << (v.end() - v.begin()) << "\n";
    std::cout << "  begin < begin+2: " << (first < first + 2) << "\n";

    std::cout << "std::sort через ітератори: ";
    Vector<int> s(3);
    s[0] = 5;
    s[1] = 1;
    s[2] = 4;
    std::sort(s.begin(), s.end());
    std::cout << s << "\n";

    std::cout << "const ітератори: ";
    const Vector<int>& cref = v;
    for (Vector<int>::Iterator it = cref.begin(); it != cref.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "\n=== Тестування операторів << і >> ===\n\n";

    Vector<int> a(3);
    a[0] = 3;
    a[1] = 1;
    a[2] = 2;

    std::cout << "operator<<: " << a << "\n";

    std::stringstream ss("42 43 44");
    Vector<int> b;
    ss >> b;
    ss >> b;
    ss >> b;
    std::cout << "operator>> (з stringstream): " << b << "\n";

    return 0;
}