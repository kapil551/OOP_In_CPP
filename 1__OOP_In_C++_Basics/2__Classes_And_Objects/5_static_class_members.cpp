#include<iostream>
#include<string.h>
using namespace std;

class Phone {

    public:

        /* Note that static class members are not tied to any object and so cannot access any of the non-static class members. 
            Static class members can however access other static class members.
        */

        /*
            Here, count and getFormattedCount are both static members. 
            
            Note that getFormattedCount is accessing the count attribute.
        */

        static int count; // static class attribute

        // static class function
        static string getFormattedCount() {

            if (count/1000000000 > 0) {
                return to_string((double) count/1000000000) + "B";
            }
            else if (count/1000000 > 0) {
                return to_string((double) count/1000000) + "M";
            }
            else if (count/1000 > 0) {
                return to_string((double) count/1000) + "K";
            } else {
                return to_string(count);
            }
	    }

};