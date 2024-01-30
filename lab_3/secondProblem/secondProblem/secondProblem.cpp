#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Nomenclature {
private:
    string* itemName;
    double wholesalePrice;
    double retailMarkup;
    int quantity;

public:
    //Случай когда нет необходимости в декострукторе 
    /*Nomenclature(const string& name = "", double wholesale = 0.0, double markup = 0.0, int qty = 0)
        : itemName(name), wholesalePrice(wholesale), retailMarkup(markup), quantity(qty) {}*/

    // Случай когда есть необходимость в декострукторе
    Nomenclature(const string& name = "", double wholesale = 0.0, double markup = 0.0, int qty = 0)
        : itemName(new string(name)), wholesalePrice(wholesale), retailMarkup(markup), quantity(qty) {}

    ~Nomenclature() {
        delete itemName; 
    }

    void setItem(const string& name, double wholesale, double markup, int qty) {
        *itemName = name;
        wholesalePrice = wholesale;
        retailMarkup = markup;
        quantity = qty;
    }

    double calculateProfit() const {
        double retailPrice = wholesalePrice * (1 + retailMarkup);
        return retailPrice * quantity - wholesalePrice * quantity;
    }

    void display() const {
        cout << "Название товара: " << *itemName << endl;
        cout << "Оптовая цена: " << wholesalePrice << endl;
        cout << "Розничная наценка: " << retailMarkup * 100 << "%" << endl;
        cout << "Количество на складе: " << quantity << endl;
        cout << "Возможный чистый доход: " << calculateProfit() << endl;
    }

    bool hasItems() const {
        return quantity > 0;
    }
};

void printMenu() {
    cout << "Меню:\n";
    cout << "1. Ввести новый товар\n";
    cout << "2. Вывести информацию о товаре\n";
    cout << "0. Выйти из программы\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    setlocale(LC_ALL, "ru");


    Nomenclature item;
    int choice;

    do {
        printMenu();
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            double wholesale, markup;
            int qty;

            cout << "Введите название товара: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите оптовую цену: ";
            cin >> wholesale;
            cout << "Введите розничную наценку (в долях, например, 0.2 для 20%): ";
            cin >> markup;
            cout << "Введите количество товара: ";
            cin >> qty;

            item.setItem(name, wholesale, markup, qty);
            break;
        }
        case 2: {
            if (item.hasItems()) {
                item.display();
            }
            else {
                cout << "Нет данных о товаре. Сначала введите товар.\n";
            }
            break;
        }
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите опцию из меню.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
