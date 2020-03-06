#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int a = 2;
	int b = 5;
	int c = 4;
	float result;
	
	result = a + b * c / a * ( b - c ) + b % c;
	//  2 + (5*4/2*(1)) + 1
	// 2 + 10 + 1 
	
	cout << result << endl;
	
}
