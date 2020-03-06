#include <iostream>
using namespace std;

double* insert(double a[], int size, int p, double val);

int main(int argc, char **argv)
{
	const int arraySize = 5;
	double array[arraySize];
	double array_sorted[arraySize];
	int p = 4;
	double val = 7.0;
	
	cout << "Array" << endl;
	
	for (unsigned int i = 0; i<arraySize; i++){
		array[i] = 10.0 * rand()/(double(RAND_MAX));
		cout << array[i] << endl;
	}
	
	cout <<"Sorted array" <<endl;
	
	array_sorted = insert(array, arraySize, p , val);
	
	for (unsigned int i = 0; i<arraySize; i++){
		cout << array_sorted[i] << endl;
	}
	
	return 0;
}

double* insert(double a[], int size, int p, double val){
	double dum1 = 0.0;

	for (unsigned int i =0; i < p; i++){
		if (a[i] > a[i+1]){
			dum1 = a[i];
			a[i] = a[i+1];
			a[i+1] = dum1;
		}
	}
	
	return a;
}