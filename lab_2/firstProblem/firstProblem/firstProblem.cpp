#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

class Aeroflot {
    private:
        int flightNumber;
        string departurePoint;
        string destinationPoint;
        string arrivalTime;
        string departureTime;
        int registrationSection;

    public:
        Aeroflot(int flightNum, const string& departurePt, const string& destinationPt, const string& arrivalT, const string& departureT, int registrationSec)
            : flightNumber(flightNum), departurePoint(departurePt), destinationPoint(destinationPt),
            arrivalTime(arrivalT), departureTime(departureT), registrationSection(registrationSec) {}

        int getFlightNumber() const { return flightNumber; }
        string getDeparturePoint() const { return departurePoint; }
        string getDestinationPoint() const { return destinationPoint; }
        string getArrivalTime() const { return arrivalTime; }
        string getDepartureTime() const { return departureTime; }
        int getRegistrationSection() const { return registrationSection; }
};

bool sortByDestination(const Aeroflot& a, const Aeroflot& b) {
    return a.getDestinationPoint() < b.getDestinationPoint();
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    setlocale(LC_ALL, "ru");

    vector<Aeroflot> flights; 

    int numFlights;
    cout << "Введите количество рейсов: ";
    cin >> numFlights;

    for (int i = 0; i < numFlights; ++i) {
        int flightNumber;
        string departurePoint, destinationPoint, arrivalTime, departureTime;
        int registrationSection;

        cout << "Введите информацию про " << i + 1 << "-й рейс\n";
        cout << "Введите номер рейса: ";
        cin >> flightNumber;
        cout << "Введите пункт отправления: ";
        cin >> departurePoint;
        cout << "Введите пункт назначения: ";
        cin >> destinationPoint;
        cout << "Введите время прибытия: ";
        cin >> arrivalTime;
        cout << "Введите время отправления: ";
        cin >> departureTime;
        cout << "Введите номер секции для регистрации: ";
        cin >> registrationSection;

        flights.emplace_back(flightNumber, departurePoint, destinationPoint, arrivalTime, departureTime, registrationSection);
    }

    sort(flights.begin(), flights.end(), sortByDestination);

    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| # Рейса | Пункт отправления | Пункт назначения | Время прибытия | Время отправления | Секция регистрации |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

    bool flightsFound = false;

    for (const auto& flight : flights) {
        cout << "| " << flight.getFlightNumber() << "      | " << flight.getDeparturePoint() << "         | " << flight.getDestinationPoint() << "           | "
            << flight.getArrivalTime() << "         | " << flight.getDepartureTime() << "         | " << flight.getRegistrationSection() << "                  |" << endl;
        flightsFound = true;
    }

    if (!flightsFound) {
        cout << "Нет рейсов для отображения." << endl;
    }

    cout << "------------------------------------------------------------------------------------------------------------" << endl;

    return 0;
}
