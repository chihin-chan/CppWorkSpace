#include <iostream>
using namespace std;

int main() {
	int n;
	for (n=20; n >0; n--){
		if (n%4 == 0){
			continue;
		}
		// 19,18,17 prints 1,2,3
		// 16 doesn't print
		// 15,14,13 prints 5,6,7
		// skip 8 -> 9 10 11 -> 12 13 14 15
		cout << (20-n) << endl;
		if (n==5){
			break;
		}
	}
	return 0;
}
