#include <iostream>
#include <fstream> 
#include <vector> 
#include <string> 

using std::cout; using std::cin; using std::endl;

void getVector(std::vector<double>& inputVector, std::ifstream& file)
{
    std::string numberString;
    int individualNumber;

    if (file)
    {

        while (std::getline(file, numberString, '\n'))
        {
            for (int i = 0; i < numberString.size(); i++)
            {
                if (numberString.at(i) != ' ')
                {
                    individualNumber = numberString.at(i) - '0';
                    inputVector.push_back(individualNumber);
                }
            }                
        }
    }
    else
    {
        cout << "input file cannot be openede" << endl;
    }
    file.close();
}

void createMatrix(double** matrix, std::vector<double>& count, int& n, int& m)
{
    n = count[0];
    m = (count.size() - 1) / count[0];
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++, k++)
        {
            if (k < count.size())
            {
                matrix[i][j] = count[k];
                cout << matrix[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

void multiMatrix(double** matrix_fA, double** matrix_fB, int& n, int& m, std::ofstream& outputFile)
{
    double** matrix_fC = new double* [n];
    double sum = NULL;
    for (int i = 0; i < n; i++)
    {
        matrix_fC[i] = new double[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix_fC[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                matrix_fC[i][j] += matrix_fA[i][k] * matrix_fB[k][j];
            }
            cout << matrix_fC[i][j] << "\t";
            outputFile << matrix_fC[i][j] << "\t";
        }
        cout << endl;
        outputFile << endl;
    }
}

int main()
{

    std::ifstream inputFile_fA("fA.txt");
    std::ifstream inputfile_fB("fB.txt");
    std::ofstream outputFile("fC.txt");

    std::vector<double> fA, fB;
    int n = NULL, m = NULL;

    getVector(fA, inputFile_fA);
    getVector(fB, inputfile_fB);

    double** matrix_fA = new double* [fA[0]];
    double** matrix_fB = new double* [fB[0]];

    createMatrix(matrix_fA, fA, n, m);
    cout << endl;
    createMatrix(matrix_fB, fB, n, m);
    cout << endl;
    multiMatrix(matrix_fA, matrix_fB, n, m, outputFile);

    return 0;
}