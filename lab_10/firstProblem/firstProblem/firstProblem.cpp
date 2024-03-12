
#include <iostream>

using namespace std;

class Canon {
public:
	static double p;

	static void getShootResult(int n) {
		double prob = 0;
		for (int i = 0; i < n; i++) {
			prob = getEstimateProbability(i);
			cout << "\nВероятность равна = " << prob << endl;
			if (prob < 1) {
				cout << "Промах! Цель не сбита\n";
			}
			else if (prob == 1) {
				cout << "Есть попадание! Цель уничтожена\n";
				break;
			}
		}
		cout << endl;
	}

	static double getEstimateProbability(int n) {
		return 1.0 - pow((1.0 - p), n);
	}

};

double Canon::p = 0;

int main() {
	setlocale(LC_ALL, "ru");

	cout.precision(15);

	double p;
	int n;
	cout << "Введите вероятность попадания (0 <= p <= 1): ";
	cin >> p;
	cout << "Введите количество выстрелов (n > 0): ";
	cin >> n;

	Canon::p = p;

	cout << "Результат стрельбы:\n";
	Canon::getShootResult(n);

	return 0;
}
