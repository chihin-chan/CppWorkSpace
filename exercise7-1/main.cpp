#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double average(double a[], int size);
double max(double a[], int size);


int main(int argc, char **argv)
{
	const int arraySize = 100;
	double myArray[arraySize];
	
	// Initial seed
	srand(time(0));
	
	for  (unsigned int i = 0 ; i < arraySize; i++){
		myArray[i] = 100.0 * rand() / (double(RAND_MAX));
		cout << myArray[i] << endl;
	}
	cout << "Average" << endl;
	cout << average(myArray, arraySize) << endl;
	
	cout << "Big" << endl;
	cout << max(myArray, arraySize) << endl;
	
}


double average(double a[], int size){
	
	double sum = 0;
	for (unsigned int i = 0; i<size; i++){
		sum += a[i];
	}
	return sum/(double(size));
}

double max(double a[], int size){
	double big = 0.0;
	for (unsigned int i=0; i<size; i++){
		if (a[i] > big){
			big = a[i];
		}
	}
	return big;
}