#include <iostream>
 #include <limits>
 using namespace std;

 int main() {
	string input;
	cout << "Enter text (whitespace-delimited): ";
	
	cin >> input;
	
	cout << "Using stream operators: " << input << endl;
	
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter text (newline-delimited): ";
	getline(cin, input);
	cout << "Using default getline: " << input << endl;

	cout << "Enter text (comma-delimited): ";
	getline(cin, input, ',');
	cout << "Using comma separator: " << input << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


 return 0;
 }