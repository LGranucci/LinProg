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

float *Matrice::operator*(float *vettore)
{
	int size = sizeof(vettore) / sizeof(vettore[0]);
	if (size != n)
	{
		cout << "non possibile" << endl;
		return vettore;
	}
	float *result = new float[m];
	float aux = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < size; j++)
		{
			aux += matrice[i][j] * vettore[j];
		}
		result[i] = aux;
		aux = 0;
	}
	return result;
}

float *Matrice::mRiga(float *vett)
{
	int size = sizeof(vett) / sizeof(vett[0]);
	if (size != m)
	{
		cout << "not possible" << endl;
		return vett;
	}
	float *result = new float[n];
	float aux = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			aux += matrice[j][i] * vett[j];
		}
		result[i] = aux;
		aux = 0;
	}
	return result;
}