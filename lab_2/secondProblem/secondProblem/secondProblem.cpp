#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    string surname;
    string birthDate;
    string phoneNumber;

public:
    Student(const string& sur, const string& bDate, const string& phone) : surname(sur), birthDate(bDate), phoneNumber(phone) {}

    string getSurname() const { return surname; }
    string getBirthDate() const { return birthDate; }
    string getPhoneNumber() const { return phoneNumber; }
};

class StudentDatabase {
private:
    vector<Student> students;

public:
    void addStudent(const string& surname, const string& birthDate, const string& phoneNumber) {
        students.emplace_back(surname, birthDate, phoneNumber);
    }

    bool removeStudent(const string& surname) {
        auto it = remove_if(students.begin(), students.end(), [&](const Student& student) {
            return student.getSurname() == surname;
            });

        if (it != students.end()) {
            students.erase(it, students.end());
            return true;
        }

        return false;
    }   

    Student* findStudentBySurname(const string& surname) {
        auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
            return student.getSurname() == surname;
            });

        if (it != students.end()) {
            return &(*it);
        }

        return nullptr;
    }

    void sortStudentsBySurname() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getSurname() < b.getSurname();
            });
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "База данных студентов пуста." << endl;
            return;
        }

        cout << "-----------------------------------------" << endl;
        cout << "| Фамилия   | Дата рождения | Телефон   |" << endl;
        cout << "-----------------------------------------" << endl;

        for (const auto& student : students) {
            cout << "| " << student.getSurname() << " | " << student.getBirthDate() << " | " << student.getPhoneNumber() << " |" << endl;
        }

        cout << "-----------------------------------------" << endl;
    }

    bool hasStudents() const {
        return !students.empty();
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    StudentDatabase database;

    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Удалить студента" << endl;
        cout << "3. Найти студента по фамилии" << endl;
        cout << "4. Отсортировать студентов по фамилии" << endl;
        cout << "5. Вывести всех студентов" << endl;
        cout << "0. Выйти" << endl;

        int choice;
        cout << "Выберите действие: ";
        cin >> choice;

        if (!database.hasStudents() && choice != 1 && choice != 6) {
            cout << "База данных студентов пуста. Добавьте студента или выберите пункт 'Выйти'." << endl;
            continue;
        }

        switch (choice) {
        case 1: {
            string surname, birthDate, phoneNumber;
            cout << "Введите фамилию: ";
            cin >> surname;
            cout << "Введите дату рождения (дд.мм.гггг): ";
            cin >> birthDate;
            cout << "Введите номер телефона: ";
            cin >> phoneNumber;
            database.addStudent(surname, birthDate, phoneNumber);
            break;
        }
        case 2: {
            string surname;
            cout << "Введите фамилию студента для удаления: ";
            cin >> surname;
            if (database.removeStudent(surname)) {
                cout << "Студент " << surname << " успешно удален\n";
                database.displayAllStudents();
            }
            else {
                cout << "Студента " << surname << " нет в БД\n";
            }
            break;
        }
        case 3: {
            string surname;
            cout << "Введите фамилию студента для поиска: ";
            cin >> surname;
            Student* foundStudent = database.findStudentBySurname(surname);
            if (foundStudent != nullptr) {
                cout << "Студент найден: " << foundStudent->getSurname() << " " << foundStudent->getBirthDate() << " " << foundStudent->getPhoneNumber() << endl;
            }
            else {
                cout << "Студент не найден." << endl;
            }
            break;
        }
        case 4: {
            database.sortStudentsBySurname();
            cout << "Студенты отсортированы по фамилии." << endl;
            database.displayAllStudents();
            break;
        }
        case 5: {
            database.displayAllStudents();
            break;
        }
        case 0: {
            return 0;
        }
        default: {
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }
        }
    }

    return 0;
}
