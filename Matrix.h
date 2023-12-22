#include <iostream>
using namespace std;

class Matrice
{
	int n; //righe
	int m; //colonne
	float **matrice;
	float **trasposed;

public:
	Matrice(int a, int b)
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
	void stampa();
	void assegna(float *vett, int size);
	float *mColonna(float *vett, int size);
	float *mRiga(float *vett, int size);
	Matrice *operator=(Matrice &matr);
	float *operator*(const Matrice &mat);
};

