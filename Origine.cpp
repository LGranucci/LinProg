#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    //Test mColonna
	Matrice a(3, 2);
    Matrice b(2, 7);
	float v1[6] = {1, 2, 3, 4, 5, 6};
    float v2[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	float vect[3] = {3, 4, 3};
	a.assegna(v1, 6);
    b.assegna(v2, 14);

    cout<<"Matrice a: \n";
	a.stampa();
    cout<<"Matrice b: \n";
    b.stampa();
    cout<<"vect: \n";
    for (int i = 0; i < 3; i++)
    {
        cout<<" "<<vect[i];
    }
    cout<<"\n";

    cout<<"a.mColonna(vect, 3): \n";
	float *res = a.mColonna(vect, 3);

    cout<<"b.mColonna(vect, 3): \n";
    res = b.mColonna(vect, 3);
	for (int i = 0; i < 2; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
    
    //test mRiga
    std::cout<<"a.mRiga(vect, 3)\n";
	float *res2 = a.mRiga(vect, 3);
	for (int i = 0; i < 2; i++)
	{
		cout << res2[i] << " ";
	}
	cout << endl;

    //test overloading operator * 
    cout<<"\n\ntest prodotto a*b:\n";
    float *moltiplication = a * b; //matrice 3*3
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout<<" "<<moltiplication[i*7 + j];
        }
        cout<<"\n";
    }

	return 0;
};
