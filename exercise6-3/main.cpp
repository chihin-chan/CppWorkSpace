#include <iostream>
#include <fstream>

using namespace std;

double sim_support(double x);
double canti(double x);

int main(int argc, char **argv)
{
	double x;
	double dx;
	
    cout << "Enter x: ";
	cin >> x;
	
	cout << "Cantilever Deflection: "<< canti(x) << endl;
	cout << "Simply Supported: "<< sim_support(x) << endl;
	
	dx = 0.1;
	int n = 1/dx;
	
	ofstream vOut("Deflection.txt", ios::out | ios::trunc);
	vOut.precision(5);
	
	vOut << "Cantilevel Deflection" << " 	dx" << "		"<< "Sim Deflect"<< "	dx"<< endl;
	for (int i=1; i <= n; i++){
		cout << "Cantilever Deflection: "<< canti(i*dx) << endl;
	    cout << "Simply Supported: "<< sim_support(i*dx) << endl;
		vOut << canti(i*dx) << "		" << i*dx << "			"<< sim_support(i*dx) <<"		"<< i*dx<< endl;
	}
	vOut.close();
	return 1;
}

double sim_support(double x){
	double E = 210 * 10e9;
	double I = 0.0016;
	double w = 10*10^3;
	double L = 1;
	
	return -w/(24*E*I)*(x*x*x*x - 2*L*x*x*x + L*L*L*x);
	
}

double canti(double x){
	double E = 210 * 10e9;
	double I = 0.0016;
	double F = 10*10^3;
	double L = 1;
	
	return F/(6*E*I)*(x*x*x - 3*L*x*x);
	
}