#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int _stateMenu;
int teachersScore = 0;
string fileName = "data.txt";

struct TEACHERS {
    string name;
    string spec;
    int index;
};

void Menu()
{
    cout << "Группы студентов(1)" << endl;
    cout << "Штат преподавателей(2)" << endl;
    cout << "Удалить преподавателя(3)" << endl;
    cout << "Добавить преподавателя(4)" << endl;
    cout << "Цена занятия(5)" << endl;
    cout << "Поиск по подстроке(6)" << endl;
    cout << "Изменить файл БД(7)" << endl;
    cout << "Выйти из программы(8)" << endl;
    cin >> _stateMenu;
}

void showTeachers(TEACHERS Teachers[], int n)
{
    cout << "              ШТАТ ПРЕПОДАВАТЕЛЕЙ            " << endl << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << Teachers[i].name << " ---- " << Teachers[i].spec << endl;
        cout << "---------------------------------------------" << endl;
    }
}

void findElement(TEACHERS Teachers[], int index)
{
    for (int i = 0; i < teachersScore; i++)
    {
        if (Teachers[i].index == index)
        {
            cout << Teachers[i].name << " ---- " << Teachers[i].spec << endl;
            cout << "---------------------------------------------" << endl;
        }
    }
}

void readData(TEACHERS Teachers[])
{
    ifstream dataBase(fileName);

    string str;
    int linesScore = 0;

    while (getline(dataBase, str))
    {
        linesScore++;
    }
    dataBase.close();

    ifstream dataBase2(fileName);

    teachersScore = linesScore / 2;

    for (int i = 0; i < teachersScore; i++)
    {
        string name;
        string spec;
        getline(dataBase2, name);
        getline(dataBase2, spec);

        Teachers[i].name = name;
        Teachers[i].spec = spec;
    }

    dataBase2.close();

    for (int i = 0; i < teachersScore; i++)
    {
        Teachers[i].index = i;
    }
}

void addData(string name[], string spec)
{
    ofstream dataBase(fileName, ios::app);

    dataBase << name[0] << " " << name[1] << endl;
    dataBase << spec << endl;
}

void deleteData(TEACHERS Teachers[], int index)
{
    ofstream dataBase(fileName);

    for (int i = index; i + 1 < teachersScore; i++) {
        Teachers[i] = Teachers[i + 1];
    }
    teachersScore--;

    for (int i = 0; i < teachersScore; i++)
    {
        dataBase << Teachers[i].name << endl;
        dataBase << Teachers[i].spec << endl;
    }

    dataBase.close();
}

void findString(TEACHERS Teachers[], string str)
{
    int n = 0;

    cout << endl;

    for (int i = 0; i < teachersScore; i++)
    {
        string s = Teachers[i].name;
        size_t pos = s.find(str);
        if (pos != string::npos)
        {
            cout << Teachers[i].name << endl;
            cout << "-----------------------------" << endl;
        }
        else
            n++;

        if (n == teachersScore)
        {
            cout << "Совпадений не найдено" << endl;
            cout << "-----------------------------" << endl;
        }

    }
}

void sortingBy(TEACHERS Teachers[], string method)
{
    TEACHERS temp;

    if (method == "FIO")
    {
        for (int i = 0; i < teachersScore - 1; i++)
        {
            if (Teachers[i].name > Teachers[i + 1].name)
            {
                temp = Teachers[i];
                Teachers[i] = Teachers[i + 1];
                Teachers[i + 1] = temp;
            }
        }
    }
    else {
        for (int i = 0; i < teachersScore - 1; i++)
        {
            if (Teachers[i].spec > Teachers[i + 1].spec)
            {
                temp = Teachers[i];
                Teachers[i] = Teachers[i + 1];
                Teachers[i + 1] = temp;
            }
        }
    }

    showTeachers(Teachers, teachersScore);
}

int searchBinary(TEACHERS Teachers[], int left, int right, string key)
{
    int midd = 0;
    while (1)
    {
        midd = (left + right) / 2;

        if (key < Teachers[midd].spec)
            right = midd - 1;
        else if (key > Teachers[midd].spec)
            left = midd + 1;
        else
            return midd;

        if (left > right)
            return -1;
    }
}



int main()
{
    setlocale(LC_ALL, "rus");
    Menu();

    int findIndex;

    string fio[2];
    string spec;
    string pod;
    string find;

    TEACHERS Teachers[50];

    readData(Teachers);

    while (_stateMenu != 8) {
        switch (_stateMenu)
        {
        case 1:
            system("cls");
            cout << "        ГРУППЫ СТУДЕНТОВ           " << endl << endl;
            cout << "-----------------------------------" << endl;
            cout << "1 группа ---- ИСИТ ---- 30 человек" << endl;
            cout << "-----------------------------------" << endl;
            cout << "2 группа ---- ПОИТ ---- 30 человек" << endl;



































                 cout << "-----------------------------------" << endl;
            cout << "3 группа ---- ПОИБМС ---- 30 человек" << endl;
            cout << "-----------------------------------" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        case 2:
            system("cls");
            readData(Teachers);

            showTeachers(Teachers, teachersScore);

            int choosedIndex;
            cout << "Введите действие(1): 1 - поиск, 2 - бинарный поиск, 3 - сортировка по ФИО, 4 - сортировка по кафедре 5 - выход: ";
            cin >> choosedIndex;

            switch (choosedIndex)
            {
            case 1:
                cout << "Введите индекс элемента: " << endl;
                cin >> findIndex;
                system("cls");
                findElement(Teachers, findIndex);
                system("pause");
                break;
            case 2:
            {
                system("cls");
                cout << "Введите кафедру: " << endl;
                cin >> find;
                system("cls");
                int indexElement = searchBinary(Teachers, 0, teachersScore, find);
                cout << Teachers[indexElement].name << " ------------ " << Teachers[indexElement].spec << endl;
                cout << "--------------------------------------------------" << endl;
                system("pause");
                break;
            }
            case 3:
                system("cls");
                sortingBy(Teachers, "FIO");
                system("pause");
                break;
            case 4:
                system("cls");
                sortingBy(Teachers, "SPEC");
                system("pause");
                break;
            case 5:
                system("cls");

                Menu();
                break;
            }



            break;
        case 3:
            int delIndex;
            system("cls");
            cout << "            УДАЛИТЬ ПРЕПОДАВАТЕЛЯ            " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "Введите номер элемента: " << endl;
            cin >> delIndex;
            deleteData(Teachers, delIndex);
            system("cls");
            cout << "Данные успешно удалены" << endl;
            system("pause");
            system("cls");
            Menu();

            break;
        case 4:
            system("cls");
            readData(Teachers);
            cout << "              ДОБАВИТЬ ПРЕПОДАВАТЕЛЯ             " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "Введите ФИО:" << endl;
            cin >> fio[0]; cin >> fio[1];
            system("cls");
            cout << "Введите кафедру преподавателя:" << endl;
            cin >> spec;
            addData(fio, spec);
            system("cls");
            cout << "Данные успешно добавлены" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        case 5:
            system("cls");
            cout << "                   ЦЕНЫ                     " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "Лекция---------------------------------100BYN" << endl;
            cout << "Лабораторная---------------------------150BYN" << endl;
            cout << "Практика-------------------------------120BYN" << endl;
            system("pause");
            system("cls");
            Menu();

            break;
        case 6:
            system("cls");
            cout << "Введите подстроку: ";
            cin >> pod;
            findString(Teachers, pod);
            system("pause");
            system("cls");
            Menu();

            break;
        case 7:
            system("cls");
            cout << "Введите файл с данными: ";
            cin >> fileName;
            system("cls");
            cout << "Название файла записано" << endl;
            system("pause");
            system("cls");
            Menu();

            break;
        default:
            system("cls");
            cout << "Неверно введен номер действия!" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }
    }
}

