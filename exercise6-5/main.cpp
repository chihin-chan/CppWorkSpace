#include <iostream>
using namespace std;

int fib(int x);

int main(int argc, char **argv)
{
	int n;
	
	while(true){
		try{
			string input;
			cout << "Enter n: ";
			cin >> input;
			
			int tmp  = std::stoi(input);
			
			// n must be greater or equals to 0
			if (tmp <= 0){
				throw std::out_of_range("");
			}
			
			// move out of while loop
			n = tmp;
			break;
		}
		
		// Catch exception if a string is entered
		catch (std::invalid_argument const &e){
			cout << "Error: Please enter a number." << endl; 
		}
		
		// Catch exception if a very large integer entered
		catch (std::out_of_range const &e) {
            cout << "Error: Number too large or negative." << endl;
        }
	}
	
	cout << "Fib Sequence " << fib(n) << endl;
	
	return 0;
}


int fib(int n){
	if (n>2){
		return  fib(n-1) + fib(n-2);
	}
	else 
	{
		return 1;
	}
}