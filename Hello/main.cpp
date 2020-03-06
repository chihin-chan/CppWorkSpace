#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    cout << argc << endl;
	cout << argv <<  endl;
	for (int i =1; i<=argc; ++i)
	{
		cout << argv[i] << endl;
		}
	return 0;
}
