#include "Matrix.h"
#include <iostream>
using namespace std;
ostream& operator<<(ostream&os, const Matrice&m) {
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.m; j++) {
			cout << " " << m.matrice[i][j];
		}
		cout << endl;
	}
	return os;
}

Matrice* Matrice::opposta()
{
	//Attenzione: non si può inizializzare una matrice con un ciclo di cin. serve un vettore
	return nullptr;
}
