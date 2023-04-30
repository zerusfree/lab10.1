#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateTXT(char* fname)  // створення файлу з введених рядків
{
	ofstream fout(fname);	 // відкрили файл для запису
	char ch;				 // відповідь користувача – чи продовжувати введення
	string s;				 // введений користувачем рядок
	do
	{
		cin.get();			 // очищуємо буфер клавіатури – щоб не було символу
		cin.sync();			 // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; getline(cin, s); // ввели рядок
		fout << s << endl;	 // записали його у файл
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname)	 // виведення файлу на екран
{
	ifstream fin(fname);	 // відкрили файл для зчитування
	string s;				 // прочитаний рядок
	while (getline(fin, s))  // поки можна прочитати рядок
	{
		cout << s << endl;   // виводимо його на екран
	}
	cout << endl;
}

bool AvailiableElements(const string& filename)
{
	ifstream fin(filename);
	int count = 0;

	if (!fin.is_open())
	{
		cout << "Error: Could not open file!" << endl;
		return false;
	}

	string line;
	while (getline(fin, line))  // read each line from the file
	{
		for (size_t i = 0; i < line.length(); i++)
		{
			if (line[i] == 'A' && line[i + 1] == 'G' && line[i + 2] == 'A' || line[i] == 'O' && line[i + 1] == 'G' && line[i + 2] == 'O')
			{
				fin.close();
				return true;
			}
		}
	}
	fin.close();
	return false;
}

int main()
{
	char fname[100];

	cout << "enter file name: "; cin >> fname;

	CreateTXT(fname); // ввели рядки файлу з клавіатури
	PrintTXT(fname); // вивели вміст першого файлу на екран

	if (AvailiableElements(fname)) {
		cout << "The file '" << fname << "' contains group of symbols \" AGA \" or \" OGO \" \n";
	}
	else {
		cout << "The file '" << fname << "' does not contain  group of symbols \" AGA \" or \" OGO \"\n";
	}

	return 0;
}