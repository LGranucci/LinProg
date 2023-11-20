#include "Matrix.h"
#include <iostream>
using namespace std;
void Matrice::stampa()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << " " << matrice[i][j];
		}
		cout << endl;
	}
};