#include<iostream>
#include<string.h>
using namespace std;

class Employee {

    public:
        // attributes
        int id;
        string name;
        long salary;

        // parameterized_constructor
        Employee(int idValue, string nameValue, long salaryValue) {
            id = idValue;
            name = nameValue;
            salary = salaryValue;
        }
};

int main() {

	Employee hannibal_lecter(1, "Hannibal Lecter", 10000000);
	Employee norman_bates(2, "Norman Bates", 9000000);
	Employee darth_vader(3, "Darth Vader", 8000000);
	
	cout << hannibal_lecter.id << " " << hannibal_lecter.name << " " << hannibal_lecter.salary << endl;
	cout << norman_bates.id << " " << norman_bates.name << " " << norman_bates.salary << endl;
	cout << darth_vader.id << " " << darth_vader.name << " " << darth_vader.salary << endl;
	return 0;
}