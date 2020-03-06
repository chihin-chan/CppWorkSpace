#include <iostream>

using namespace std;

int main()
{
	string vName;
	unsigned int vAge;
	unsigned int vOption;
	
	cout << "Enter your name: ";
	getline(cin, vName);
	
	cout << "Enter your Age: ";
	cin >> vAge;
	
	cout << " Please Select Option:" << endl;
	cout<<"1. Option 1"<< endl;
	cout<<"2. Option 2"<< endl;
	cout<<"3. Quit"<< endl;
	cout<<"Enter Option: ";
	cin >> vOption;
	
	cout << "Name: " << vName << ", Age: " << vAge << ", Option: " << vOption << endl;
		
}
