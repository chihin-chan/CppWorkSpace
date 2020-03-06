#include <iostream>
#include <math.h>
using namespace std;

double test(string prompt);
double root(double a, double n, double esp, double x0);

int main(int argc, char **argv)
{
    double a;
	double n;
	double x0;
	double esp;
	
	string msg1 = "Enter a ";
	string msg2 = "Enter n ";
	
	esp = 10e-4;
	x0 = 1;
	
	a = test(msg1);
	n = test(msg2);
	
	cout<<"a: "<< a << endl;
	cout<<"n: "<< n << endl;
	
	cout << "Rooot: " << root(a, n, esp, x0) << endl;
	
	cout << "error : " << pow(a,1/n) - root(a, n, esp, x0) <<endl;
	

	return 0;
}


double test(string prompt){
	string input;
	double a;
	
	while (true) {
        // Try to execute commands
        try {
            cout << prompt;
            cin >> input;
            double tmp = std::stod(input);   // Exception thrown here

            if (tmp <= 0) {
                throw std::out_of_range("");
            }
            // if no error occurs, we ignore the 'catch' blocks
            a = tmp;
			break;
			
        }

        // Catch exception if a string is entered
        catch (std::invalid_argument const &e) {
            cout << "Error: Please enter a number." << endl;
        }

        // Catch exception if a very large integer entered
        catch (std::out_of_range const &e) {
            cout << "Error: Number too large or negative." << endl;
        }
		
	}
	return a;
}

double root(double a, double n, double esp, double x0){
	double dx = 1;
	double x_pow;

	int i = 0;
	while (abs(dx) >= esp){
		x_pow = x0;
		for (int i =1; i < n-1; i++){
			x_pow = x0*x_pow;
		}
		dx = 1/n * ( a / (x_pow) - x0);
		//cout << "dx = " << dx << endl;
		x0 = x0 + dx;
		//cout << i << endl;
		i++;
	}	
	return x0;
}