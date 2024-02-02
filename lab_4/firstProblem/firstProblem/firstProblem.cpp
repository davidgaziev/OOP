#include <iostream>
#include <string>
using namespace std;

class Kamaz {
private: 
    string name;
    double speed;

public: 
    Kamaz(const string& name = "", double speed = 0) : name(name), speed(speed) {}

    void showParam() const {
        cout << "Название: " << name << endl;
        cout << "Скорость: " << speed << endl;
    }

    double getSpeed() const {
        return speed;
    }

    void changeSpeed(double newSpeed) {
        speed = newSpeed;
    }
};

class Tatra {
private:
    string name;
    double speed;

public:
    Tatra(const string& name = "", double speed = 0) : name(name), speed(speed) {}

    void showParam() const {
        cout << "Название: " << name << endl;
        cout << "Скорость: " << speed << endl;
    }

    double getSpeed() const {
        return speed;
    }

    void changeSpeed(double newSpeed) {
        speed = newSpeed;
    }
};

int compareSpeed(Kamaz kamaz, Tatra tatra) {
    if (kamaz.getSpeed() > tatra.getSpeed()) return 1;
    else if (kamaz.getSpeed() < tatra.getSpeed()) return -1;

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
    kamaz.showParam();
    tatra.showParam();

    printResult(compareSpeed(kamaz, tatra));

    kamaz.changeSpeed(90);
    tatra.changeSpeed(80);

    cout << "Трасса 'Горы': \n";
    kamaz.showParam();
    tatra.showParam();

    printResult(compareSpeed(kamaz, tatra));

    kamaz.changeSpeed(50);
    tatra.changeSpeed(50);

    cout << "Трасса 'Пустыня': \n";
    kamaz.showParam();
    tatra.showParam();

    printResult(compareSpeed(kamaz, tatra));
    
    return 0;
}

