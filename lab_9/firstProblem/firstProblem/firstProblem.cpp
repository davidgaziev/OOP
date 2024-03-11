// firstProblem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <process.h>

using namespace std;

const int LIMIT = 5;

class SafeArray {
private:
    int arr[LIMIT];
public:
    class Range {
    public:
        string msg; 
        Range(string msg) : msg(msg){ }
    };

    void push(int n, int value) {
        if (n < 0 || n >= LIMIT) {
            throw Range("\nОшибочный индекс!\n");
        }

        arr[n] = value;
    }

    int get(int n) const{
        if (n < 0 || n >= LIMIT) {
            throw Range("\nОшибочный индекс!\n");
        }

        return arr[n];
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    SafeArray arr;


    for (int i = 0; i < LIMIT; i++) {
        arr.push(i, i * 10);
    }

    for (int i = 0; i < LIMIT; i++) {
        cout << "Элемент #" << i << " = " << arr.get(i) << endl;
    }

    try {
        arr.push(11, 5);
    }
    catch (SafeArray::Range error) {
        cout << error.msg;
    }

    return 0;
}
