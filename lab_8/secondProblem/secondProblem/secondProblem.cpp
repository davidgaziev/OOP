// secondProblem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

template <class T, int sizeArray> class Array {
public:
    T firstArray[sizeArray] = {};
    T secondArray[sizeArray] = {};

    void fill() {
        for (int i = 0; i < sizeArray; i++) {
            firstArray[i] = rand() % 10;
            secondArray[i] = rand() % 10;
        }
    }

    void display() {
        for (int i = 0; i < sizeArray; i++) {
            cout << "F[" << i << "] = " << firstArray[i] << "; ";
        }

        cout << "\n\n";

        for (int i = 0; i < sizeArray; i++) {
            cout << "S[" << i << "] = " << secondArray[i] << "; ";
        }

        cout << "\n";
    }

    T sum() {
        T sum = 0;
        for (int i = 0; i < sizeArray; i++) {
            sum += firstArray[i] + secondArray[i];
        }

        return sum;
    }

};

int main() {
    setlocale(LC_ALL, "rus");

    const int sizeArray = 5;

    cout << "Массив типа INT:\n";

    Array<int, sizeArray> arr;

    arr.fill();
    arr.display();

    cout << "Сумма массивов: " << arr.sum() << endl;

    cout << "\nМассив типа DOUBLE:\n";

    Array<double, sizeArray> arr1;

    arr1.fill();
    arr1.display();

    cout << "Сумма массивов: " << arr1.sum() << endl;

    return 0;
}
