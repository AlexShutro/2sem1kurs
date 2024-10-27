#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout; using std::cin; using std::endl;

int main()
{
    std::ifstream fileA("fileA.txt");
    std::ofstream fileB("fileB.txt");

    std::string line;
    std::vector<int> individual_numbers;

    while (std::getline(fileA, line, '\n'))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] != ' ')
            {
                individual_numbers.push_back(line[i] - '0');
            }
        }
        fileA.close();
    }
    std::ranges::sort(individual_numbers);
    for (int i = 0; i < individual_numbers.size() - 2; i++)
    {
        if (individual_numbers[i] == individual_numbers[i + 1] && individual_numbers[i] == individual_numbers[i + 2])
            fileB << individual_numbers[i] << '\t';
    }
}

