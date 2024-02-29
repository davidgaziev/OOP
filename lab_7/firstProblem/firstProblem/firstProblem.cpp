#include <iostream>

using namespace std;

class Array {
public:
    static const int MAX_SIZE = 100; 
    unsigned int elements[MAX_SIZE]; 
    int numElements; 

public:
    Array(int size = 0, unsigned int initialValue = 0) : numElements(size) {
        for (int i = 0; i < size; ++i) {
            elements[i] = initialValue;
        }
    }

    virtual ~Array() {}

    virtual void addArrays(const Array& arr) const {
        int minSize = min(numElements, arr.numElements);
        for (int i = 0; i < minSize; ++i) {
            cout << "i[" << i << "] = " << elements[i] + arr.elements[i] << "; ";
        }
        cout << endl;
    }
};

class Array1 : public Array {
public:
    Array1(int size = 0, unsigned int initialValue = 0) : Array(size, initialValue) {}

    void addArrays(const Array& arr) const override {
        int minSize = min(numElements, arr.numElements);
        for (int i = 0; i < minSize; ++i) {
            cout << "i[" << i << "] = " << elements[i] + arr.elements[i] + 1 << "; ";
        }
        cout << endl;
    }
};

class Array2 : public Array {
public:
    Array2(int size = 0, unsigned int initialValue = 0) : Array(size, initialValue) {}

    void addArrays(const Array& arr) const override {
        int minSize = min(numElements, arr.numElements);

        for (int i = 0; i < minSize; ++i) {
            cout << "i[" << i << "] = " << elements[i] + arr.elements[i] + 2 << "; ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Array array1(5, 1); 
    Array array2(5, 2); 
    Array1 array1_1(3, 3);
    Array2 array2_2(4, 4);

    cout << "Array1 + Array2:\n";
    array1.addArrays(array2); 

    cout << "Array1_1 + Array2:\n";
    array1_1.addArrays(array2); 

    cout << "Array1_1 + Array2_2:\n";
    array1_1.addArrays(array2_2); 

    cout << "Array2_2 + Array1_1:\n";
    array2_2.addArrays(array1_1);

    return 0;
}

