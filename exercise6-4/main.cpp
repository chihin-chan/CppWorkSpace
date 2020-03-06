#include <iostream>
using namespace std;

int factorial(int n);

int main(int argc, char **argv)
{
	int n;
	int k;
	string tmp1, tmp2;
	
	while(true){
		try
			{
			cout << "Input n ";
			cin >> tmp1;
			cout << "Input k ";
			cin >> tmp2;
			
			n = std::stoi(tmp1);
			k = std::stoi(tmp2);
			
				if (n <= 0 || k <= 0){
					throw std::out_of_range("");
				}	
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
	
	cout << "Factorial = " << factorial(n)/(factorial(k)*factorial(n-k))<< endl;
	
	return 0;
}

int factorial(int n){
	
	double fact = 1;
	
	for (int i=1; i <= n ; i++){
		fact = fact*i;
	}
	
	return fact;
}