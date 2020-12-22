#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;
struct fout
{
	int day;
	int year;
	char month[10];
}mass1[100];

int main()
{
	setlocale(LC_ALL, "Rus");
	int min;
	ofstream fout("data.txt",ios::binary|ios::out);
	for (int i = 0; i < 5; i++)
	{
		cout << "введите день ";
		cin >> mass1[i].day;
		cout << "введите мес€ц ";
		cin >> mass1[i].month;
		cout << "введите год ";
		cin >> mass1[i].year;

	}


//	fout.write((char*)&"день", sizeof ("день"));
	for (int i = 0; i < 5; i++)
	{
		int n = mass1[i].day;
		fout.write((char*)&n, sizeof(n));
		fout.write(" \t", sizeof(" \t"));

	}
	fout.write((char*)&"\n", sizeof("\n"));
//	fout.write((char*)&"мес€ц ", sizeof("мес€ц "));
	for (int i = 0; i < 5; i++)
	{
		char* n = mass1[i].month;
		OemToAnsi(n, n);
		fout.write((char*)&n, sizeof(n));
		fout.write(" \t", sizeof(" \t"));
	}
	fout.write((char*)&"\n", sizeof("\n"));
//	fout.write((char*)&"год ", sizeof("год "));
	min = 30000;
	for (int i = 0; i < 5; i++)
	{
		int n = mass1[i].year;
		fout.write((char*)&n, sizeof(n));
		fout.write(" \t", sizeof(" \t"));

		if (mass1[i].year < min)
		{
			min = mass1[i].year;
		}
	}
	cout << "минимальный год: " << min;
	fout.close();
}
