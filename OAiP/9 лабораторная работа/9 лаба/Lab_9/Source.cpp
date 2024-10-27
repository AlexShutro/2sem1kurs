#include <iostream>
#include <fstream>
using namespace std;

struct Address
{
	int data;
	Address* next;
	Address* prev;
};

int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. ���� �����" << endl;
	cout << "2. �������� �����" << endl;
	cout << "3. ����� �� �����" << endl;
	cout << "4. ���-�� ���������� ���������" << endl;
	cout << "5. �����" << endl;
	cout << "6. �����" << endl;
	cout << "7. ����������� ����� ������" << endl;
	cout << "8. ������������ ����� ������" << endl;
	cout << "9 - ���������� �������� ���������\n";
	cout << "10 - ������ �������� � ������(d3)\n";
	cout << endl;
	cout << "��� �����: ";
	cin >> c;
	return c;
}

// 13	countX (int x) � ������� �������� ����� ��������� ������ � �������� ��������� x.

int count(int data, Address** phead) {
	Address* t = *phead;
	int count = 0;
	while (t)
	{
		if (data==t->data) {
			count++;
		}
		t = t->next;
	}
		cout <<"���-�� ����� ���������: "<<count << endl;
	return count;
}


void insert(Address* e, Address** phead, Address** plast) //���������� � ����� ������
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

Address* setElement()      // �������� �������� � ���� ��� �������� � ���������� 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� �����: ";
	cin >> temp->data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(Address** phead, Address** plast)      //����� ������ �� �����
{
	Address* t = *phead;
	while (t)
	{
		cout << t->data << endl;
		t = t->next;
	}
	cout << "" << endl;
}

void find(int data, Address** phead)    // ����� ����� � ������
{
	Address* t = *phead;
	while (t)
	{
		if (data==t->data) break;
		t = t->next;
	}
	if (!t)
		cerr << "����� �� �������" << endl;
	else
		cout << t->data << endl;
}

void findMin(Address** phead) {
	Address* t = *phead;
	int min = INT16_MAX;
	while (t)
	{
		if (t->data < min) {
			min = t->data;
		}
		t = t->next;
	}
	cout << "����������� ����� ������: " << min;
}

void findMax(Address** phead) {
	Address* t = *phead;
	int max = INT16_MIN;
	while (t)
	{
		if (t->data > max) {
			max = t->data;
		}
		t = t->next;
	}
	cout << "������������ ����� ������: " << max;
}

void delet(int data, Address** phead, Address** plast)  // �������� �����
{
	struct Address* t = *phead;
	while (t)
	{
		if (data==t->data)  break;
		t = t->next;
	}
	if (!t)
		cerr << "����� �� �������" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "������� ������" << endl;
	}
}

int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  
			int data;
			cout << "������� �����: ";
			cin>>data;
			delet(data, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  
			int data;
			cout << "������� �����: ";
			cin >> data;
			count(data, &head);
		}
			  break;
		case 5: {	  
			int data;
			cout << "������� �����: ";
			cin >> data;
			find(data, &head);
		}
			  break;
		case 6:  exit(0);
		case 7: {
			findMin(&head);
			break;
		}
		case 8: {
			findMax(&head);
			break;
		}
		case 9: {
			system("cls");
			int number;
			cout << "������� ����� "; cin >> number;
			count(number, &head);
			system("pause");
			system("cls");
			break;
		}
		case 10:
		{
			system("cls");
			int kol;
			int lok;
			cout << "������� ����� ������� ������ �������� "; cin >> kol;
			cout << "������� ����� �� ������� ������ �������� "; cin >> lok;
			system("pause");
			system("cls");
			break;
		}
		default: exit(1);
		}
	}
	return 0;
}
void writeToFile(Address** phead)       //������ � ����
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	cout << "���������� � ����" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}

void readFromFile(Address** phead, Address** plast)          //���������� �� �����
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "�������� �� �����" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "������ ��������� ������" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}


