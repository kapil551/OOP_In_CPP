# Polymorphism

1. Function Overloading:

    - Let's say that we want to create a program where:

        - We can find the maximum of two integers
        - We can find the maximum of two decimals (double)
        - We can find the maximum of three integers
        - We can find the maximum of three decimals (double)

    - Since it is not possible to create functions with the same variable names in C, what we can do here is:

    - ```c++

            int max_two_integers (int firstNumber, int secondNumber) {
                //Logic for finding max of 2 numbers
            }
            double max_two_decimals (double firstNumber, double secondNumber) {
                //Logic for finding max of 2 numbers
            }
            int max_three_integers (int firstNumber, int secondNumber, int thirdNumber) {
                //Logic for finding max of 3 numbers
            }
            double max_three_decimals (double firstNumber, double secondNumber, double thirdNumber) {
                //Logic for finding max of 3 numbers
            }
      ```
    
    - Does not look good, right?

    - C++ was created to allow writing clean, structured code and so it allows us to create functions with the same name (with different parameters).

    - In C++, we can do something like this:

    - ```c++

            int max_num (int firstNumber, int secondNumber) {
                //Logic for finding max of 2 numbers
            }
            double max_num (double firstNumber, double secondNumber) {
                //Logic for finding max of 2 numbers
            }
            int max_num (int firstNumber, int secondNumber, int thirdNumber) {
                //Logic for finding max of 3 numbers
            }
            double max_num (double firstNumber, double secondNumber, double thirdNumber) {
                //Logic for finding max of 3 numbers
            }
      ```
    
    - This is known as function overloading.

    - Function overloading is the ability to create multiple functions with the same name but different implementations.

    - What basically happens here is that when the code is getting compiled, the compiler tries to select the correct method for each of function calls based on the arguments being passed (number of arguments and data types of those arguments).

    - **Note that this is not valid**:

    - ```c++ 
            int divide (int numerator, int denominator) {
                return numerator/denominator;
            }
            float divide (int numerator, int denominator) {
                return numerator/((float) denominator);
            }
      ```

    - Here, even though the implementation and return type is different, the number of parameters and the data types are still the same. That's why it is not valid. Function Overloading allows us to create functions with the same name with different parameters only.