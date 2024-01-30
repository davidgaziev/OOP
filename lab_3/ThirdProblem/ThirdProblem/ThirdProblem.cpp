#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Soft {
private:
    string* programName;
    string* developer;
    double sizeInGB;
    string* licenseExpirationDate;

public:
    Soft(const string& name = "", const string& dev = "", double size = 0.0, const string& expiration = "")
        : programName(new string(name)), developer(new string(dev)), sizeInGB(size), licenseExpirationDate(new string(expiration)) {}

    ~Soft() {
        delete programName;
        delete developer;
        delete licenseExpirationDate;
    }

    void display() const {
        cout << "Название программы: " << *programName << endl;
        cout << "Разработчик: " << *developer << endl;
        cout << "Занимаемый объем: " << sizeInGB << " GB" << endl;
        cout << "Дата завершения лицензии: " << *licenseExpirationDate << endl;
        cout << "Дней до завершения лицензии: " << daysUntilExpiration() << endl;
    }

    int daysUntilExpiration() const {
        string currentDate = getCurrentDate();

        int expirationYear, expirationMonth, expirationDay;
        int currentYear, currentMonth, currentDay;
        sscanf_s(licenseExpirationDate->c_str(), "%d-%d-%d", &expirationYear, &expirationMonth, &expirationDay);
        sscanf_s(currentDate.c_str(), "%d-%d-%d", &currentYear, &currentMonth, &currentDay);

        int expirationTotalDays = expirationYear * 365 + expirationMonth * 30 + expirationDay;
        int currentTotalDays = currentYear * 365 + currentMonth * 30 + currentDay;

        int daysLeft = expirationTotalDays - currentTotalDays;
        return daysLeft;
    }

    string getProgramName() const {
        return *programName;
    }

    string getDeveloper() const {
        return *developer;
    }

    double getSize() const {
        return sizeInGB;
    }

    string getLicenseExpDate() const {
        return *licenseExpirationDate;
    }

    string getCurrentDate() const {
        return "2024-01-30";
    }

    Soft(const Soft& other)
        : programName(new string(*(other.programName))), developer(new string(*(other.developer))),
        sizeInGB(other.sizeInGB), licenseExpirationDate(new string(*(other.licenseExpirationDate))) {}

    Soft& operator=(const Soft& other) {
        if (this != &other) {
            *programName = *(other.programName);
            *developer = *(other.developer);
            sizeInGB = other.sizeInGB;
            *licenseExpirationDate = *(other.licenseExpirationDate);
        }
        return *this;
    }
};

void printMenu() {
    cout << "\nМеню выбора опций:\n";
    cout << "1. Добавить программу\n";
    cout << "2. Вывести информацию о программе\n";
    cout << "0. Выход\n";
}

int main() {
    setlocale(LC_ALL, "ru");

    vector<Soft> softwareList;
    int choice;

    do {
        printMenu();
        cout << "Введите номер выбранной опции: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, developer, expiration;
            double size;

            cout << "\nВведите название программы: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите разработчика: ";
            getline(cin, developer);
            cout << "Введите размер программы в GB: ";
            cin >> size;
            cout << "Введите дату завершения лицензии (гггг-мм-дд): ";
            cin >> expiration;

            softwareList.emplace_back(name, developer, size, expiration);
            cout << "Программа добавлена.\n";
            break;
        }
        case 2: {
            if (softwareList.empty()) {
                cout << "\nНет данных о программе. Добавьте программу сначала.\n";
            }
            else {
                cout << "\nИнформация о программном обеспечении:\n";
                cout << setw(20) << left << "Название" << setw(20) << "Разработчик" << setw(15) << "Размер (GB)" << setw(20) << "Дата завершения" << setw(15) << "Дней до завершения" << endl;
                cout << "---------------------------------------------------------------------------------------------------------\n";

                for (const auto& software : softwareList) {
                    cout << setw(20) << left << software.getProgramName() << setw(20) << software.getDeveloper() << setw(15) << software.getSize() <<
                        setw(20) << software.getLicenseExpDate() << setw(15) << software.daysUntilExpiration() << endl;
                }
            }
            break;
        }
        case 0:
            cout << "Программа завершена.\n";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите опцию из меню.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
