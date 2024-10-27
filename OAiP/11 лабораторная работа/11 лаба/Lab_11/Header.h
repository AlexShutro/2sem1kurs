#pragma once
#include<iostream>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#define DEEP 8
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int _val):data(_val),left(nullptr),right(nullptr){}
};

struct Tree {
	Node* root;

	Tree():root(nullptr){}

	bool isEmpty(){
		return root == nullptr;
	}

	void push(int data,Node* branch=nullptr) {
		if (isEmpty()) {
			root=new Node(data);
			return;
		}
		Node* prev=root;// prev - ������
		if (branch != nullptr) { //��� �������� ������� �� ������ �� ��������� ������
			 prev = branch;
		}
		Node* ptr = new Node(data);
		if (ptr->data >= prev->data ) {// c��������� � �������� �� ������� ����� � ������
			if (prev->right == nullptr) {
				prev->right = ptr;	
				return;
			}
			else {
				push(data, prev->right);
			}
		}
		else if (ptr->data < prev->data) {
			if (prev->left == nullptr) {
				prev->left = ptr;	
				return;
			}
			else {
				push(data, prev->left);
			}
		}
		else {
			cout << "Error in push" << endl;
			return;
		}
	}

	void PrintTree(Node* ptr, int level) {
		if (isEmpty()) {
			cout << "The tree is empty!"<<endl;
			return;
		}
		if (ptr) {
			PrintTree(ptr->left, level + 1);
			for (int i = 0; i < level; i++) {
				cout << "   ";
			}
			cout << ptr->data << endl;
			PrintTree(ptr->right, level + 1);
		}
	}

	void FindElem(int searched, Node* branch = nullptr) {
		if (isEmpty()) {
			cout << "The tree is empty!" << endl;
			return;
		}
		if (branch == nullptr) {
			branch = root;
		}
		if (branch == root) {
			cout << "Root->";
		}
		if (searched == branch->data) {
			cout << "������� ������" << endl;
			return;
		}
		else if (searched >= branch->data) {
			if (branch->right == nullptr) {
				cout << "\033[1;31m ��e���� �� ������!  \033[0m" << endl;
				return; 
			}
			else {
				cout << "R->";
				FindElem(searched, branch->right);
			}
		}
		else {
			if (branch->right == nullptr) {
				cout << "\033[1;31m ��e���� �� ������!  \033[0m" << endl;
				return;
			}
			else {
				cout << "L->";
				FindElem(searched, branch->left);
			}
		}
	}

	bool DelTree(Node* branch) {
		if (branch != nullptr) {
			DelTree(branch->left);
			DelTree(branch->right);
			delete branch;
			return false;
		}
		root = nullptr;
		return true;
	}

	Node* FindMinEl(Node* branch) {
		if (branch->left == nullptr) {
			return branch;
		}
		else {
			FindMinEl(branch->left);
		}
	}

	bool DelElem(Node* branch, int ToDel,Node* prev=nullptr,char arrow='e') {
		if (isEmpty()) {
			cout << "The tree is empty!" << endl;
			return true;
		}
		if (ToDel == root->data) {
			cout << "������ ������� ������!" << endl;
			return true;
		}
		if (branch->data == ToDel && branch->left == nullptr && branch->right == nullptr) { //���� � �������� ��� �����������
			if (arrow == 'l') {
				prev->left = nullptr;
			}
			else if (arrow == 'r') {
				prev->right = nullptr;
			}
			delete branch;
			return true;
		}
		if (branch->data == ToDel && branch->left != nullptr && branch->right == nullptr) { //���� � �������� ���� ��������� ������ �����
			branch = branch->left;
			if (arrow == 'l') {
				prev->left = branch;
			}
			else if (arrow == 'r') {
				prev->right = branch;
			}
			return true;
		}
		if (branch->data == ToDel && branch->right != nullptr && branch->left == nullptr) { //���� � �������� ���� ��������� ������ ������
			branch = branch->right;
			if (arrow == 'l') {
				prev->left = branch;
			}
			else if (arrow == 'r') {
				prev->right = branch;
			}
			return true;
		}
		if (branch->data == ToDel && branch->right != nullptr && branch->left != nullptr) {//�������� ����� ����� ������ �������� ��  ����� � ������
			Node* nodeToChangeParent = FindMinEl(branch->right);// ������� ����������� �������
			nodeToChangeParent->left = branch->left;// ������ ����� ����� ���������� ������������ ��������
			Node* sevenodeToChangeRigth = nodeToChangeParent->right;// ��������� ������ ����� ������������
			if (nodeToChangeParent == branch->right) {
				nodeToChangeParent->right = sevenodeToChangeRigth;//��������� ����������� ����� ������������ ����������
			}
			else {
				nodeToChangeParent->right = branch->right;//��������� ������ ����� ���������� � �����������
				nodeToChangeParent->right->left = sevenodeToChangeRigth;//��������� ����������� ����� ������������ ����������
			}
			branch = nodeToChangeParent;//�������� ��������� �����������
			
			if (arrow == 'l') {
				prev->left = branch;
			}
			else if (arrow == 'r') {
				prev->right = branch;
			}
			return true;
		}


		//����� ���������� �������� � ������
		if (ToDel<branch->data) {
			if (branch->left != nullptr) {
				DelElem(branch->left, ToDel, branch,'l');
				return true;
			}
			else {
				cout << "������� �������� � ������ ���!" << endl;
				return true;
			}
		}
		if (ToDel>branch->data) {
			if (branch->right != nullptr) {
				DelElem(branch->right, ToDel, branch,'r');
				return true;
			}
			else {
				cout << "������� �������� � ������ ���!" << endl;
				return true;
			}
		}
		return false;
	}

	void ReadFromFile() {
		string filename;
		cout << "������� ��� �����: "; cin >> filename;
		ifstream fin(filename);

		while (!fin.eof()) {
			int data;
			fin >> data;
			push(data);
		}
	}

	int sumOfAllHeads(Node* root, int& sum) {
		if (root != nullptr) {
			if (root->left != nullptr && root->right != nullptr)
			{
				sum += root->data;
				sumOfAllHeads(root->left, sum);
				sumOfAllHeads(root->right, sum);
			}
		}
		return sum;
	}

	int countOfLeafs(Node* node, int& num) {
		if (node)
		{
			if (node->left == nullptr && node->right == nullptr)
				num++;
			countOfLeafs(node->left, num);
			countOfLeafs(node->right, num);
		}
		return num;
	}

	int countOfEvenKeys(Node* root, int& count) {
		if (root != nullptr) {
			if (root->left != nullptr && root->right != nullptr)
			{
				if (root->data % 2 == 0) {
					count++;
				}
				else {
					sumOfAllHeads(root->left, count);
					sumOfAllHeads(root->right, count);
				}
			}
		}
		return count;
	}

	int sumOfLeafs(Node* root, int& sum) {
		if (root != nullptr) {
			sumOfLeafs(root->left, sum);
			sumOfLeafs(root->right, sum);
			if (root->left == nullptr && root->right == nullptr)
			{
				sum += root->data;
			}
		}
		return sum;
	}

	int NodeCount(Node* node)
	{
		if (node->left == nullptr && node->right == nullptr)
			return 0;
		int left, right;
		if (node->left != nullptr)
			left = NodeCount(node->left);
		else
			left = 0;
		if (node->right != nullptr)
			right = NodeCount(node->right);
		else
			right = 0;

		return left + right + 1;
	}

};