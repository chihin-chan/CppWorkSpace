#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cblas.h>
#include <string.h>
#define F77NAME(x) x##_
extern "C" {
	void F77NAME(dgesv) (const int& n, const int& nrhs, const double* A, 
										  const  int& lda, int * ipiv, double * b,
										  const int& ldb, int& info);
}

using namespace std;

void vecPrint(double* p, int n){
	for(int i = 0;  i<n; i++){
			cout << p[i] << endl;
	}
}

void matPrint(double* A, int n, int p){
	for(int i = 0;  i<n; i++){
			for( int j = 0; j<p;j++){
				cout << A[i+j*n] << "	";
			}
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	ifstream vMyFile("data.txt");
	string n_temp;
	string x_temp;
	string y_temp;
	
	int n;
	double* x = nullptr;
	double* y = nullptr;
	if (vMyFile.good()) {
		// Gets n
		vMyFile >> n_temp;
		n = stoi(n_temp);
		x = new double[n];
		y = new double[n];
		int j = 0;
		int i = 0;
		
		while (true) 
		{		
				vMyFile >> x_temp;
				x[j] = stod(x_temp);
				j++;

				vMyFile >> y_temp;
				y[i] = stod(y_temp);
				i++;
		
			if (vMyFile.eof()) {
				break;
			}
		}
		vMyFile.close();
	}
	else{
		cout << "Failed to open file" << endl;
	}
	
	int p = 4;
	double* A = new double[n*p];
	
	// Assembling matrix A with components of x
	for(int j=0; j<p;j++){
		for(int i = 0; i<n;i++){
			A[i+n*j] = pow(x[i],j);
		}
	}

	double* titre = new double[p];
	double* aty = new double[n];
	double* ata = new double[p*p];
	int* piv = new int[p];
	int info;
	
	cblas_dgemv(CblasColMajor, CblasTrans, n, p, 1.0, A, n, y, 1, 0.0, aty, 1);
	cblas_dgemm(CblasColMajor, CblasTrans, CblasNoTrans, p, p, n , 1.0,  A, n, A, n, 0.0, ata, p);
	
	vecPrint(aty,p);
	cout <<endl;
	F77NAME(dgesv) (p,  p, ata, p, piv, aty, p, info);
	vecPrint(aty, p);
	
	delete[] titre;
	delete[] A;
	delete[] x;
	delete[] y;

}
