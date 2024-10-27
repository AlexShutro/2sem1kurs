#include"Header.h"

using namespace std;

int menu() {
	int userChoose;
	cout<< "1 - �������� ������� � ������\n"
		<< "2 - ������� ���e�� �� �����\n"
		<< "3 - ����� ������� � ������\n"
		<< "4 - �������� ������\n"
		<< "5 - �������� �� ��������\n"
		<< "6 - ������� �� �����\n"
		<< "7 - ����� �������� ������ ������(main)\n"
		<< "8 - ���������� ������� ������(d1)\n"
		<< "9 - ���������� ������ ������ � ������� ����������(d2)\n"
		<< "10 - ����� �������� ������� ������(d3)\n"
		<< "11 - ���������� ������ ������(d4)\n"
		<< "0 - ����� �� ���������\n";

	cout << "����: "; cin >> userChoose;
	return userChoose;
}

int main() {
	setlocale(LC_ALL, "rus");
	Tree tree;
	do{
		system("cls");
		switch (menu())
		{
		case 1:
		{
			system("cls");
			int data;
			cout << "������� �����: "; cin >> data;
			tree.push(data);
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			tree.PrintTree(tree.root, 0);
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			int data;
			cout << "������� �����: "; cin >> data;
			tree.FindElem(data, tree.root);
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			tree.DelTree(tree.root);
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			int data;
			cout << "������� �����: "; cin >> data;
			tree.DelElem(tree.root, data);
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			tree.ReadFromFile();
			system("pause");
			break;
		}		
		case 7: 
		{
			system("cls");
			int sum = 0;
			cout << "����� ������ ������ �����: " << tree.sumOfAllHeads(tree.root, sum) << endl;
			system("pause");
			break;
		}
		case 8: 
		{
			system("cls");
			int num = 0;
			cout << "���������� ������� ������ �����: " << tree.countOfLeafs(tree.root, num) << endl;
			system("pause");
			break;
		}
		case 9: 
		{
			system("cls");
			int count = 0;
			cout << "���������� ������ � ������� ����������: " << tree.countOfEvenKeys(tree.root, count) << endl;
			system("pause");
			break;
		}
		case 10: 
		{
			system("cls");
			int sum = 0;
			cout << "����� ������� ������ �����: " << tree.sumOfLeafs(tree.root, sum) << endl;
			system("pause");
			break;
		}
		case 11: 
		{
			system("cls");
			cout << "���������� ������ ������ �����: " << tree.NodeCount(tree.root) << endl;
			system("pause");
			break;
		}
		case 0: 
		{
			return 0;
		}
		default:
			break;
		}
	} while (true);
	return 0;
}