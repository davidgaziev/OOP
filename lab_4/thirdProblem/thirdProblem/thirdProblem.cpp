#include <iostream>
#include <string>
using namespace std;

class Tatra;

class Kamaz {
private:
    string name;
    double speed;

public:
    Kamaz(const string& name = "", double speed = 0) : name(name), speed(speed) {}

    double getSpeed() const {
        return speed;
    }

    void changeSpeed(double newSpeed) {
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
    Tatra(const string& name = "", double speed = 0) : name(name), speed(speed) {}

    void showParam(Kamaz kamaz) const {
        cout << "Название: " << name << endl;
        cout << "Скорость: " << speed << " км/ч" << endl;

        cout << "Название: " << kamaz.name << endl;
        cout << "Скорость: " << kamaz.speed << " км/ч" << endl;
    }

    void changeSpeed(double newSpeed) {
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

    Kamaz kamaz = Kamaz("kamaz", 45);
    Tatra tatra = Tatra("tatra", 60);

    cout << "Трасса 'Равнина': \n";
    tatra.showParam(kamaz);

    printResult(compareSpeed(kamaz, tatra));

    kamaz.changeSpeed(90);
    tatra.changeSpeed(80);

    cout << "Трасса 'Горы': \n";
    tatra.showParam(kamaz);

    printResult(compareSpeed(kamaz, tatra));

    kamaz.changeSpeed(50);
    tatra.changeSpeed(50);

    cout << "Трасса 'Пустыня': \n";
    tatra.showParam(kamaz);

    printResult(compareSpeed(kamaz, tatra));

    return 0;
}

