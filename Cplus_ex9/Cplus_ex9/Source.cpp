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
			double b = (double)(rand()) / RAND_MAX * (size - 2) + 2;
			double c = rand() % 100 + 1;
			double d = (i % 2 == 0) ? b : c;
			a.push_back(d);
		}
	
	
	return a;
	
}



template <typename T>
void  printMass(T a)
{
	for (double n : a){
		if (fabs(n - (int)n)> 0) {
			printf("%1.10f\t", n);
		}
		else {
			printf("%1.0f\t", n);
		}
		
	}
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
