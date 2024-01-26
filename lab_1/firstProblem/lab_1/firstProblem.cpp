#include <iostream>
using namespace std;


double power(double n, int p = 2) {
    double result = n;

    for (int i = 1; i < p; i++) {
        result *= n;
    }

    return result;
}

char power(char n, int p = 2) {
    char result = n;

    double temp = n;
    double temp2 = n;

    for (int i = 1; i < p; i++) {
        cout << temp << endl;
        temp *= temp2;
        result *= n;
    }

    cout << temp << endl;

    return result;
}

short int power(short int n, int p = 2) {
    short int  result = n;

    for (int i = 1; i < p; i++) {
        result *= n;
    }

    return result;
}

long int power(long int n, int p = 2) {
    long int result = n;

    for (int i = 1; i < p; i++) {
        result *= n;
    }

    return result;
}

float power(float n, int p = 2) {
    float result = n;

    for (int i = 1; i < p; i++) {
        result *= n;
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double inputDouble, result;
    int powerDigit, answer;
   
    char inputChar, resultChar;
    short int inputShortInt, resultShortInt;
    long int inputLongInt, resultLongInt;
    float inputFloat, resultFloat;

    cout << "Введите:\n" << "double: ";
    cin >> inputDouble;
    cout << "char: ";
    cin >> inputChar;
    cout << "short int: ";
    cin >> inputShortInt;
    cout << "long int: ";
    cin >> inputLongInt;
    cout << "float: ";
    cin >> inputFloat;
    cout << "Хотите ли ввести степень? (>=1 - да, 0 - нет): ";
    cin >> answer;
    if (answer) {
        while (true) {
            cout << "Введите степень: ";
            cin >> powerDigit;
            if (powerDigit > 2) break;
            else cout << "Степень должна быть больше 2!\n";
        }
        result = power(inputDouble, powerDigit);
        resultChar = power(inputChar, powerDigit);
        resultShortInt = power(inputShortInt, powerDigit);
        resultLongInt = power(inputLongInt, powerDigit);
        resultFloat = power(inputFloat, powerDigit);
    }
    else {
        result = power(inputDouble);
        resultChar = power(inputChar);
        resultShortInt = power(inputShortInt);;
        resultLongInt = power(inputLongInt);
        resultFloat = power(inputFloat);
    }
    
    cout << "Результат:\n" << "double: " << result << endl;
    cout << "char: " << resultChar << endl;
    cout << "short int: " << resultShortInt  << endl;
    cout << "long int: " << resultLongInt << endl;
    cout << "float: " << resultFloat << endl;
}
