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
	cout << size << endl;
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

float *Matrice::mColonna(float *vettore, int size)
{
	if (size != m)
	{
		cout << "non possibile" << endl;
		return vettore;
	}
	float *result = new float[m];
	float aux = 0;
	for (int i = 0; i < n; i++)
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

float *Matrice::mRiga(float *vett, int size)
{

	if (size != n)
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

Matrice *Matrice::operator=(Matrice &matr)
{
	Matrice *b = new Matrice(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; i++)
		{
			b->matrice[i][j] = matrice[i][j];
		}
	}
	return b;
}

// FIXME
float *Matrice::operator*(const Matrice &mat)
{
	if (this->n != mat.m)
	{
		cout << "Errore: dimensione scorretta\n";
		return nullptr;
	}

	float *res = new float[this->m * mat.n];

	for (int i = 0; i < this->m * mat.n; i++)
	{
		res[i] = 0;
	}

	for (int k = 0; k < this->m; k++)
	{
		for (int i = 0; i < mat.n; i++)
		{
			for (int j = 0; j < this->n; j++)
			{
				res[k * mat.n + i] +=
					this->matrice[k][j] * mat.matrice[j][i];
			}
		}
	}
	return res;
}
