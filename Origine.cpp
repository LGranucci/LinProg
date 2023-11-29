#include <iostream>
#include "Matrix.cpp"

using namespace std;

int main()
{
	Matrice a(2, 2);
	float v[4] = {2, 1, 1, 0};
	a.assegna(v, 4);

	a.stampa();
	float vect[2] = {3, 4};
	float *res = a.mPerVettore(vect, 2);
	for (int i = 0; i < 2; i++)
	{
		cout << res[i] << " ";
	}

	return 0;
};
