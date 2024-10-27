#include"list.h"
using namespace std;

int menu() {
	int UserChoose;
	cout << "Выберите функционал программы:" << endl
		<< "\t1 <--- Добавить элемент в начало" << endl
		<< "\t2 <--- Добавить элемент в конец" << endl
		<< "\t3 <--- Вывести список" << endl
		<< "\t4 <--- Найти элемент" << endl
		<< "\t5 <--- 13" << endl
		<< "\t6 <--- 14" << endl
		<< "\t7 <--- 15" << endl
		<< "\t8<--- 16" << endl
		<< "\t9 <--- Удалить элемент" << endl
		<< "\t10 <--- Запись в файл" << endl
		<< "\t11 <--- Чтение из файла" << endl
		<< "\t12 <--- очистить экран" << endl
		<< "\t13 <--- Выход" << endl
		<< "Ввод: ";
	cin >> UserChoose;
	if (cin.fail()) {
		system("cls");
		cout << "\033[1;31m Попробуйте еще раз! \033[0m" << endl;
		cin.clear();
		cin.ignore(INT16_MAX, '\n');
		system("cls");
		menu();
	}
	return UserChoose;
}

int main() {
	setlocale(LC_ALL, "rus");
	NumberList list;
	do {
		switch (menu()) {
		case 1: {
			system("cls");
			int Num;
			cout << "Введите число: "; cin >> Num;
			list.shift(Num);
			break;
		}
		case 2: {
			system("cls");
			int Num;
			cout << "Введите число: "; cin >> Num;
			list.push(Num);
			break;
		}
		case 3: {
			system("cls");
			list.ShowInfo();
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			list.FindNumber();
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			list.GetSum13();
			system("pause");
			break;
		}
		case 6: {
			system("cls");
			list.GetSum8();
			system("pause");
			break;
		}
		case 7: {
			system("cls");
			list.GetSum14();
			system("pause");
			break;
		}
		case 8: {
			system("cls");
			list.GetSum3();
			system("pause");
			break;
		}
		case 9: {
			system("cls");
			int Num;
			cout << "Введите число которое хотите удалить: "; cin >> Num;
			list.deleteNode(Num);
			system("pause");
			break;
		}
		case 10: {
			system("cls");
			string filename;
			cout << "Введите название файла: ";
			cin >> filename;
			list.WriteFile(filename);
			system("pause");
			break;
		}
		case 11: {
			system("cls");
			string filename;
			cout << "Введите название файла: ";
			cin >> filename;
			list.ReadFile(filename);
			system("pause");
			break;
		}
		case 12: {
			system("cls");
			break;
		}
		case 13: {
			system("cls");
			cout << "\033[1;31m Спасибо! \033[0m";
			return 0;
			break;
		}
		default: {
			break;
		}
		}
	}while(true);

	return 0;
}