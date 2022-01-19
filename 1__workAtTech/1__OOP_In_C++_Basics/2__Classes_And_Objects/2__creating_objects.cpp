#include <iostream>
#include <string.h>
using namespace std;

class Phone {
    
    public:
        // attributes of class Phone
        string brand;
        string model;
        int ram;
        int storage;

        // functions of class Phone
        void dialCall(string number) {
            cout << "Calling " << number << " from " << brand << ":" << model << "\n";
        }

        void receiveCall(string number) {
             cout << "Recieving Calling from " << number << " on " << brand << ":" << model << "\n";
        }
    

};

int main() {

    // creating objects
    Phone my_iPhone_11;
    Phone my_iPhone_xs;
    Phone my_oneplus_7;

    // we can access class members using the dot(.) operator on the object
    my_iPhone_11.brand = "Apple";
    my_iPhone_11.model = "iPhone 11";
    my_iPhone_11.ram = 4;
    my_iPhone_11.storage = 64;

    // calling the class functions
    my_iPhone_11.dialCall("1010101010");
    my_iPhone_11.receiveCall("2323232323");

    return 0;
}