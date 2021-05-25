#include "Array.h"
#include <iostream>
#include <time.h>
#include <stdexcept>
#include <exception>
#include <cmath>

using namespace std;

typedef Array::value_type* TArray;

int main()
{
	int n;
	cout << "n= "; cin >> n;
	Array c = Array(n);

	srand((unsigned)time(NULL));
	Array::value_type A = -50;
	Array::value_type B = 50;

	TArray a = new Array::value_type[n];
	for (int i = 0; i < n; i++)
		a[i] = A + rand() % int(B - A + 1);

	Array::iterator l = const_cast<Array::iterator>(c.begin());
	for (int j = 0; j < n; j++, l++)
		*l = a[j];
	cout << c;
	cout << "Max = " << c.Max() << endl;
	cout << "Last element = " << c[n - 1] << endl;
	c.Add();
	cout << c;
	cout << "Sum = " << c.Sum() << endl;
	c.push_back(c.Sum());
	c.push_back(c.Average_Abs());
	cout << c;
}