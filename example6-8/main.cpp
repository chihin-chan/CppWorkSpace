#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

namespace mymath{
	double mylog(double num) {
		if (num<=0) {
			throw std::logic_error("Number must be > 0");
		}
		return std::log(num);
	}
}
int main(){
	
	try{
	std::cout<<mymath::mylog(1)<<std::endl;
	std::cout<<mymath::mylog(-1)<<std::endl;
	}
	catch (const std::log_error& e) {
	std::cout << "An error occure: " << e.what() << std::endl;
	}
	catch (const std::bad_alloc& e) {
	std::cout << "No allocations here., so should not be called!"
					<< std:endl;
	}	
}
