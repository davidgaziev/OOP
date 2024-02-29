#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

template <class T> class Stack {
private:
    vector<T> elements;
public:
    void push(const T& item) {
        elements.push_back(item);
    }

    T pop() {
        if (elements.empty()) {
            cout << "Стек пуст!" << endl;
            exit(1);
        }
        T topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    T top() const {
        if (elements.empty()) {
            cerr << "Стек пуст!" << endl;
            exit(1);
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }
};

class Worker {
private:
    string surname;
    string specialty;


public:

    Worker(const string& s, const string& sp) : surname(s), specialty(sp) {}

    string getSurname() const { return surname; }
    string getSpecialty() const { return specialty; }
};

class FactoryManager {
private:
    Stack<Stack<Worker>> factories;

public:
    void addWorkers(int factoryIndex) {
        int numWorkers;
        cout << "Введите количество работников на заводе " << factoryIndex + 1 << ": ";
        cin >> numWorkers;

        Stack<Worker> factoryWorkers;

        for (int j = 0; j < numWorkers; ++j) {
            string surname, specialty;
            int age;
            double averageSalary;

            cout << "Введите фамилию работника " << j + 1 << ": ";
            cin >> surname;
            cout << "Введите специальность работника " << j + 1 << " (слесарь/токарь): ";
            cin >> specialty;

            factoryWorkers.push(Worker(surname, specialty));
        }

        factories.push(factoryWorkers);
    }

    void countWorkers(int& numFitters, int& numTurners) {
        while (!factories.isEmpty()) {
            Stack<Worker> factory = factories.pop();
            while (!factory.isEmpty()) {
                Worker worker = factory.pop();

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

int main()
{
    setlocale(LC_ALL, "ru");
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
