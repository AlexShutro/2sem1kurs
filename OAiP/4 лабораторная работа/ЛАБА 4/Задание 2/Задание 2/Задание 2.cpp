#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::min_element;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream inputFile("FileA.txt");
    std::ofstream outputFile("FileA.txt");

    std::vector<std::string> str_vector;
    std::string line;
    std::string word;
    std::string max_word;

    char str[100];

    gets_s(str);
    outputFile << str << endl;

    while (std::getline(inputFile, line, '\n'))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] != ' ')
            {
                word += line[i];
            }

            else
            {
                str_vector.push_back(word);
                word.clear();
            }
        }
    }
    inputFile.close();
    for (auto a : str_vector)
    {
        cout << a << '\t';
    }
    auto min_word = *min_element(str_vector.begin(), str_vector.end());
    cout << endl << min_word << endl;
}
