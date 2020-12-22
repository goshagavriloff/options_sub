#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>
using namespace std;



template <typename T1>
T1  setMass(T1 a, int size)
{

		for (int i = 0; i < size; i++) {
			a.push_back(rand() % 100 + 1);
		}
	
	
	return a;
	
}



template <typename T>
void  printMass(T a)
{
	for (int n : a)
		std::cout << n << "\t";
}

std::list<double> myList;
std::vector<float> myRequest;

int main()
{
	

	setlocale(LC_ALL, "Rus");
	cout << "ДО: \n ";
	int i;
	int size = 0;
	double m;
	cout << "введите размерность массива ";
	cin >> size;




	myList = setMass(myList, size);
	printMass(myList);
	cout << "\n ПОСЛЕ \n";
	for (double n : myList) {
		myRequest.push_back(n- myList.back());
	}
	myRequest.pop_back();
	printMass(myRequest);

}
