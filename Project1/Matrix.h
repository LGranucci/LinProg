#include <iostream>
using namespace std;

class Matrice {
	int n;
	int m;
	int** matrice;
public:
	Matrice(int a, int b) {
		n = a; //righe
		m = b; //colonne
		cout << n << m << endl;
		matrice = new int* [n];
		for (int i = 0; i < m; i++) {
			matrice[i] = new int[m];
		}
		int x;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> x;
				matrice[i][j] = x;
			};
		};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << matrice[i][j];
			}
			cout << endl;
		}
	}
	friend ostream& operator<<(ostream&, const Matrice&);
	Matrice* opposta();

};
