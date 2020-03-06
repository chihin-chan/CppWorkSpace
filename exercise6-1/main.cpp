#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double c2f(double cel){
	return cel*9/5 +32;
}

double f2c(double feh){
	return (feh - 32 )*(5/9);
}

int main(){
	
	int option;
	float deg;
	
	try{
		cout << "Enter Option: "<< endl;
		cout << " 1. Celsius to Fahrenheit" <<endl;
		cout <<" 2. Fahrenheit to Celsius" << endl;
		cin >> option;
		
		
		if (option < 1 || option >2){
			logic_error("Invalid Option");
		}
		switch(option){
			case 1:
			cout << " Option 1 selected. " << endl;
			cout << " Enter Celsius." << endl;
			cin >> deg;
			cout << deg <<"C  -> " << c2f(deg) << "F" <<endl;
			break;
			case 2:
			cout << " Option 1 selected. " << endl;
			cout << " Enter Fahrenheit." << endl;
			cin >> deg;
			cout << deg <<"F -> " << f2c(deg) << "C" <<endl;
			break;
		}
	}
	
	catch (const logic_error& e){
		cout << "Invalid Option" << e.what() << endl;
	}
}