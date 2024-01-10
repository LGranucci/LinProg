#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    //Test mColonna
	Matrice a(3, 2);
    Matrice b(2, 3);
	float v1[6] = {2, 1, 0, 2, 4, 3};
	float vect[3] = {3, 4, 3};
	a.assegna(v1, 6);
    b.assegna(v1, 6);

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
        for (int j = 0; j < 3; j++)
        {
            cout<<" "<<moltiplication[i*3 + j];
        }
        cout<<"\n";
    }

	return 0;
};
