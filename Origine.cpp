#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    //Test mColonna
	Matrice a(3, 2);
    Matrice b(2, 7);
    Matrice c(3, 3);
    Matrice d(2, 2);
    Matrice e(4, 4);
	float v1[6] = {1, 2, 3, 4, 5, 6};
    float v2[16] = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17};
	float vect[3] = {3, 4, 3};
	a.assegna(v1, 6);
    b.assegna(v2, 14);
    c.assegna(v2, 9);
    d.assegna(v1, 4);
    e.assegna(v2, 16);

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
    std::cout<<"prova determinante di matrice d: \n";
    d.stampa();
    std::cout<<"\ndeterminante pari a: "<<d.determinante()<<"\n";

    std::cout<<"prova determinante di matrice c: \n";
    c.stampa();
    std::cout<<"\ndeterminante pari a: "<<c.determinante()<<"\n";

    std::cout<<"prova determinante di matrice e: \n";
    e.stampa();
    std::cout<<"\ndeterminante pari a: "<<e.determinante()<<"\n";

    //Test matrice inversa
    std::cout<<"inversa matrice e: \n";
    Matrice inv_e(4, 4);
    inv_e.assegna(e.inversa(), 16, true);
    inv_e.stampa();

    std::cout<<"martice e moltiplicata per la propria inversa: \n";

    float* k = inv_e * e;
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout<<k[i*4+j]<<" ";
        }
        std::cout<<"\n";
        cout<<endl;
    }

    float* result;
    inv_e.stampa();
    result = inv_e.selezionaColonna(1);
    for (int i = 0; i < 4; i++)
    {
        cout<<result[i]<<endl;
    }
    
    
    delete[] k;
    
	return 0;
};
