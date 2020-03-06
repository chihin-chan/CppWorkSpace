#include <iostream>
#include <cblas.h>

#define F77NAME(x) x##_
extern "C" {
    void F77NAME(dsyev) (const char& v, const char& ul, const int& n,
                         double* a, const int& lda, double* w,
                         double* work, const int& lwork, int* info);
}

using namespace std;

int main(){
    
    const int n = 10;
    const int lda = n;
    const int ldv = n;
    
    int info = 0;
    int lwork = -1; 
    double wkopt;
    double* A = new double[n*n];
    double* w = new double[n];
    double* work;

    srand(time(0));
    for (int i = 0;  i<n; i++){
        for(int j = 0; j<n; j++){
            A[i+n*j] = A[j*n+i] = double(rand())/RAND_MAX;
        }
    }

    // Query for optimal workspace
    F77NAME (dsyev) ('V', 'U', n, A, lda, w, &wkopt, lwork, &info);
   
    // Allocating Workspace
    lwork = int(wkopt);
    work = new double[lwork];
    
    // Solving for eigenvalues
    F77NAME (dsyev) ('V', 'U', n, A, lda, w, work, lwork, &info);
    
    if(info){
        cout << "ERROR: An error has occured!" << endl;
    }    
}
