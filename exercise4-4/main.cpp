#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
	float y,w,E,I,x,L;
	
	L = 2;
	w = 10e4;
	I = 0.0016;
	E = 210 * 10e9;
	
	x = L/2;
	
	y = -w/(24*E*I)*(x*x*x*x - 2*L*x*x*x + L*L*L*x);
	
	cout << "Deflection" << y << endl;
	
}
