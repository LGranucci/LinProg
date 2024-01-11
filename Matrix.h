#include <iostream>
using namespace std;

class Matrice
{
	int n; //righe
	int m; //colonne
	float **matrice;
	float **trasposed;

public:
	Matrice(int, int);
    ~Matrice()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] matrice[i];
        }
        delete[] matrice;
    }
    Matrice(const Matrice&);
    void aggiornaTrasposta();
	void stampa();
	void assegna(float *vett, int size);
	float *mColonna(float *vett, int size);
	float *mRiga(float *vett, int size);
	Matrice *operator=(Matrice &matr);
	float *operator*(const Matrice &mat);
};


