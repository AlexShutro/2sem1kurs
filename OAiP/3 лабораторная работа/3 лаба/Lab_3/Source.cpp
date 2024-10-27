#include<iostream>
#include<fstream>
#include<string>
#define BUFSIZE 256
#define KILOBAIT 1024
using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	system("chcp>1251");
	FILE* ReadFile;
	ifstream fin("ReadFile.txt");
	int FILESIZE;
	for (FILESIZE = 0; !fin.eof(); FILESIZE++)
		fin.get();
	fin.close();
	fin.open("ReadFile.txt");
	char* buffer=new char[FILESIZE];
	buffer[FILESIZE-1]='\0';
	fin.read(buffer, FILESIZE);
	cout << buffer;

	int NumberOfLines = 1;
	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '\n') {
			NumberOfLines++;
		}
	}
	
	char **ArrOfStr = new char * [NumberOfLines];
	for (int i = 0; i <= NumberOfLines; i++) {
		ArrOfStr[i] = new char[KILOBAIT];
	}

	for (int i = 0, k = 0,z=0; ; i++) {
		if (buffer[i] == '\0') {
			ArrOfStr[k][z] = '\0';
			break;
		}
		if (buffer[i] == '\n') {
			ArrOfStr[k][z] = '\0';
			k++;
			z = 0;
			continue;
		}
		ArrOfStr[k][z] = buffer[i];
		z++;
	}
	
	for (int i = 0; buffer[i] != '\0'; i++) {

	}
	for (int i = 0; i < NumberOfLines; i++) {
		cout << ArrOfStr[i];
	}

	FILE* Output;
	ofstream fout("Output.txt");
	int CountOfWords = 1;
	for (int i = 0; i <= NumberOfLines; i++) {
		for (int k = 0; ArrOfStr[i][k] != '\0'; k++) {
			if (ArrOfStr[i][k] == ' ') {
				CountOfWords++;
			}
			if (CountOfWords == 2) {
				cout << ArrOfStr[i] << "--------------->" << strlen(ArrOfStr[i]);
				fout.write(ArrOfStr[i], strlen(ArrOfStr[i]));
				fout << '\n';
				CountOfWords = 1;
				break;
				
			}
		}
	}
	fout.close();
	for (int i = 0; i < NumberOfLines; i++) {
	  delete[] ArrOfStr[i];
    }
	delete[]buffer;
	return 0;
}