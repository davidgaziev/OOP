#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>

using namespace std;

class Nomenclature {
private:
    string itemName;
    double wholesalePrice;
    double retailMarkup;
    int quantity;

public:
    Nomenclature(const string& name = "", double wholesale = 0.0, double markup = 0.0, int qty = 0)
        : itemName(name), wholesalePrice(wholesale), retailMarkup(markup), quantity(qty) {}

    void setItem(const string& name, double wholesale, double markup, int qty) {
        itemName = name;
        wholesalePrice = wholesale;
        retailMarkup = markup;
        quantity = qty;
    }

    double calculateProfit() const {
        double retailPrice = wholesalePrice * (1 + retailMarkup);
        return retailPrice * quantity - wholesalePrice * quantity;
    }

    bool hasItems() const {
        return quantity > 0;
    }

    // Получить название товара
    const string& getItemName() const {
        return itemName;
    }

    // Получить оптовую цену
    double getWholesalePrice() const {
        return wholesalePrice;
    }

    // Получить розничную наценку
    double getRetailMarkup() const {
        return retailMarkup;
    }

    // Получить количество товара
    int getQuantity() const {
        return quantity;
    }
};

void printMenu() {
    cout << "Меню:\n";
    cout << "1. Ввести новый товар\n";
    cout << "2. Вывести информацию о товарах\n";
    cout << "0. Выйти из программы\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    setlocale(LC_ALL, "ru");

    vector<Nomenclature> items;
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

            items.emplace_back(name, wholesale, markup, qty);
            break;
        }
        case 2: {
            if (!items.empty()) {
                cout << setw(20) << left << "Название товара" << setw(15) << "Оптовая цена" << setw(25) << "Розничная наценка (%)" << setw(15) << "Количество" << setw(20) << "Чистый доход" << endl;
                cout << "---------------------------------------------------------------------------------------------------\n";

                for (const auto& item : items) {
                    cout << setw(20) << left << item.getItemName() << setw(15) << item.getWholesalePrice() << setw(25) << item.getRetailMarkup() * 100 << setw(15) << item.getQuantity() << setw(20) << item.calculateProfit() << endl;
                }
                cout << "---------------------------------------------------------------------------------------------------\n";
            }
            else {
                cout << "Нет данных о товарах. Сначала введите товар.\n";
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
