#include<iostream>
#include<string.h>
using namespace std;

// base class
class Vehicle {

    private:
        string brand;
    
    public:

        Vehicle(string brand) {
            this->brand = brand;
        }

        string getBrand() {
            return brand;
        }

        void honk() {
            cout << brand << " is honking" << "\n";
        }
};

// dependent/derived class
class Car: public Vehicle {

    private:
        string model;
    
    public:
        Car(string brand, string model): Vehicle(brand) {
            this->model = model;
        }

        string getModel() {
            return model;
        }
        void move() {
            cout << getBrand() << " " <<model << " is moving" << "\n";
        }

};

int main() {
	
	Vehicle vehicle("Tesla");
	Car car("Tesla", "Model S");
	cout << vehicle.getBrand() << endl;
	vehicle.honk();

	cout << car.getBrand() << " " << car.getModel() << endl;
	car.honk();
	car.move();
	return 0;
}
