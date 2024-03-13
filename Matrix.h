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
    Matrice(Matrice*, int*); //Costruttore matrice di base
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

bool PassoSimplesso(Matrice &A, int n, int m, int* Basi, float* c, float*b);
float linprog(Matrice* A, int n, int m, int* Basi, float*c, float*b);
 
#endif

