#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	float S, V, pi, r;
	pi = 3.1415926;
	
	do{
		cout << "Input Radius: ";
		cin >> r;
	} while (r <= 0);
	
	V = 4/3*pi*r*r*r;
	S = 4*pi*r*r;
	
	cout << "Volume: " << V <<"m^3, Surface Area: " << S <<"m^2"<<endl;

	return 0;
}
