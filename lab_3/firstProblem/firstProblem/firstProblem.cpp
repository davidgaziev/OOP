#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Timer {
private:
    int seconds;

public:
    Timer(int secs) : seconds(secs) {}

    Timer(const string& timeStr) {
        int seconds = 0;
        sscanf_s(timeStr.c_str(), "%d", &seconds);
        this->seconds =  seconds;
    }

    Timer(int mins, int secs) {
        this->seconds = mins * 60 + secs;
    }

    void run() {
        clock_t start = clock();
        while (seconds > 0) {
            if ((clock() - start) / CLOCKS_PER_SEC == 1) {
                start = clock();
                cout << "Осталось времени: " << seconds << " секунд.\n";
                seconds--;
            }
        }
        cout << "*ЗВОНОК!* *ЗВОНОК!* *ЗВОНОК!*\a\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Timer timer1(10);
    Timer timer2("5"); 
    Timer timer3(1, 5);

    //cout << "Таймер 1  int (10 сек):" << endl;
    //timer1.run();

    //cout << "\nТаймер 2 string (5 сек):" << endl;
    //timer2.run();

    cout << "\nТаймер 3 int int (1 мин 30 сек):" << endl;
    timer3.run();

    return 0;
}
