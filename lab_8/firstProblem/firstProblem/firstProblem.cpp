// firstProblem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

template <class T> T findMax(const T* array, int size) {
    T max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

template <class T> void sort(T* array, int size) {
    T temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

template <class T> void display(const T* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << "A[" << i << "] = " << array[i] << "; ";
    }

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    
    const int sizeArray = 5;

    int intArray[sizeArray] = {1, 10, 2, 5, 12};
    double doubleArray[sizeArray] = { 2.5, 125.22, 1.2, 55.3, 0.2 };

    cout << "Массив типа INT:\n";
    cout << "Максимальное значение элемента в массиве = " << findMax(intArray, sizeArray) << endl;
    
    sort(intArray, sizeArray);

    cout << "Отсортированный массив: \n";
    display(intArray, sizeArray);

    cout << "\n\nМассив типа DOUBLE:\n";
    cout << "Максимальное значение элемента в массиве = " << findMax(doubleArray, sizeArray) << endl;

    sort(doubleArray, sizeArray);

    cout << "Отсортированный массив: \n";
    display(doubleArray, sizeArray);

    return 0;
}

