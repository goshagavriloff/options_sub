#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
struct fou
{
	int day;
	int year;
	string month;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	int min;
	int date_size = 4;
	fou mass1[100],mass2[100],mass3[100];


	ofstream fout("data_1.txt");
	for (int i = 0; i < date_size; i++)
	{
		cout << "введите день ";
		cin >> mass1[i].day;
		cout << "введите месяц ";
		cin >> mass1[i].month;
		cout << "введите год ";
		cin >> mass1[i].year;

	}


	fout << "день \t";
	
	for (int i = 0; i < date_size; i++)
	{
		int n = mass1[i].day;
		fout << n;
		fout << " ";
		fout << "\t";

	}
	fout.write((char*)&"\n", sizeof("\n"));
	
	fout << "месяц \t";
	for (int i = 0; i < date_size; i++)
	{
		string n = mass1[i].month;
		fout << n;
		fout << " ";
		fout << "\t";
	}
	fout.write((char*)&"\n", sizeof("\n"));
	fout << "год \t";
	min = 30000;
	for (int i = 0; i < date_size; i++)
	{
		int n = mass1[i].year;
		fout << n;
		fout << " ";
		fout << "\t";

		if (mass1[i].year < min)
		{
			min = mass1[i].year;
		}
	}
	cout << "минимальный год: " << min<< '\n';
	fout.close();


	string line;
	ifstream myfile("data_1.txt");
	int lineCount = 1;
	if (myfile.is_open())
	{
		while (getline(myfile, line))//getline(myfile, line)
		{
			vector<string> commands;
			string buffer = "";
			for (int i = 0; i < line.size(); i++) {
				if (line[i] != '\t') {      //  сплиттер
					buffer += line[i];
				}
				else {
					commands.push_back(buffer);
					buffer = "";
				}
			}


			
			for (int i = 1; i < commands.size(); i++) {
				
				

				if (lineCount == 1) {
					 mass2[i - 1].day= std::stoi( commands[i]) ;
				}

				if (lineCount == 2) {
					mass2[i - 1].month = commands[i];
				}

				if (lineCount == 3) {
					mass2[i - 1].year = std::stoi(commands[i]);
				}
			}
			
			lineCount++;
			
		}
		myfile.close();

		for (int i = 0; i < date_size; i++)
		{
			cout << mass2[i].day << "-" << mass2[i].month <<"-"<< mass2[i].year << '\n';
		}




	}

	else cout << "Unable to open file";


	ofstream fout_2("data_2.txt", ios::binary | ios::out);
	fout_2.write((char*)&"день", sizeof("день"));

	for (int i = 0; i < 5; i++)
	{
		int n = mass1[i].day;
		fout_2.write((char*)&n, sizeof(n));
		fout_2.write(" \t", sizeof(" \t"));

	}
	fout_2.write((char*)&"\n", sizeof("\n"));

	fout_2.write((char*)&"месяц ", sizeof("месяц "));
	for (int i = 0; i < 5; i++)
	{
		

		char* n = new char[mass1[i].month.length() + 1];
		strcpy_s(n, mass1[i].month.length() + 1, mass1[i].month.c_str());

		OemToAnsi(n, n);
		fout_2.write((char*)&n, sizeof(n));
		fout_2.write(" \t", sizeof(" \t"));
	}

	fout_2.write((char*)&"\n", sizeof("\n"));
	fout_2.write((char*)&"год ", sizeof("год "));
	for (int i = 0; i < 5; i++)
	{
		int n = mass1[i].year;
		fout_2.write((char*)&n, sizeof(n));
		fout_2.write(" \t", sizeof(" \t"));
	}
	fout_2.close();

	///вывод содержимого файла
	//const int M = sizeof(int);
	//ifstream f("data_2.txt", ios::binary);
	//int x;
	//char buff ;
	//while (f.read((char*)&x, M))
	//	std::cout.write(reinterpret_cast<const char*>(&x), sizeof(x));
	//cout << endl;
	//f.close();
	/// 



	string line_2;
	ifstream myfile_2("data_2.txt", ios::binary | ios::out);
	int lineCount_2 = 1;
	if (myfile_2.is_open())
	{
		while (getline(myfile_2, line))//getline(myfile, line)
		{
			vector<string> commands;
			string buffer = "";
			for (int i = 0; i < line.size(); i++) {
				if (line[i] != '\t') {      //  сплиттер
					buffer += line[i];
				}
				else {
					commands.push_back(buffer);
					buffer = "";
				}
			}



			for (int i = 1; i < commands.size(); i++) {



				if (lineCount == 1) {
					mass3[i - 1].day = std::stoi(commands[i]);
				}

				if (lineCount == 2) {
					mass3[i - 1].month = commands[i];
				}

				if (lineCount == 3) {
					mass3[i - 1].year = std::stoi(commands[i]);
				}
			}

			lineCount++;

		}
		myfile_2.close();

		for (int i = 0; i < date_size; i++)
		{
			cout << mass3[i].day << "-" << mass3[i].month << "-" << mass3[i].year << '\n';
		}




	}

	else cout << "Unable to open file";


}
