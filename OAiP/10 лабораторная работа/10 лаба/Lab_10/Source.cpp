#include<iostream>
#include<math.h>
using namespace std;

// 13 вариант
unsigned int dnx(unsigned int n, unsigned int x) {
	unsigned int count = 1;
	if (n % x == 0 && x > 1) {
		count = dnx(n, x - 1) + 1;
	}
	else if (n % x != 0 && x > 1) {
		count = dnx(n, x - 1);
	}
	return count;

}

int main() {
	setlocale(LC_ALL, "rus");
	unsigned int input;
	cout << "Введите положительное число: "; cin >> input;
	cout << "Количество делителей: " << dnx(input, 100) << endl;
	return 0;
}
