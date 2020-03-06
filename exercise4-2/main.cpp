#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
	float m,g,c,v,t;
	
	g = 9.81;
	
	cout << "Mass?";
	cin >> m;
	
	cout << "Drag Coefficient?";
	cin >> c;
	
	cout.precision(4);
	cout<< "V(3) = " << m*g/c*(exp(-c*3/m)-1) <<endl;
	cout << "V(5) = " << m*g/c*(exp(-c*5/m)-1) <<endl;
	cout << "V(7) = " << m*g/c*(exp(-c*7/m)-1)<<endl;
	cout << "V(Terminal) = " << m*g/c*(-1)<<endl;
}
