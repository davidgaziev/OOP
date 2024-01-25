#include <iostream>
using namespace std;


static double power(double n, int p = 2) {
    double result = n;

    for (int i = 1; i < p; i++) {
        result *= n;
    }

    return result;
}

static double power(char n, int p = 2) {
    double temp = n - '0';

    double result = temp;

    for (int i = 1; i < p; i++) {
        result *= temp;
    }

    return result;
}

static double power(short int n, int p = 2) {
    double result = n;

    for (int i = 1; i < p; i++) {
        result *= n;
    }

    return result;
}

static double power(long int n, int p = 2) {
    double result = n;

    for (int i = 1; i < p; i++) {
        result *= n;
    }

    return result;
}

static double power(float n, int p = 2) {
    double result = n;

    for (int i = 1; i < p; i++) {
        result *= n;
    }

    return result;
}



int main()
{
    setlocale(LC_ALL, "Russian");

    float digit;
    int powerDigit, answer;
    double result;

    cout << "Введите число: ";
    cin >> digit;
    cout << "Хотите ли ввести степень? (>=1 - да, 0 - нет): ";
    cin >> answer;
    if (answer) {
        while (true) {
            cout << "Введите степень: ";
            cin >> powerDigit;
            if (powerDigit > 2) break;
            else cout << "Степень должна быть больше 2!\n";
        }
        result = power(digit, powerDigit);
    }
    else {
        result = power(digit);
    }
    
    cout << "Результат: " << result;
}
