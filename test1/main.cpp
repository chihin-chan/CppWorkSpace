#include <iostream>
#include <math.h>

using namespace std;

int factorial(int n);
double sin_fun(double x, int k);
double cos_fun(double x, int k);

int main(int argc, char **argv)
{
	double value;										// Storing rad input by user
	const double pi = 3.1415926535897; // Declaring pi
	int k =5;												// Summation up to k steps
	double abs_err;									// Storing absolute error 
	
	// Repeat try and catch function until user inputs in correctly
    while (true) {
        try {
			string input;
            cout << "Input radians: ";
            cin >> input;
            double tmp = std::stod(input);   // Exception thrown here

            if (tmp < -pi || tmp > pi) {
                throw std::out_of_range("");
            }
			
			// Storing User Input, radians
            value = tmp;
            // if no error occurs, we ignore the 'catch' blocks
            break;
        }

        // Catch exception if a string is entered
        catch (std::invalid_argument const &e) {
            cout << "Error: Please enter a number." << endl;
        }

        // Catch exception if a input is beyond range
        catch (std::out_of_range const &e) {
            cout << "Error: Number is out of range. Please enter value in radians, between -pi<x<pi." << endl;
		}
	}
	
	// Printing results to the command line
	cout << "Radians entered: " << value <<"rad" << endl;
	cout << "Exact value of sin(" <<value <<"): " << sin(value) << endl;
	cout << "Exact value of cos(" << value <<"): " << cos(value) << endl;
	cout << "Approximate value of sin(" << value << "): " << sin_fun(value,k) << endl;
	cout << "Approximate value of cos(" << value << "): " << cos_fun(value,k) << endl;
	
	abs_err = abs( ((sin(value) * sin(value)) + (cos(value) * cos(value)) )- ((sin_fun(value, k) * sin_fun(value, k)) + (cos_fun(value, k)*cos_fun(value, k))) );
	
	cout << "Absolute error: " << abs_err << endl;
	
	return 0;
}



// Function for calculating factorial
int factorial(int n){
	
	double fact = 1;
	// Looping factorial
	for (int i=1; i <= n ; i++){
		fact = fact*i;
	}
	return fact;
}

// Function for calculating sin
double sin_fun(double x, int k){
	
	double sum = 0;
	// Computing the summation from formula
	for(int i =0; i<=k; i++){
		sum = sum + ( pow(-1,i) * pow(x,(2*i+1)) /  factorial(2*i+1) );
	}
	return sum;
}

// Function for calculating cos
double cos_fun(double x, int k){
	
	double sum = 0;
	// Computing the summation of cos from formula
	for(int i = 0; i<=k; i++){
		sum = sum + ( pow(-1,i) * pow(x,2*i) / factorial(2*i) );
	}
	return sum;
}