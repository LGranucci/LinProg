
#include <iostream>
#include "Matrix.h"
//prende in input una matrice A, le sue dimensioni, un array di base, un array c e un array b
//Restituisce un vettore di base modificato
//La matrice A deve essere già di base
int* PassoSimplesso(Matrice A, int n, int* Basi, float* c, float*b){
    
    // y = c * A^-1 
    float* ai_vect = A.inversa();
    Matrice ai = Matrice(n, n);
    ai.assegna(ai_vect, n, 0);
    float* y = ai.mColonna(c, n);
    //find k = first neg element of y
    int k = -1;
    for (int i = 0; i < n; i++)
    {
        if(y[i] < 0){
            k = i;
        }
    }
    if(k = -1){
        std::cout<<"tutto y positivo";
        //gestire il return
    }
    std::cout<<k;
    return 0;
}






float linprog(Matrice* A, int n, int m, int* Basi, float*c, float*b){
    Matrice Ab = Matrice(A, Basi);
    PassoSimplesso(Ab, m, Basi, c, b);
    return 0;   
}




