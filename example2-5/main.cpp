#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	enum Colour {
	red, // red -> 0 (implicitly chosen)
	green = 5, // green -> 5
	blue, // blue -> 6 (implicitly chosen)
	yellow = 10 // yellow -> 10
 };
	int a = 100000;
	char c = a;
	int x = a; // x == 6
	cout << x << endl;
	
}