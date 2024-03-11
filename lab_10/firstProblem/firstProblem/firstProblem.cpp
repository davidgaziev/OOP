
#include <iostream>

using namespace std;

class Canon {
public:
	static int p;

	static void getShootResult(int n) {
		cout << p << endl;
		for (int i = 0; i < n; i++) {
			if (p == 0) {
				cout << "\nПромах! Цель не сбита";
			}
			else if (p == 1) {
				cout << "\nЕсть попадание! Цель уничтожена";
				break;
			}
		}
		cout << endl;
		
	}

	static double getEstimateProbability(int n) {
		return 1.0 - pow((1.0 - p), n);
	}

};

int Canon::p = 0;

int main() {
	setlocale(LC_ALL, "ru");

	int p;
	int n;
	cout << "Введите вероятность попадания (0 <= p <= 1): ";
	cin >> p;
	cout << "Введите количество выстрелов (n > 0): ";
	cin >> n;

	Canon::p = p;

	cout << "Результат стрельбы: ";
	Canon::getShootResult(n);

	double estimatedProbability = Canon::getEstimateProbability(n);

	cout << "Оценочное значение вероятности поражения цели: " << estimatedProbability << endl;
	return 0;
}
