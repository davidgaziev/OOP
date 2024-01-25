#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Worker {
private:
    string surname;
    int age;
    string specialty;
    double averageSalary;

public:
    
    Worker(const string& s, int a, const string& sp, double sal) : surname(s), age(a), specialty(sp), averageSalary(sal) {}

    string getSurname() const { return surname; }
    int getAge() const { return age; }
    string getSpecialty() const { return specialty; }
    double getAverageSalary() const { return averageSalary; }
};


class FactoryManager {
private:
    vector<vector<Worker>> factories; 

public:
    void addWorkers(int factoryIndex) {
        int numWorkers;
        cout << "Введите количество работников на заводе " << factoryIndex + 1 << ": ";
        cin >> numWorkers;

        vector<Worker> factoryWorkers; 

        for (int j = 0; j < numWorkers; ++j) {
            string surname, specialty;
            int age;
            double averageSalary;

            cout << "Введите фамилию работника " << j + 1 << ": ";
            cin >> surname;
            cout << "Введите возраст работника " << j + 1 << ": ";
            cin >> age;
            cout << "Введите специальность работника " << j + 1 << " (слесарь/токарь): ";
            cin >> specialty;
            cout << "Введите средний оклад работника " << j + 1 << ": ";
            cin >> averageSalary;

            factoryWorkers.emplace_back(surname, age, specialty, averageSalary);
        }

        factories.push_back(factoryWorkers); 
    }

    void countWorkers(int& numFitters, int& numTurners) {
        for (const auto& factory : factories) {
            for (const auto& worker : factory) {
                if (worker.getSpecialty() == "слесарь") {
                    numFitters++;
                }
                else if (worker.getSpecialty() == "токарь") {
                    numTurners++;
                }
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251); 

    int numFactories;
    cout << "Введите количество заводов: ";
    cin >> numFactories;

    FactoryManager factoryManager;

    for (int i = 0; i < numFactories; ++i) {
        factoryManager.addWorkers(i);
    }

    int numFitters = 0;
    int numTurners = 0;
    factoryManager.countWorkers(numFitters, numTurners);

    cout << "Количество слесарей: " << numFitters << endl;
    cout << "Количество токарей: " << numTurners << endl;

    return 0;
}
