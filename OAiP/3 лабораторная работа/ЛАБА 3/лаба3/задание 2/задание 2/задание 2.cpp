#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout; using std::cin; using std::endl;

int main()
{
    std::ifstream inputFile("f.txt");
    std::ofstream outputFile("g.txt");

    std::vector<int> numbers;
    std::vector<int> positive;
    std::vector<int> negative;

    std::string line;
    int individualNumber;

    if (inputFile.is_open() != 0)
    {
        while (std::getline(inputFile, line, '\n'))
        {
            for (int i = 0; i < line.size() - 2; i++)
            {
                if (line.at(i) == '-' && (line.at(i + 1) != ' ' && line.at(i + 2) != ' '))
                {
                    individualNumber = -((line[i + 1] - '0') * 10 + (line[i + 2] - '0'));
                    i += 2;
                    numbers.push_back(individualNumber);
                }
                else if (line.at(i) != ' ' && line.at(i + 1) != ' ')
                {
                    individualNumber = (line[i] - '0') * 10 + (line[i + 1] - '0');
                    numbers.push_back(individualNumber);
                }
            }
            inputFile.close();
        }
        std::sort(numbers.begin(), numbers.end(), [](const auto& v1, const auto& v2) {return v1 > v2; });
        auto dist_first_negative = std::distance(numbers.begin(), std::find_if(numbers.begin(), numbers.end(), [](const auto& v) {return v < 0; }));
        for (int i = 0; i < numbers.size(); i++)
        {
            if (i < dist_first_negative)
            {
                positive.push_back(numbers[i]);
            }
            else
            {
                negative.push_back(numbers[i]);
            }
        }
        for (int i = 0, j = 0, k = 0, n = 5, n1 = 5; i < numbers.size() / 5; i++)
        {
            if (i % 2 == 0)
            {
                for (; j < n; j++)
                {
                    cout << negative[j] << '\t';
                }
                n += 5;
            }
            else
            {
                for (; k < n1; k++)
                {
                    cout << positive[k] << '\t';
                }
                n1 += 5;
            }
        }
    }
    else
    {
        cout << "file is not open";
    }
}