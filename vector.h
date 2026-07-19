#pragma once

class vector {
public:
    vector(int sizeOffArray);
    vector(const vector& other);
    ~vector();

    vector& operator=(const vector& other);

    void resize(int newSize);
    void set(int index, int newValue);
    int get(int index) const;
    int getSize() const;

    int& operator[](int index);
    const int& operator[](int index) const;

    bool operator==(const vector& other) const;
    bool operator!=(const vector& other) const;

private:
    int size;
    int* dynamicArray;
};
