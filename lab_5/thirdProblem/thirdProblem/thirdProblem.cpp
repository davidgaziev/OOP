#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double len = 0, double wid = 0) : length(len), width(wid) {}

    double rect_area(double len, double wid) {
        return len * wid;
    }

    double rect_area(double side) {
        return side * side;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Rectangle rect;

    double length, width;
    cout << "Введите длину прямоугольника: ";
    cin >> length;
    cout << "Введите ширину прямоугольника: ";
    cin >> width;

    cout << "Площадь прямоугольника: " << rect.rect_area(length, width) << endl;

    double side;
    cout << "Введите длину стороны квадрата: ";
    cin >> side;

    cout << "Площадь квадрата: " << rect.rect_area(side) << endl;

    return 0;
}
