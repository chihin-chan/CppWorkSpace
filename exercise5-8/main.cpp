#include <iostream>
#include <cmath>
using namespace std;

double funct(double x);

int main(int argc, char **argv){
	
	const double a = -1;
	const double b = 1;
	int n = 1000;
	const double h = (b-a)/n;
	double sum1 = 0;
	double sum2 = 0;
	double integral;
	
	// Calculating the first summation
	for (int i = 1; i <= n/2; i++){
		sum1 = sum1 + funct(a+(2*i-1)*h);
	}
	
	// Calculating the second summation
	for (int i = 1; i <= n/2 -1; i++){
		sum2 = sum2 + funct(a+2*i*h);
	}
	
	integral = (b-a)/(3*n) * ( funct(a) + 4*sum1 + 2*sum2 + funct(b) );
	cout << "No. of intervals: "<< n << endl;
	cout << "Integral: "<< integral << endl;
	
}

double funct(double x){
	return x*x*exp(x*x);
}