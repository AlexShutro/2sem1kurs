#pragma once
#include<iostream>
#include<fstream>

using namespace std;
//Создать список, содержащий элементы целого типа.
//Найти сумму отрицательных двухзначных элементов 
//или выдать сообщение, что таких элементов нет. 
struct Node {
	int number;
	Node* next;
	Node(int newNumber) :number(newNumber), next(nullptr) {}
};

struct NumberList {
	Node* first;
	Node* last;
	NumberList() :first(nullptr), last(nullptr) {}

	bool IsEmpty() {
		return first == nullptr;
	}

	void shift(int newNumber) {
		Node* ptr = new Node(newNumber);
		if (IsEmpty()) {
			first = ptr;
			last = ptr;
			return;
		}
		ptr->next = first;
		first = ptr;
	}

	void push(int newNumber) {
		Node* ptr = new Node(newNumber);
		if (IsEmpty()) {
			first = ptr;
			last = ptr;
			return;
		}
		last->next = ptr;
		last = ptr;
	}

	void ShowInfo() {
		if (IsEmpty()) {
			return;
		}
		Node* ptr = first;
		do {
			cout << ptr->number<<endl;
			ptr = ptr->next;
		} while (ptr);
	}

	void RemoveFirst() {
		if (IsEmpty()) return;
		Node* ptr = first;
		first = ptr->next;
		delete ptr;
	};

	void RemoveLast() {
		if (IsEmpty()) return;
		if (first == last) {
			RemoveFirst();
			return;
		}
		Node* ptr = first;
		while (ptr->next != last) ptr = ptr->next;
		ptr->next = nullptr;
		delete last;
		last = ptr;
	};

	void deleteNode(int Num) {
		if (IsEmpty()) return;
		if (first->number == Num) {
			RemoveFirst();
			return;
		}
		else if (last->number == Num) {
			RemoveLast();
			return;
		}
		Node* slow = first;
		Node* fast = first->next;
		while (fast && fast->number != Num) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			cout << "\033[1;31m Такого числа нет!  \033[0m" << endl;
			return;
		}
		slow->next = fast->next;
		delete fast;
	}

	void ReadFile(string filename) {
		ifstream fin(filename);
		Node* ptr = first;
		int Num;
		while (!fin.eof()) {
			fin >> Num;

			push(Num);
		}
		fin.close();
	}

	void WriteFile(string filename) {
		Node* ptr = first;
		ofstream fout(filename);
		while (ptr) {
			fout << ptr->number << '\n';
			ptr = ptr->next;
		}
		fout.close();
	}

	int FindNumber() {
		if (IsEmpty()) return -1;
		int num;
		int pos = -1;
		cout << "Введите число кторое вы хотите найти: "; cin >> num;
		Node* ptr = first;

		while (ptr) {
			if (num == ptr->number) {
				cout << "Число: " << num <<endl
					<< "Находиться на позиции: " << pos + 1 << endl;
				return pos;
			}
			pos++;
			ptr = ptr->next;
		}
		return pos;
	}

	int GetSum13() {
		if (IsEmpty()) return -1;
		int sum=0;
		Node* ptr = first;

		while (ptr) {
			if (ptr->number <= -10 && ptr->number >= -99) {
				sum += ptr->number;
			}
			ptr = ptr->next;
		}

		if (sum == 0) {
			cout << "Таких чисел в списке нет!" << endl;
		}
		else {
			cout << "Cуммa отрицательных двухзначных элементов: " << sum << endl;
		}
		return sum;
	}

	int GetSum8() {
		if (IsEmpty()) return -1;
		int sum = 0;
		Node* ptr = first;

		while (ptr) {
			if (ptr->number < 0&&ptr->number%2==0) {
				sum += ptr->number;
			}
			ptr = ptr->next;
		}

		if (sum == 0) {
			cout << "Таких чисел в списке нет!" << endl;
		}
		else {
			cout << "Cуммa отрицательных элементов, кратных 2: " << sum << endl;
		}
		return sum;
	}

	int GetSum14() {
		if (IsEmpty()) return -1;
		int sum = 0;
		Node* ptr = first;

		while (ptr) {
			if (ptr->number < 0 && ptr->number % 5 == 0) {
				sum += ptr->number;
			}
			ptr = ptr->next;
		}

		if (sum == 0) {
			cout << "Таких чисел в списке нет!" << endl;
		}
		else {
			cout << "Cуммa отрицательных элементов, кратных 5: " << sum << endl;
		}
		return sum;
	}

	int GetSum3() {
		if (IsEmpty()) return -1;
		int sum = 0;
		Node* ptr = first;

		while (ptr) {
			if (ptr->number > 0 && ptr->number % 5 == 0) {
				sum += ptr->number;
			}
			ptr = ptr->next;
		}

		if (sum == 0) {
			cout << "Таких чисел в списке нет!" << endl;
		}
		else {
			cout << "Cуммa положительных элементов, кратных 5: " << sum << endl;
		}
		return sum;
	}
};
