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
void Matrice::assegna(float *vett, int size)
{
	if (size != n * m)
	{
		cout << "size vettore sbagliato" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrice[i][j] = vett[i * n + j];
		}
	}
}

float *Matrice::mPerVettore(float *vettore, int size)
{
	if (size != m)
	{
		cout << "non possibile" << endl;
		return nullptr;
	}
	float *result = new float[m];
	float aux = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < m; j++)
		{
			aux += matrice[i][j] * vettore[j];
		}
		result[i] = aux;
		aux = 0;
	}
	return result;
}