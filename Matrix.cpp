#include <iostream>
#include "Matrix.h"
using namespace std;

Matrice::Matrice(int a, int b)
{

		n = a; // righe
		m = b; // colonne
		cout << n << m << endl;
		matrice = new float *[n];

		for (int i = 0; i < n; i++)
		{
			matrice[i] = new float[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrice[i][j] = 0;
			};
		};

		if (n == m)
		{
			trasposed = new float *[n];
			for (int i = 0; i < m; i++)
			{
				trasposed[i] = new float[m];
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					matrice[j][i] = 0;
				};
			};
		}
}

Matrice::Matrice(const Matrice &m1) //DA TESTARE
{
    this->n = m1.n;
    this->m = m1.m;
    this->matrice = new float*[m1.n];
    for (int i = 0; i < m1.n; i++)
    {
        this->matrice[i] = new float[m1.m];
        for (int j = 0; j < m1.m; j++)
        {
            this->matrice[i][j] = m1.matrice[i][j];
        }
    }
    this->trasposed = new float*[m1.m];
    for (int i = 0; i < m; i++)
    {
        this->trasposed[i] = new float[m1.n];
    }
    this->aggiornaTrasposta();
}

void Matrice::aggiornaTrasposta() //DA TESTARE
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            trasposed[i][j] = matrice[j][i];
        }
    }
}

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
			matrice[i][j] = vett[i * m + j];
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
	float *result = new float[n];
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
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
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

float *Matrice::operator*(const Matrice &mat)
{
	if (this->m != mat.n)
	{
		cout << "Errore: dimensione scorretta\n";
		return nullptr;
	}

	float *res = new float[this->n * mat.m];

	for (int i = 0; i < this->n * mat.m; i++)
	{
		res[i] = 0;
	}

	for (int k = 0; k < this->n; k++)
	{
		for (int i = 0; i < mat.m; i++)
		{
			for (int j = 0; j < this->m; j++)
			{
				res[k * mat.m + i] +=
					this->matrice[k][j] * mat.matrice[j][i];
			}
		}
	}
	return res;
}

