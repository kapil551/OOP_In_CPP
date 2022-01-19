#include<iostream>
#include<string.h>
using namespace std;

class Employee {
    
    private:
        int id;
        string name;
        long salary;
    
    public:
        // parameterised constructor
        Employee(int id, string name, long salary) {
            
            this->id = id;
            this->name = name;
            this->salary = salary;
        }

        //functions/methods

        // getter
        int getId() {
            return id;
        }

        // getter
        string getName() {
            return name;
        }

        // getter
        long getSalary() {
            return salary;
        }

        // setter
        void setId(int id) {
            this->id = id;
        }

        // setter
        void setName(string name) {
            this->name = name;
        }

        // setter
        void setSalary(long salary) {
            this->salary = salary;
        }

};

int main() {
	// your code goes here
	Employee hannibal_lecter(1, "Hannibal Lecter", 10000000);
	Employee norman_bates(2, "Norman Bates", 9000000);
	Employee darth_vader(3, "Darth Vader", 8000000);
	
	darth_vader.setId(327);
	darth_vader.setName("Anakin Skywalker");
	darth_vader.setSalary(7500000);
	
	cout << hannibal_lecter.getId() << " " << hannibal_lecter.getName() << " " << hannibal_lecter.getSalary() << endl;
	cout << norman_bates.getId() << " " << norman_bates.getName() << " " << norman_bates.getSalary() << endl;
	cout << darth_vader.getId() << " " << darth_vader.getName() << " " << darth_vader.getSalary() << endl;
	return 0;
}
