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

void vecPrint(double* v, int n){
	for(int i = 0; i<n; i++){
		cout << v[i] << endl;
	}
}

void matPrint(double* A, int n, int m){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << A[i+j*n] << "	";
		}
	cout << endl;
	}
}

int main(int argc, char**argv){	

	int n;
	int p = 4;
	double* y = nullptr;
	double* x = nullptr;
	double* A = nullptr;
	double* aty = nullptr;
	double* ata = nullptr;
	
	// Reading File and storing n, vector x, vector y
	ifstream vMyFile("data2.txt");
	string nTemp;
	if(vMyFile.good()){
		vMyFile >> nTemp;
		n = stoi(nTemp);
		
		x = new double[n];
		y = new double[n];
		int i = 0;		
			while(true){
				vMyFile >> nTemp;
				x[i] = stod(nTemp);
				
				vMyFile >> nTemp;
				y[i] = stod(nTemp);
				
				i++;
				
				if(vMyFile.eof()){
					break;
				}
			}
	}
	
	// Printing x, y 
	// vecPrint(x,n);
	// vecPrint(y,n);	

	// Assembling matrix A
	A = new double[n*p];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<p; j++){
			A[i+j*n] = pow(x[i],j);
		}
	}

	// matPrint(A,n,p);
	
	// Computing Matrix-Vector Multiplication A**T * y
	aty = new double[p];	
	cblas_dgemv (CblasColMajor, CblasTrans, n, p, 1.0, A, n, y, 1, 0.0, aty, 1);

	// Computing Matrix-Matrix Multiplication A**T * A
	ata = new double[p*p];
	cblas_dgemm (CblasColMajor, CblasTrans, CblasNoTrans, p, p, n, 1.0, A, n, A, n, 0.0, ata, p);

	// Inverse ATA^-1 * (ATy)
	int* piv = new int[p];
	int info = 0;
	for(int i=0; i<p; i++){
		piv[i] = i;
	}
	F77NAME (dgesv) (p,1,ata,p,piv,aty,p,info);
    
    // Prints Results
    cout << "Solution: " << endl;
    vecPrint(aty,p);
	

	delete[] piv;
	delete[] y;
	delete[] x;
}


