#include<iostream>
#include<string.h>
using namespace std;

class CalculatorApp {

    // access specifier/modifier --> private
    private:

        string name;
        string icon;
        string theme;
    
    // access specifier/modifier --> public
    public:

        // default constructor
        CalculatorApp() {

        }

        // parameterized constructor
        CalculatorApp(string nameValue, string iconValue, string themeValue) {
            name = nameValue;
            icon = iconValue;
            theme = themeValue;
        }

        // functions
        string getName() {
            return name;
        }

        string getIcon() {
            return icon;
        }

        string getTheme() {
            return theme;
        }

        void setTheme(string themeVal) {
            theme = themeVal;
        }

        int plus(int first, int second) {
            return first + second;
        }

        int multiply(int first, int second) {
            return first * second;
        }

        int minus(int first, int second) {
            return first - second;
        }

        int divide(int first, int second) {
            return first / second;
        }

}; 

int main() {
    
	CalculatorApp calculator ("Calculator", "/icon/calculator.jpg", "Light");
	cout << "Name: " << calculator.getName() << endl;
	cout << "Icon: " << calculator.getIcon() << endl;
	cout << "Theme: " << calculator.getTheme() << endl;
	calculator.setTheme("Dark");
	cout << "Theme (after theme change): " << calculator.getTheme() << endl;
	
	int firstNumber = 42, secondNumber = 8;
	cout << "Plus: " << calculator.plus(firstNumber, secondNumber) << endl;
	cout << "Minus: " << calculator.minus(firstNumber, secondNumber) << endl;
	cout << "Multiply: " << calculator.multiply(firstNumber, secondNumber) << endl;
	cout << "Divide: " << calculator.divide(firstNumber, secondNumber);
	return 0;
}