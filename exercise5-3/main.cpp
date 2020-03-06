#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
	
	int k1,k2;
	double sum1, sum2, pi_exact, pi, pi2;
	
	pi = 0;
	sum1 = 0;
	sum2 = 0;
	k1 = 0;
	
	pi_exact = 3.14159265;
	
	// first sum
	
	while ( abs(pi_exact - pi) > 1e-5){
		
		sum1 = (4*pow(-1,k1)) / (2*k1+1);
		pi = sum1 + pi;
		
		
		cout << "Value of Pi " << pi << endl;
		cout <<endl;
		k1++;
	}
	
	pi2  = 0;
	k2 =1;
	
	while ( abs(pi_exact - pi2) > 1e-5){
		
		sum2 = ( 4*pow(k2,2) ) / ( 4*pow(k2,2)-1 );
		pi2 = sum2 + pi2;
		cout << "Value of Pi (2nd Sum): " << pi2<< endl;
		cout <<endl;
		k2++;
	}
	cout << "Value of K: " << k1 << endl;
	cout << "Value of K: " << k2 << endl;
		
	
}

