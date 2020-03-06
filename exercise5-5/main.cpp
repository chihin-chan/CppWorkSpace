#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	double x[100]; 
	double s[100];
	
	ofstream vOut("Data.txt", ios::out | ios::trunc);
	
	if (vOut.good()){
		
		vOut.precision(5);
		cout << "test";
		for(int i=0; i<=99; i++){
			x[i] = 2*3.142*i/100;
			s[i] = sin(x[i]);
			cout << "x: " << x[i] << endl;
			cout << "sin function: " << s[i]<<endl;
			vOut << x[i] <<", " << s[i] << endl;	
		}
	vOut.close();
	}
	
	else{
		cout << "File is corrupted"<< endl;
	}
	
	return 0;
}
