#include <iostream>

using namespace std;

const double pi = 3.1415;

class Figure {
public:

    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Rectangle : public Figure {
public:
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) { };

    double area() {
        return width * height;
    }

    double perimeter() {
        return 2 * (width + height);
    }
};

class Circle : public Figure {
public:
    double radius;

    Circle(double r) : radius(r) { };

    double area() {
        return pi * radius * radius;
    }

    double perimeter() {
        return 2 * pi * radius;
    }
};

class Trapezium : public Figure {
public: 
    double sideA;
    double sideB;
    double sideC;
    double sideD;
    double height;

    Trapezium(double a, double b, double c, double d, double h) : sideA(a), sideB(b), sideC(c), sideD(d), height(h) { };

    double area() {
        return (sideA + sideB) / 2 * height;
    }

    double perimeter() {
        return sideA + sideB + sideC + sideD;
    }
        
};

int main()
{
    setlocale(LC_ALL, "ru");

    Rectangle rectangle(4, 5);
    Circle circle(3);
    Trapezium trapezium(1, 2, 3, 4, 5);


    cout << "Площадь прямоугольника: " << rectangle.area() << endl;
    cout << "Периметр прямоугольника: " << rectangle.perimeter() << endl;

    cout << "Площадь круга: " << circle.area() << endl;
    cout << "Периметр круга: " << circle.perimeter() << endl;

    cout << "Площадь трапеции: " << trapezium.area() << endl;
    cout << "Периметр трапеции: " << trapezium.perimeter() << endl;
    


}
