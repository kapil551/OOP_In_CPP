#include <iostream>
#include <string.h>
using namespace std;

class Phone {

    public:

        // attributes of class
        string brand;
        string model;
        int ram;
        int storage;
    
    // default constructor
    Phone() {

    }

    // parameterized constructor
    Phone(string brandValue, string modelValue, int ramValue, int storageValue) {

        brand = brandValue;
        model = modelValue;
        ram = ramValue;
        storage = storageValue;
    }
    
    // functions of class
    void PhoneDetails() {
        cout << brand << " " << model << " " << ram << " " << storage << " \n";
    }
    
    void dialCall(string number) {
        cout << "Calling " << number << " from " << brand << ":" << model << "\n";
    }

    void receiveCall(string number) {
        cout << "Receiving call from " << number << " on " << brand << ":" << model << "\n";
    }
};

int main() {

    // creating objects with parameterized constructor
    Phone my_iPhone_11 = Phone("Apple", "iPhone 11", 4, 64);
    Phone my_iPhone_xs = Phone("Apple", "iPhone XS", 4, 64);
    Phone my_oneplus_7t = Phone("OnePlus", "7t", 8, 128);

    // // initialize the objects
    // my_iPhone_11.brand = "Apple";
    // my_iPhone_11.model = "iPhone 11";
    // my_iPhone_11.ram = 4;
    // my_iPhone_11.storage = 64;

    // my_iPhone_xs.brand = "Apple";
    // my_iPhone_xs.model = "iPhone XS";
    // my_iPhone_xs.ram = 4;
    // my_iPhone_xs.storage = 64;

    // my_oneplus_7t.brand = "OnePlus";
    // my_oneplus_7t.model = "7t";
    // my_oneplus_7t.ram = 8;
    // my_oneplus_7t.storage = 128;

    // calling the class functions
    // my_iPhone_11.PhoneDetails();
    my_iPhone_11.dialCall("9732130450");
    my_iPhone_11.receiveCall("9732130450");

    // my_iPhone_xs.PhoneDetails();
    my_iPhone_xs.dialCall("9732130450");
    my_iPhone_xs.receiveCall("9732130450");

    // my_oneplus_7t.PhoneDetails();
    my_oneplus_7t.dialCall("9732130450");
    my_oneplus_7t.receiveCall("9732130450");

    return 0;
}