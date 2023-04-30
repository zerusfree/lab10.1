#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateTXT(char* fname)  // ��������� ����� � �������� �����
{
	ofstream fout(fname);	 // ������� ���� ��� ������
	char ch;				 // ������� ����������� � �� ������������ ��������
	string s;				 // �������� ������������ �����
	do
	{
		cin.get();			 // ������� ����� ��������� � ��� �� ���� �������
		cin.sync();			 // "����� �����", ���� ��������� ���� ����� �����
		cout << "enter line: "; getline(cin, s); // ����� �����
		fout << s << endl;	 // �������� ���� � ����
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname)	 // ��������� ����� �� �����
{
	ifstream fin(fname);	 // ������� ���� ��� ����������
	string s;				 // ���������� �����
	while (getline(fin, s))  // ���� ����� ��������� �����
	{
		cout << s << endl;   // �������� ���� �� �����
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

	CreateTXT(fname); // ����� ����� ����� � ���������
	PrintTXT(fname); // ������ ���� ������� ����� �� �����

	if (AvailiableElements(fname)) {
		cout << "The file '" << fname << "' contains group of symbols \" AGA \" or \" OGO \" \n";
	}
	else {
		cout << "The file '" << fname << "' does not contain  group of symbols \" AGA \" or \" OGO \"\n";
	}

	return 0;
}