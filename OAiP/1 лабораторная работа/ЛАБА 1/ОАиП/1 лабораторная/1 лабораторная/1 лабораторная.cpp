#include <iostream>                    
# define str_len 30                               
# define size 30  
using namespace std;
void enter_new();
void del();
void change();
void out();
struct ABITURIENT
{
	char name[str_len];
    char adress;
	char specialnost[5];
	int konkurs;
	int oplata;
};
struct ABITURIENT list_of_abiturient[size];
struct ABITURIENT bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для изменения записи" << endl;
	cout << "4-для вывода записи(ей)" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  change();  break;
		case 4:  out();	break;
		}
	} while (choice != 5);
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Номер строки:  ";
		cout << current_size + 1;
		cout << endl << "Наименование вуза:  " << endl;
		cin >> list_of_abiturient[current_size].name;
		cout << "Адрес:  " << endl;
		cin >> list_of_abiturient[current_size].adress;
		cout << "Перечень специальностей:  " << endl;
		cin >> list_of_abiturient[current_size].specialnost;
		cout << "Конкурс прошлого года по каждой специальности: " << endl;
		cin >> list_of_abiturient[current_size].konkurs;
		cout << "Размер оплаты при договорном обучении: " << endl;
		cin >> list_of_abiturient[current_size].oplata;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_abiturient[de1] = list_of_abiturient[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list_of_abiturient[i] = bad;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void change()
{
	int n, per;
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите: " << endl;
		cout << "1-для изменения наименования вуза" << endl;
		cout << "2-для изменения адреса" << endl;
		cout << "3-для изменения специальности" << endl;
		cout << "4-для изменения конкурса" << endl;
		cout << "5-для изменения оплаты" << endl;
		cout << "6-конец\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "Новая наименование вуза: ";
			cin >> list_of_abiturient[n - 1].name;   break;
		case 2: cout << "Новый адрес: ";
			cin >> list_of_abiturient[n - 1].adress; break;
		case 3: cout << "Новая специальность: ";
			cin >> list_of_abiturient[n - 1].specialnost; break;
		case 4: cout << "Новый конкурс прошлого года по каждой специальности: ";
			cin >> list_of_abiturient[n - 1].konkurs;   break;
		case 5: cout << "Новый размер оплаты при договорном обучении: ";
			cin >> list_of_abiturient[n - 1].oplata; break;

		}
	} while (per != 6);
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << "Наименование вуза: ";
		cout << list_of_abiturient[n - 1].name << endl;
		cout << "Адрес: ";
		cout << list_of_abiturient[n - 1].adress << endl;
		cout << "Специальность: ";
		cout << list_of_abiturient[n - 1].specialnost << endl;
		cout << "Конкурс прошлого года по каждой специальности: ";
		cout << list_of_abiturient[n - 1].konkurs << endl;
		cout << "Размер оплаты при договорном обучении: ";
		cout << list_of_abiturient[n - 1].oplata << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Наименование вуза: ";
			cout << list_of_abiturient[i].name << endl;
			cout << "Адрес: ";
			cout << list_of_abiturient[i].adress << endl;
			cout << "Специальность: ";
			cout << list_of_abiturient[i].specialnost << endl;
			cout << "Конкурс прошлого года по каждой специальности: ";
			cout << list_of_abiturient[i].konkurs << endl;
			cout << "Размер оплаты при договорном обучении: ";
			cout << list_of_abiturient[i].oplata << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
