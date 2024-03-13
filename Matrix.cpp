#include <iostream>
#include "Matrix.h"
#define MAX 200


using namespace std;

int alt(int num)
{
    if (num%2 == 0)
    {
        return 1;
    }
    return -1;
}

//dim: dimensione di src 
void copiaEscludi(float* src, float* dest, int r, int c, int dim)
{
    int iSrc = 0, jSrc = 0;
    for (int i = 0; i < dim-1; i++)
    {
        if(iSrc == r)
        {
            iSrc++;
        }
        for(int j = 0; j < dim-1; j++)
        {
            if(jSrc == c)
            {
                jSrc++;
            }
            dest[i*(dim-1)+j] = src[iSrc * dim + jSrc];
            jSrc++;
        }
        jSrc = 0;
        iSrc++;
    }
}

Matrice::Matrice(int a, int b)
{

		n = a; // righe
		m = b; // colonne
		//cout << n << m << endl;
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

Matrice::Matrice(const Matrice &m1) //DA TESTARE
{
    this->n = m1.n;
    this->m = m1.m;
    this->matrice = new float*[m1.n];
    for (int i = 0; i < m1.n; i++)
    {
        this->matrice[i] = new float[m1.m];
        for (int j = 0; j < m1.m; j++)
        {
            this->matrice[i][j] = m1.matrice[i][j];
        }
    }
    this->trasposed = new float*[m1.m];
    for (int i = 0; i < m; i++)
    {
        this->trasposed[i] = new float[m1.n];
    }
    this->aggiornaTrasposta();
}

Matrice::Matrice(Matrice* m1, int* base)//Da testare
{
    this->m = this->n = m1->m;
    
    this->matrice = new float*[this->m];
    for (int i = 0; i < this->n; i++)
    {
        this->matrice[i] = new float[this->m];
        for(int j = 0; j < this->m; j++)
        {
             this->matrice[i][j] = m1->matrice[base[i]][j];
        }
    }
    this->trasposed = new float*[m1->m];
    for (int i = 0; i < m; i++)
    {
        this->trasposed[i] = new float[m1->m];
    }
    this->aggiornaTrasposta();
}

void Matrice::aggiornaTrasposta() //DA TESTARE
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            trasposed[i][j] = matrice[j][i];
        }
    }
}

void Matrice::stampa()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << " " << matrice[i][j];
		}
		cout << endl;
	}
};

void Matrice::assegna(float *vett, int size, bool din)
{
	//cout << size << endl;
    if (vett == nullptr)
    {
        cout<<"vettore non esistente\n";
        return;
    }
	if (size != n * m)
	{
		cout << "size vettore sbagliato" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrice[i][j] = vett[i * m + j];
		}
	}
    if (din)
        delete[] vett;
}

float *Matrice::mColonna(float *vettore, int size)
{
	if (size != m)
	{
		cout << "non possibile" << endl;
		return vettore;
	}
	float *result = new float[n];
	float aux = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < size; j++)
		{
			aux += matrice[i][j] * vettore[j];
		}
		result[i] = aux;
		aux = 0;
	}
	return result;
}

float *Matrice::mRiga(float *vett, int size)
{
	if (size != n)
	{
		cout << "not possible" << endl;
		return vett;
	}
	float *result = new float[n];
	float aux = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			aux += matrice[j][i] * vett[j];
		}
		result[i] = aux;
		aux = 0;
	}
	return result;
}

Matrice *Matrice::operator=(Matrice &matr)
{
	Matrice *b = new Matrice(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; i++)
		{
			b->matrice[i][j] = matrice[i][j];
		}
	}
	return b;
}

float *Matrice::operator*(const Matrice &mat)
{
	if (this->m != mat.n)
	{
		cout << "Errore: dimensione scorretta\n";
		return nullptr;
	}

	float *res = new float[this->n * mat.m];

	for (int i = 0; i < this->n * mat.m; i++)
	{
		res[i] = 0;
	}

	for (int k = 0; k < this->n; k++)
	{
		for (int i = 0; i < mat.m; i++)
		{
			for (int j = 0; j < this->m; j++)
			{
				res[k * mat.m + i] +=
					this->matrice[k][j] * mat.matrice[j][i];
			}
		}
	}
	return res;
}

float Matrice::determinante()
{
    if (n != m) 
    {
        return 0;
    }
    float tempvs[n*n];

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            tempvs[i*n + j] = matrice[i][j];
    }
    return det(tempvs, n);
}

float det(float matrix[], int dim)
{
    float d = 0;
    if(dim == 1)
        return matrix[0];
    if(dim == 2)
        return matrix[0]*matrix[3]-matrix[1]*matrix[2];
    else
    {
        for(int i = 0; i < dim; i++)
        {
            float sotto_m[(dim-1)*(dim-1)];
            copiaEscludi(matrix, sotto_m, 0, i, dim);
            d += alt(i) * matrix[i]
                 * det(sotto_m, dim-1);
        }
    }
    return d;
}


float *Matrice::inversa() 
{

    float detM = this->determinante();
    
    //std::cout<<"determinante matrice da invertire: "<<detM<<"\n";

    if (!detM) 
    {
        std::cout<<"matrice non invertibile\n";
        return nullptr;
    }

    float *ris = new float[n*n];

    float matrix[n*n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i * n + j] = this->matrice[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            float coFactor[(n-1)*(n-1)]; 
            copiaEscludi(matrix, coFactor, i, j, n);
            //// DEBUGGG 
            //std::cout<<"cofattore di A_"<<i<<"_"<<j<<": \n";
            //for(int k = 0; k < n-1; k++)
            //{
            //    for(int l = 0; l < n-1; l++)
            //    {
            //        std::cout<<coFactor[i * (n-1) + j];
            //    }
            //    std::cout<<"\n";
            //}
            //std::cout<<"determinante del cofattore: "<<det(coFactor, n-1)<<"\n";
            ////DEBUGGgggGG
            ris[j*n + i] = alt(i+j) * det(coFactor, n-1);
        }
    }
    for (int i = 0; i < n*n; i++)
    {
        ris[i] *= (1/detM);
    }
    return ris;
}


float* Matrice::selezionaRiga(int r){
    float* res;
    res = new float[this->m];
    if(r >= n){
        cout << "riga non esistente"<<endl;
        return res;
    }
    for (int i = 0; i < this->m; i++)
    {
        res[i] = this->matrice[r][i];
    }
    
    return res;
}

float* Matrice::selezionaColonna(int c){
    float* res;
    res = new float [this->n];
    if(c >= m){
        cout<< "colonna non esistente"<<endl;
        return res;
    }
    for (int i = 0; i < this->n; i++)
    {
        res[i] = this->matrice[i][c];
    }
    
    return res;
}

bool PassoSimplesso(Matrice &A, int n, int m, int* Basi, float* c, float*b)
{ 
      
    // y = c * A^-1 
    Matrice Ab(&A, Basi);
    float* ai_vect = Ab.inversa();
    Matrice ai = Matrice(m, m);
    ai.assegna(ai_vect, m * m, 0);
    float* y = ai.mColonna(c, m);
    //find k = first neg element of y
    int k = -1;
    for (int i = 0; i < m; i++)
    {
        std::cout<<y[i]<<"y"<<i<<std::endl;
        if(y[i] < 0){
            k = i;
        }
    }
    if(k == -1){
        std::cout<<"tutto y positivo\n";
        Basi[0] = -1;
        return true;
    }
    std::cout<<k<<"\n";
    return false; //problema non risolto
}

float linprog(Matrice* A, int n, int m, int* Basi, float*c, float*b)
{
    PassoSimplesso((*A), n, m, Basi, c, b);
    return 0;   
}







