/*
 * High-performance Computing
 *
 * Solution to Exercise 6.1.
 *
 * Converts temperatures between celsius and fahrenheit.
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Convert a temperature in celcius to farenheit
double c2f(double temp) {
    return temp * 9.0 / 5.0 + 32.0;
}

// Convert a temperature in farenheit to celcius
double f2c(double temp) {
    return (temp - 32.0) / 9.0 * 5.0;
}

int main() {
    string input        = "";
    unsigned int option = 0;
    double in_temp      = 0.0;
    double out_temp     = 0.0;

    try {
        // These lines print a menu, and produce an integer
        cout << "Select conversion: " << endl;
        cout << "  1. C to F" << endl;
        cout << "  2. F to C" << endl;
        cout << "Choose an option: ";
        cin >> input;
        option = stoi(input);

        // Check the user entered a valid option
        if (option < 1 || option > 2) throw logic_error("Invalid option.");

        // Call the relevant function for each option
        switch (option) {
            case 1:
                cout << "Enter temperature in C: ";
                cin >> input;
                in_temp = stod(input);

                cout << in_temp << "C is " << c2f(in_temp) << "F" << endl;

                break;  // don't forgot - otherwise case 2 will also run
            case 2:
                cout << "Enter temperature in F: ";
                cin >> input;
                in_temp = stod(input);

                cout << in_temp << "F is " << f2c(in_temp) << "C" << endl;

                break;  // not essential here, but good practice!
            default:    // good practice
                break;
        }
    }
    catch (const exception& e) {
        cout << "Error in input: " << e.what() << endl;
        return 1;
    }

    return 0;
}
