#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
	ifstream vMyFile("Data.txt");
	string var1, var2;
	float flt1,flt2;
	if (vMyFile.good()){
		while (true){
			vMyFile >> var1 >> var2;
			flt1 = stof(var1);
			flt2 = stof(var2);
			if (vMyFile.eof()){
				break;
			}
			cout << flt1 << " "<< flt2 << endl;
		}
	vMyFile.close();
	}
	else {
		cout << "Failed to open file"<< endl;
	}
}

	
