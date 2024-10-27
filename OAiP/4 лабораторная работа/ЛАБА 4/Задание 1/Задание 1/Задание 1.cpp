#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using std::cout; using std::cin; using std::endl;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream fileA("fileA.txt");
    std::ofstream fileB("fileB.txt");

    std::string line;
    std::vector<std::string> str;

    int count = NULL;

    if (fileA.is_open())
    {
        while (std::getline(fileA, line))
        {
            if (line[0] == 'A')
            {
                str.push_back(line);
                count++;
            }
        }
        fileA.close();
        for (auto a : str)
        {
            fileB << a << '\n';
        }
        fileB << count << '\n';
    }
    else
    {
        cout << "file not open";
    }
}
