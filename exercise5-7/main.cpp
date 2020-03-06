#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    float c = 100;
	float m = 10;
	float v = 0;
	float dt = 0.1;
	float g = 9.81;

	
	while (true){
		v = v + ( g - c / m * v) * dt;
		cout << "Velocity: "<< v<< endl;
	}
}
