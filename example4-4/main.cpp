#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	int x = 5;
	ofstream vOut("data.txt", ios::out | ios::trunc);
	vOut.precision(5);
	vOut << setw(15) << "#_x"
			 << setw(15) <<"x^2"
			 << setw(15) << "x^3" << endl;
	vOut << setw(15) << x
			 << setw(15) << x*x
			 << setw(15) << x*x*x << endl;
	vOut.close();

}