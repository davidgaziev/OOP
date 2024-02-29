#include <iostream>

using namespace std;

class Currency {
public: 
    double amount;
    double changeAmount;
    
    Currency() { amount = 0; changeAmount = 0; };

    virtual void exchange(double sum) {
        changeAmount = sum;
        amount = sum / 1.01;
    }

    virtual void display() {
        cout << changeAmount << " сом = " << amount << " рублей" << endl;
    }

};

class Dollar : public Currency {
public: 
    void exchange(double sum) {
        changeAmount = sum;
        amount = sum / 89.5;
    }

    void display() {
        cout << changeAmount << " сом = " << amount << " долларов" << endl;
    }
};

class Euro : public Currency {
public:
    void exchange(double sum) {
        changeAmount = sum;
        amount = sum / 96.25;
    }

    void display() {
        cout << changeAmount << " сом = " << amount << " евро" << endl;
    }
};


int main(){
    setlocale(LC_ALL, "ru");
    
    Currency rub;
    Dollar usd;
    Euro eur;

    cout << "Обмен валют:\n";

    rub.exchange(1000);
    rub.display();

    usd.exchange(1000);
    usd.display();

    eur.exchange(1000);
    eur.display();

    return 0;
}

