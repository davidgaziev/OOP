#include <iostream>
#include <string>
using namespace std;

class SpeedExc {
public:
    string msg;
    SpeedExc(string msg) : msg(msg) { }
};

class Tatra;

class Kamaz {
private:
    string name;
    double speed;

public:
    Kamaz(const string& name = "", double speed = 10) : name(name), speed(speed) {
        if (speed <= 0) {
            throw SpeedExc("\nСкорость не может быть меньше или равна 0\n");
        }

        speed = speed;
    }

    void changeSpeed(double newSpeed) {
        if (newSpeed <= 0) {
            throw SpeedExc("\nСкорость не может быть меньше или равна 0\n");
        };
        speed = newSpeed;
    }

    friend class Tatra;
    friend int compareSpeed(Kamaz, Tatra);
};

class Tatra {
private:
    string name;
    double speed;

public:

    Tatra(const string& name = "", double speed = 10) : name(name), speed(speed) {
        if (speed <= 0) {
            throw SpeedExc("\nСкорость не может быть меньше или равна 0\n");
        }

        speed = speed;
    }

    void showParam(Kamaz kamaz) const {
        cout << "Название: " << name << endl;
        cout << "Скорость: " << speed << " км/ч" << endl;

        cout << "Название: " << kamaz.name << endl;
        cout << "Скорость: " << kamaz.speed << " км/ч" << endl;
    }

    void changeSpeed(double newSpeed) {
        if (newSpeed <= 0) {
            throw SpeedExc("\nСкорость не может быть меньше или равна 0\n");
        };
        speed = newSpeed;
    }

    friend int compareSpeed(Kamaz, Tatra);
};

int compareSpeed(Kamaz kamaz, Tatra tatra) {
    if (kamaz.speed > tatra.speed) return 1;
    else if (kamaz.speed < tatra.speed) return -1;

    return 0;
}

void printResult(int result) {
    switch (result) {
    case 1:
        cout << "\nКамаз движется быстрее!\n\n";
        break;
    case -1:
        cout << "\nТатра движется быстрее!\n\n";
        break;
    default:
        cout << "\nГрузовики движутся одинаково!\n\n";
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    try {
        Kamaz kamaz = Kamaz("kamaz", 45);
        Tatra tatra = Tatra("tatra", 60);
        cout << "Трасса 'Равнина': \n";
        tatra.showParam(kamaz);

        printResult(compareSpeed(kamaz, tatra));

        kamaz.changeSpeed(00);
        tatra.changeSpeed(80);

        cout << "Трасса 'Горы': \n";
        tatra.showParam(kamaz);

        printResult(compareSpeed(kamaz, tatra));

        kamaz.changeSpeed(50);
        tatra.changeSpeed(50);

        cout << "Трасса 'Пустыня': \n";
        tatra.showParam(kamaz);

        printResult(compareSpeed(kamaz, tatra));
    }
    catch (SpeedExc error) {
        cout << error.msg;
    }

    return 0;
}