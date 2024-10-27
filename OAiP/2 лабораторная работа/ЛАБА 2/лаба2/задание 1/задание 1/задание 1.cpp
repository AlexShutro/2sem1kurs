#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <ranges>

using std::cout; using std::cin; using std::endl;

struct birthday_bytes
{
	unsigned int week_day : 3;
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
};

enum Gender
{
	мужской = 1,
	женский,
	вертолёт
};

struct citizen
{
	std::string name_surname;
	std::string adres;
	birthday_bytes birthday_date;
	Gender gender;

	friend std::ostream& operator<<(std::ostream& os, std::vector<citizen>& citizens);
};

std::ostream& operator<<(std::ostream& os, const citizen& citizens)
{
	os << citizens.name_surname << '\n' << citizens.adres << '\n' << citizens.birthday_date.day << '.' << citizens.birthday_date.month << '.' << citizens.birthday_date.year << '\n';
	switch (citizens.gender)
	{
	case 1: os << "мужской";
		break;
	case 2: os << "женский";
		break;
	case 3: os << "боевой вертолёт";
		break;
	}
	return os;
}

void include_citizens(std::vector<citizen>& guesses, int& n)
{
	for (int i = 0; i < n; i++)
	{
		int count = NULL;
		int gender = NULL;
		int day = NULL, month = NULL, year = NULL;
		cout << endl << "ФИО: "; cin >> guesses[i].name_surname;
		cout << endl << "Адрес проживания: "; cin >> guesses[i].adres;
		cout << endl << "Дата рождения:"; cin >> day; cin >> month; cin >> year;
		guesses[i].birthday_date.day = day;
		guesses[i].birthday_date.month = month;
		guesses[i].birthday_date.year = year;
		cout << endl << "Гендер: мужской - 1, женский - 2, боевой вертолёт - 3 "; cin >> gender;
		guesses[i].gender = (Gender)gender;
	}
}

void find_citizens(std::vector<citizen>& citizens)
{
	int year = NULL; cout << "Введите дату рождения, по которому будет осуществляться поиск: "; cin >> year;
	auto output = citizens | std::ranges::views::filter([&](const auto& v) {return v.birthday_date.year == year; });
	for (auto a : output)
	{
		cout << a << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = NULL;
	cout << "Количество горожан: "; cin >> n;
	std::vector<citizen> citizens(n);
	include_citizens(citizens, n);

	for (auto a : citizens)
	{
		cout << a << endl;
	}
	cout << endl;
	find_citizens(citizens);
}
