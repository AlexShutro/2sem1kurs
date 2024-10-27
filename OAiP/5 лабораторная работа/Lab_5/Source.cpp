#include<iostream>
#include<string>
#define MaxNumberOfStudents 16

using namespace std;

struct Student {
	string name;
	string surname;
	int StartYear;
	string faculty;
	int group;
	float MiddleMark;
}student;

enum FACULTIES { PAM = 1, FIT, HTAT };

void delStud(Student* arr, string surname, int& length) {
	int pos=0;
	for (int i = 0; i <= length; i++) {
		if (arr[i].surname == surname) {
			pos = i;
		}
	}
	if (pos == 0) return;
	for (int i = pos; i < length; i++) {
		arr[i].name = arr[i + 1].name;
		arr[i].surname = arr[i + 1].surname;
		arr[i].StartYear = arr[i + 1].StartYear;
		arr[i].faculty = arr[i + 1].faculty;
		arr[i].group = arr[i + 1].group;
		arr[i].MiddleMark = arr[i + 1].MiddleMark;
	}
	length--;
}

void FindByMiddle(Student* arr, float mark, int& length) {
	bool isfound = false;
	for (int i = 1; i <= length; i++) {
		if (arr[i].MiddleMark == mark) {
			cout << "-----------------------------------------" << endl;
			cout << "Имя: " << arr[i].name << endl;
			cout << "Фамилия: " << arr[i].surname << endl;
			cout << "Дата поступления: " << arr[i].StartYear << endl;
			cout << "Факультет: " << arr[i].faculty << endl;
			cout << "Группа: " <<arr[i].group << endl;
			cout << "Средний балл: " <<arr[i].MiddleMark << endl;
			cout << "-----------------------------------------" << endl;
			isfound = true;
		}
	}
	if (!isfound) {
		cout << "Студента с таким баллом не обнаруженно" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int LEN = 1;
	int& length = LEN;
	Student* students = new Student[MaxNumberOfStudents];
	do {
		int Choose;
		cout << "Выберите действие: " << endl
			<< "1 <--- Добавить студента" << endl
			<< "2 <--- Показать всех студентов" << endl
			<< "3 <--- Удалить студента" << endl
			<< "4 <--- Поиск студента по среднему баллу" << endl
			<< "5 <--- Выход" << endl
			<<"Ввод: ";
		cin >> Choose;
		switch (Choose)
		{
		case 1: {
			system("cls");
			int fac;
			cout << "Имя: "; cin >> students[length].name;
			cout << "Фамилия: "; cin >> students[length].surname;
			cout << "Дата поступления: "; cin >> students[length].StartYear; cin.ignore();
			cout << "Факультет (1-PAM, 2-FIT, 3-HTAT): "; cin >> fac;
			switch (fac) {
			case FACULTIES::PAM: {
				students[length].faculty = "PAM";
				break;
			}
			case FACULTIES::FIT: {
				students[length].faculty = "FIT";
				break;
			}
			case FACULTIES::HTAT: {
				students[length].faculty = "HTAT";
				break;
			}
			default: {
				break;
			}
			}
			cout << "Группа: "; cin >> students[length].group; cin.ignore();
			cout << "Средний балл: "; cin >> students[length].MiddleMark;
			length++;
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			for (int i = 1; i < length; i++) {
				cout << "-----------------------------------------" << endl;
				cout << "Имя: " << students[i].name << endl;
				cout << "Фамилия: " << students[i].surname << endl;
				cout << "Дата поступления: " << students[i].StartYear << endl;
				cout << "Факультет: " << students[i].faculty << endl;
				cout << "Группа: " << students[i].group << endl;
				cout << "Средний балл: " << students[i].MiddleMark << endl;
				cout << "-----------------------------------------" << endl;
			}
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			string surname;
			cout << "Введите фамилию студента которого хотите удалить: "; cin >> surname;
			delStud(students, surname, length);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			float mark;
			cout << "Введите средний балл студента: "; cin >> mark;
			FindByMiddle(students, mark, length);
			system("pause");
			break;
		}
		case 5: {
			delete[]students;
			return 0;
			break;
		}
		default:
			cout << "Попробуйте еще раз!" << endl;
			break;
		}
	} while (true);
	delete[]students;
	return 0;
}

//#include<iostream>
//#include<string>
//#include<fstream>
//#define MAXARR 12
//
//using namespace std;
//
//struct State{
//	string name;
//	string capital;
//	int people;
//	float size;
//	string PRsurname;
//};
//
//union help {
//	int choose;
//	float size;
//	char symbol;
//} buf;
//
//void menu() {
//	cout << "Выберите действие: " << endl
//		<< "1 <--- Добавить государство" << endl
//		<< "2 <--- Просмотреть государства" << endl
//		<< "3 <--- Найти государство" << endl
//		<< "4 <--- Записать в Файл" << endl
//		<< "5 <--- Прочитать Файл" << endl
//		<< "6 <--- Выйти" << endl<<
//		"Ввод:"; cin >> buf.choose;
//}
//
//void addState(State* arr,int& length) {
//	length++;
//	cout << "Название страны: "; cin >> arr[length].name;
//	cout << "Название столицы: "; cin >> arr[length].capital;
//	cout << "Кол-во населения: "; cin >> arr[length].people;
//	cout << "Площадь: "; cin >> arr[length].size;
//	cout << "Фамилия президента: "; cin >> arr[length].PRsurname;
//}
//
//void ShowStates(State* arr, int& length) {
//	for (int i = 0; i < length; i++) {
//		cout << "---------------------------------------" << endl;
//		cout << "Название страны: "<<arr[i].name<<endl;
//		cout << "Название столицы: "<< arr[i].capital<<endl;
//		cout << "Кол-во населения: "<< arr[i].people<<endl;
//		cout << "Площадь: "<<arr[i].size<<endl;
//		cout << "Фамилия президента: "<< arr[i].PRsurname<<endl;
//		cout << "---------------------------------------" << endl;
//	}
//}
//
//void FindState(State* arr, int& length,string name) {
//	for (int i = 1; i <= length;i++) {
//		if (name == arr[i].name) {
//			cout << "---------------------------------------" << endl;
//			cout << "Название страны: " << arr[i].name << endl;
//			cout << "Название столицы: " << arr[i].capital << endl;
//			cout << "Кол-во населения: " << arr[i].people << endl;
//			cout << "Площадь: " << arr[i].size << endl;
//			cout << "Фамилия президента: " << arr[i].PRsurname << endl;
//			cout << "---------------------------------------" << endl;
//		}
//	}
//}
//
//void WriteFile(State* arr, int& length, string filename) {
//	ofstream fout(filename);
//	for (int i = 1; i <= length; i++) {
//		fout  << arr[length].name << endl;
//		fout  << arr[length].capital << endl;
//		fout  << arr[length].people << endl;
//		fout  << arr[length].size << endl;
//		fout  << arr[length].PRsurname << endl;
//	}
//	fout.close();
//}
//
//void ReadFile(State* arr, int& length, string filename) {
//	ifstream fin(filename);
//	for (int i = length; !fin.eof()&&length<MAXARR ; i++) {
//		cout << "<----------------->";
//		length++;
//		fin >> arr[i].name;
//		fin >> arr[i].capital;
//		fin >> arr[i].people;
//		fin >> arr[i].size;
//		fin >> arr[i].PRsurname;
//		if (fin.eof()) {
//			break;
//		}
//	}
//	fin.close();
//}
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	State* arr = new State[MAXARR];
//	int Ln = 0;
//	int& length = Ln;
//	do {
//		menu();
//		switch (buf.choose)
//		{
//		case 1: {
//			system("cls");
//			addState(arr, length);
//			system("pause");
//			break;
//		}
//		case 2: {
//			system("cls");
//			ShowStates(arr, length);
//			system("pause");
//			break;
//		}
//		case 3: {
//			system("cls");
//			string name;
//			cout << "Введите название страны: "; cin >> name;
//			FindState(arr, length, name);
//			system("pause");
//			break;
//		}
//		case 4: {
//			system("cls");
//			WriteFile(arr, length, "output.txt");
//			system("pause");
//			break;
//		}
//		case 5: {
//			system("cls");
//			ReadFile(arr, length, "input.txt");
//			system("pause");
//			break;
//		}
//		case 6: {
//			system("cls");
//			delete[]arr;
//			system("pause");
//			return 0;
//			break;
//		}
//
//		default:
//			break;
//		}
//	} while (true);
//	delete[]arr;
//	return 0;
//}