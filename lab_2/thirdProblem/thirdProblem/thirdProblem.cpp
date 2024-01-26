#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char d) : data(d), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(char item) {
        Node* newNode = new Node(item);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    char top() const {
        if (!isEmpty()) {
            return topNode->data;
        }
        // Возвращаем значение по умолчанию, если стек пуст
        return '\0';
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }
};

// Функция для разделения состава на два направления
void separateTrain(const Stack& train, Stack& directionA, Stack& directionB) {
    Stack tempTrain = train; // Создаем копию состава

    while (!tempTrain.isEmpty()) {
        char wagon = tempTrain.top();
        tempTrain.pop();
        if (wagon == 'A') {
            directionA.push(wagon);
        }
        else if (wagon == 'B') {
            directionB.push(wagon);
        }
    }
}

// Функция для вывода содержимого стека
void printStack(const Stack& stack) {
    Stack tempStack = stack; // Создаем копию стека

    while (!tempStack.isEmpty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    Stack train;
    Stack directionA;
    Stack directionB;

    char choice;
    cout << "Хотите ввести состав с клавиатуры? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Введите состав: (A - вагон типа A, B - вагон типа B, X - конец ввода)" << endl;
        char wagon;
        while (true) {
            cin >> wagon;
            if (wagon == 'X' || wagon == 'x') {
                break;
            }
            train.push(wagon);
        }
    }
    else {
        ifstream file("train.txt");
        if (!file) {
            cerr << "Ошибка открытия файла." << endl;
            return 1;
        }

        char wagon;
        while (file >> wagon) {
            train.push(wagon);
        }

        file.close();
    }

    // Разделяем состав на два направления
    separateTrain(train, directionA, directionB);

    // Выводим составы на два направления
    cout << "Направление A:" << endl;
    printStack(directionA);

    cout << "Направление B:" << endl;
    printStack(directionB);

    return 0;
}
