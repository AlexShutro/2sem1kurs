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
	cout << "1. Ввод числа" << endl;
	cout << "2. Удаление числа" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Кол-во одинаковых элементов" << endl;
	cout << "5. Поиск" << endl;
	cout << "6. Выход" << endl;
	cout << "7. Минимальное число списка" << endl;
	cout << "8. Максимальное число списка" << endl;
	cout << "9 - Количество заданных элементов\n";
	cout << "10 - Замена элемента в списке(d3)\n";
	cout << endl;
	cout << "Ваш выбор: ";
	cin >> c;
	return c;
}

// 13	countX (int x) – функция подсчёта числа элементов списка с заданным значением x.

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
		cout <<"Кол-во таких элементов: "<<count << endl;
	return count;
}


void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
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

Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите число: ";
	cin >> temp->data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->data << endl;
		t = t->next;
	}
	cout << "" << endl;
}

void find(int data, Address** phead)    // Поиск числа в списке
{
	Address* t = *phead;
	while (t)
	{
		if (data==t->data) break;
		t = t->next;
	}
	if (!t)
		cerr << "число не найдено" << endl;
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
	cout << "Минимальное число списка: " << min;
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
	cout << "Максимальное число списка: " << max;
}

void delet(int data, Address** phead, Address** plast)  // Удаление числа
{
	struct Address* t = *phead;
	while (t)
	{
		if (data==t->data)  break;
		t = t->next;
	}
	if (!t)
		cerr << "число не найдено" << endl;
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
		cout << "Элемент удален" << endl;
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
			cout << "Введите число: ";
			cin>>data;
			delet(data, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  
			int data;
			cout << "Введите число: ";
			cin >> data;
			count(data, &head);
		}
			  break;
		case 5: {	  
			int data;
			cout << "Введите число: ";
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
			cout << "Введите число "; cin >> number;
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
			cout << "Введите число которое хотите заменить "; cin >> kol;
			cout << "Введите число на которое хотите заменить "; cin >> lok;
			system("pause");
			system("cls");
			break;
		}
		default: exit(1);
		}
	}
	return 0;
}
void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}

void readFromFile(Address** phead, Address** plast)          //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}


