#include <iostream>
#include <stdexcept>

using namespace std;

class Int {
private:
    long double value;

public:
    Int(long double val = 0) : value(val) {}

    Int operator+(const Int& other) const {
        long double result = value + other.value;
        if (result > LLONG_MAX || result < LLONG_MIN) {
            throw overflow_error("Выход за границы целого числа!");
        }
        return Int(result);
    }

    Int operator-(const Int& other) const {
        long double result = value - other.value;
        if (result > LLONG_MAX || result < LLONG_MIN) {
            throw overflow_error("Выход за границы целого числа!");
        }
        return Int(result);
    }

    Int operator*(const Int& other) const {
        long double result = value * other.value;
        if (result > LLONG_MAX || result < LLONG_MIN) {
            throw overflow_error("Выполнение оператора умножения\nВыход за границы целого числа!");
        }
        return Int(result);
    }

    Int operator/(const Int& other) const {
        if (other.value == 0) {
            throw runtime_error("Деления на ноль!");
        }
        long double result = value / other.value;
        if (result > LLONG_MAX || result < LLONG_MIN) {
            throw overflow_error("Выполнение оператора деления\nВыход за границы целого числа!");
        }
        return Int(result);
    }

    Int& operator++() {
        if (value == LLONG_MAX) {
            throw overflow_error("Выполнение унарного оператора сложения\nВыход за границы целого числа!");
        }
        ++value;
        return *this;
    }

    Int operator++(int) {
        Int temp = *this;
        ++(*this);
        return temp;
    }

    Int& operator--() {
        if (value == LLONG_MIN) {
            throw overflow_error("Выполнение унарного оператора вычитания\nВыход за границы целого числа!");
        }
        --value;
        return *this;
    }

    Int operator--(int) {
        Int temp = *this;
        --(*this);
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Int& num) {
        out << num.value;
        return out;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    try {
        Int a = LLONG_MAX; 
        Int b = 1;

        Int sum = a + b;
        cout << "Сумма: " << sum << endl;

        Int diff = a - b;
        cout << "Разность: " << diff << endl;

        Int prod = a * b;
        cout << "Произведение: " << prod << endl;

        Int div = a / b;
        cout << "Деление: " << div << endl;

        Int c = LLONG_MAX - 1000;

        cout << "c до постфиксного инкремента: " << c++ << endl;
        cout << "c после постфиксного инкремента: " << c << endl;
        cout << "c до префиксного инкремента: " << ++c << endl;

        Int d = LLONG_MIN + 1000;
        cout << "d до постфиксного декремента: " << d-- << endl;
        cout << "d после постфиксного декремента: " << d << endl;
        cout << "d до префиксного декремента: " << --d << endl;
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
