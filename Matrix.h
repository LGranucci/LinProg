#ifndef MATRIX_HEADER
#define MATRIX_HEADER


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
    Matrice(const Matrice&, int*, int); //Costruttore matrice di base
    void aggiornaTrasposta();
	void stampa();
	void assegna(float *vett, int size, bool din = false);
	float *mColonna(float *vett, int size);
	float *mRiga(float *vett, int size);
	Matrice *operator=(Matrice &matr);
	float *operator*(const Matrice &mat);
    float determinante();
    float *inversa();
    float* selezionaRiga(int r);
    float* selezionaColonna(int c);
};

float det(float[], int);

#endif
