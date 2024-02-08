#include <iostream>
#include <stdexcept>

using namespace std;

class Fraction {
private:
    double value;

public:
    Fraction(double val = 0) : value(val) {}

    Fraction operator+(const Fraction& other) const {
        return Fraction(value + other.value);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(value - other.value);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(value * other.value);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.value == 0) {
            throw runtime_error("Деление на ноль!");
        }
        return Fraction(value / other.value);
    }

    friend Fraction operator+(double num, const Fraction& frac)  {
        return Fraction(frac.value + num);
    }

    friend Fraction operator-(double num, const Fraction& frac)  {
        return Fraction(frac.value - num);
    }

    friend Fraction operator*(double num, const Fraction& frac)  {
        return Fraction(frac.value * num);
    }

    friend Fraction operator/(double num, const Fraction& frac)  {
        if (num == 0) {
            throw runtime_error("Деление на ноль!");
        }
        return Fraction(frac.value / num);
    }

    Fraction& operator++() {
        value++;
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    void display() const {
        cout << value;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Fraction a(3.0); 
    Fraction b(0.5);

    cout << "Начальные значения:\na = ";
    a.display();
    cout << "\nb = ";
    b.display();
    cout << "\n\n";

    Fraction c = a + b; cout << "a + b = ";
    c.display();
    cout << endl;

    Fraction d = a - 2; 
    cout << "a - 2 = ";
    d.display();
    cout << endl;

    Fraction e = b * 2; 
    cout << "2 * b = ";
    e.display();
    cout << endl;

    Fraction f = a / 4; 
    cout << "a / 4 = ";
    f.display();
    cout << endl;

    Fraction g = ++c; 
    cout << "++c = ";
    g.display();
    cout << endl;

    Fraction h = d++; 
    cout << "d++ = ";
    h.display();
    cout << endl;

    Fraction j = a / 1 + 15;
    cout << "a / 1  + 15 = ";
    j.display();
    cout << endl;

    return 0;
}
