#include"Header.h"

using namespace std;

int menu() {
	int userChoose;
	cout<< "1 - Добавить элемент в дерево\n"
		<< "2 - Вывести дерeво на экран\n"
		<< "3 - Найти элемент в дереве\n"
		<< "4 - Очистить дерево\n"
		<< "5 - Удаление по значению\n"
		<< "6 - Чтениие из файла\n"
		<< "7 - Сумма значений вершин дерева(main)\n"
		<< "8 - Количество листьев дерева(d1)\n"
		<< "9 - Количество вершин дерева с чётными значениями(d2)\n"
		<< "10 - Сумма значений листьев дерева(d3)\n"
		<< "11 - Количество вершин дерева(d4)\n"
		<< "0 - Выход из программы\n";

	cout << "Ввод: "; cin >> userChoose;
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
			cout << "Введите число: "; cin >> data;
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
			cout << "Введите число: "; cin >> data;
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
			cout << "Введите число: "; cin >> data;
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
			cout << "Сумма вершин дерева равна: " << tree.sumOfAllHeads(tree.root, sum) << endl;
			system("pause");
			break;
		}
		case 8: 
		{
			system("cls");
			int num = 0;
			cout << "Количество листьев дерева равно: " << tree.countOfLeafs(tree.root, num) << endl;
			system("pause");
			break;
		}
		case 9: 
		{
			system("cls");
			int count = 0;
			cout << "Количество вершин с чётными значениями: " << tree.countOfEvenKeys(tree.root, count) << endl;
			system("pause");
			break;
		}
		case 10: 
		{
			system("cls");
			int sum = 0;
			cout << "Сумма листьев дерева равна: " << tree.sumOfLeafs(tree.root, sum) << endl;
			system("pause");
			break;
		}
		case 11: 
		{
			system("cls");
			cout << "Количество вершин дерева равно: " << tree.NodeCount(tree.root) << endl;
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