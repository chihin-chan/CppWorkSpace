#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
	double fact = 1;
	
	cout << "Input n! ";
	cin >> n;
	
	for (int i=1; i <= n ; i++){
		fact = fact*i;
	}
	
	cout << "Factorial = " << fact << endl;
	
	return 0;
}
	
