#include <iostream>
using namespace std;

class Matrice
{
	int n;
	int m;
	float **matrice;

public:
	Matrice(int a, int b)
	{
		n = a; // righe
		m = b; // colonne
		cout << n << m << endl;
		matrice = new float *[n];
		for (int i = 0; i < m; i++)
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
	}
	void stampa();
	void assegna(float *vett, int size);
	float *mPerVettore(float *vett, int size);
	float *mVettoreRiga(float *vett, int size);
};
