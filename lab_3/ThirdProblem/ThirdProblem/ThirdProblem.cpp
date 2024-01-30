#include <iostream>
#include <string>

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

    string getCurrentDate() const {
        return "2024-01-30"; 
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    
    Soft software("Word", "Microsoft", 2.5, "2024-02-31");

    software.display();

    return 0;
}
