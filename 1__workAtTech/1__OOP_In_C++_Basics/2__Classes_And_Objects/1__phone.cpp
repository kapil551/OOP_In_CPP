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