#include<iostream>

using namespace std;

struct Train{
	int TrainNumber;
	char Destination[32];
	char ArrivingTime[5];
	char EndTime[5];
};

int main() {
	setlocale(LC_ALL, "rus");
	system("chcp>1251");


	return 0;
}