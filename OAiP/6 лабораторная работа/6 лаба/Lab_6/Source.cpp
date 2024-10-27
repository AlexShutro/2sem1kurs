#include"list.h"
using namespace std;

int menu() {
	int UserChoose;
	cout << "�������� ���������� ���������:" << endl
		<< "\t1 <--- �������� ������� � ������" << endl
		<< "\t2 <--- �������� ������� � �����" << endl
		<< "\t3 <--- ������� ������" << endl
		<< "\t4 <--- ����� �������" << endl
		<< "\t5 <--- 13" << endl
		<< "\t6 <--- 14" << endl
		<< "\t7 <--- 15" << endl
		<< "\t8<--- 16" << endl
		<< "\t9 <--- ������� �������" << endl
		<< "\t10 <--- ������ � ����" << endl
		<< "\t11 <--- ������ �� �����" << endl
		<< "\t12 <--- �������� �����" << endl
		<< "\t13 <--- �����" << endl
		<< "����: ";
	cin >> UserChoose;
	if (cin.fail()) {
		system("cls");
		cout << "\033[1;31m ���������� ��� ���! \033[0m" << endl;
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
			cout << "������� �����: "; cin >> Num;
			list.shift(Num);
			break;
		}
		case 2: {
			system("cls");
			int Num;
			cout << "������� �����: "; cin >> Num;
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
			cout << "������� ����� ������� ������ �������: "; cin >> Num;
			list.deleteNode(Num);
			system("pause");
			break;
		}
		case 10: {
			system("cls");
			string filename;
			cout << "������� �������� �����: ";
			cin >> filename;
			list.WriteFile(filename);
			system("pause");
			break;
		}
		case 11: {
			system("cls");
			string filename;
			cout << "������� �������� �����: ";
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
			cout << "\033[1;31m �������! \033[0m";
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