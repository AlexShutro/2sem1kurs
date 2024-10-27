#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#define MaxAmountOfTrains 32
using namespace std;

struct Train {
	string TrainNumber;
	string Destination;
	string StartTime;
	string EndTime;
};



void GetData(Train *arr,int &length) {
	int ID;
	cout << "Максимальный ID в системе->" << length-1;
	cout << "ID	Поезда:"; cin >> ID; cout << ID << endl;
	cout << "-------------------------------------\n";
	cout << "Введите номер поезда: "; cin>>arr[ID].TrainNumber; cin.ignore();
	cout << "Введите пункт назначения: "; cin >> arr[ID].Destination;
	cout << "Введите время отправления(XX:XX): "; cin >> arr[ID].StartTime; cin.ignore();
	cout << "Введите время прибытия(XX:XX): "; cin >> arr[ID].EndTime;	cin.ignore();
	cout << "-------------------------------------\n";
	length++;
}
void ShowData(Train* arr, int &length) {

	for (int i = 0; i < length; i++) {
		cout << "ID	Поезда:" << i << endl;
		cout << "-------------------------------------\n";
		cout << "Номер поезда: " << arr[i].TrainNumber << endl;
		cout << "Пункт назначения: " << arr[i].Destination << endl;
		cout << "Время отправления: " << arr[i].StartTime << endl;
		cout << "Время прибытия: " << arr[i].EndTime << endl;
		cout << "-------------------------------------\n";
	}
	
}
void DeleteTrain(Train* arr, int& length) {
	int ID;
	cout << "Максимальный ID в системе->" << length-1;
	cout << "ID	Поезда:"; cin >> ID; cout << ID << endl;
	for (int i = ID; i < length-1; i++) {
		arr[i].TrainNumber = arr[i + 1].TrainNumber;
		arr[i].Destination = arr[i + 1].Destination;
		arr[i].StartTime = arr[i + 1].StartTime;
		arr[i].EndTime = arr[i + 1].EndTime;
	}
	length--;
}
void FindTrain(Train* arr, int& length) {
	string destin;
	cout << "Введите название конечного пункта на Eng: "; cin >> destin;
	for (int i = 0; i < length; i++) {
		if (destin == arr[i].Destination) {
			cout << "ID поезда с конечным пуктом " << destin << ":\033[1;31m---->" << i<<"<----\033[0m" << endl;
			return;
		}
	}
	cout << "Не удалось обнаружить :(\n";
	return;
}
void WriteInFile(Train* arr,const char filename[],int &l) {
	ofstream fout(filename);
	for (int i = 0; i < l; i++) {
		fout << arr[i].TrainNumber << '\n';
		fout << arr[i].Destination << '\n';
		fout << arr[i].StartTime << '\n';
		fout << arr[i].EndTime << '\n';
	}
	fout.close();
}
void ReadFromFile(Train* arr, const char filename[], int &l) {
	ifstream fin(filename);
	
	for (int i = l; i < 32; i++) {
		getline(fin, arr[i].TrainNumber,'\n');
		getline(fin, arr[i].Destination, '\n');
		getline(fin, arr[i].StartTime, '\n');
		getline(fin, arr[i].EndTime, '\n');
		if (fin.eof()) {
			break;
		}
		l++;
	}
	fin.close();
	
}

int main() {
	setlocale(LC_ALL, "rus");
	system("chcp>1251");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	



	Train* Trains = new Train[MaxAmountOfTrains];
	int Length = 0;
	int& LengthOfTrains = Length;

	//Берем данные из файла
	do {
		int choose;
		cout << "Введите функциию работы программы:\n\
			1-Добавить поезд\n\
			2-Простмотреть данные о поездах\n\
			3-Найти поезд по месту следования\n\
			4-Удалить поезд\n\
			5-Добавить поезда из файла\n\
			6-Записать поезда в файл\n\
			7-Очистить экран\n\
			8-Выход\n";
		cout << "Ввод: "; cin >> choose; 
		switch (choose) {
		case 1:
			GetData(Trains, LengthOfTrains);
			break;
		case 2:
			ShowData(Trains,LengthOfTrains);
			break;
		case 3:
			FindTrain(Trains, LengthOfTrains);
			break;
		case 4:
			DeleteTrain(Trains, LengthOfTrains);
			break;
		case 5: 
			ReadFromFile(Trains, "input.txt",LengthOfTrains);
			break;
		case 6:
			WriteInFile(Trains, "output.txt", LengthOfTrains);
			break;
		case 7:
			system("cls");
			break;
		case 8:
			delete[]Trains;
			return 0;
			break;
		default:
			cout << "Нет такого варианта! Попробуйте еще раз...";
			break;
		}
	} while (true);

	delete[]Trains;
	return 0;
}