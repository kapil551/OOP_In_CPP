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

2. Operator Overloading:

    - We've learned about complex numbers and how to find its sum in the previous section. When we can use + to get the sum of two integers, decimals, etc, why can't we do the same with complex numbers?

    - Because it is not an in-built data type.

    - If we do ```firstComplexNumber + secondComplexNumber```, the compiler won't understand how to do it because it just knows that these are objects of class ComplexNumber and don't know anything about how to do any operation on them.

    - So what if we can tell the compiler how to do an operation on it?

    - C++ allows us to do that through something known as "operator overloading".

    - Operator overloading is similar to function overloading in a way that instead of the same function name, we have the same operator behaving differently depending on the parameters.

    - We can assume that the internal implementation of + operator is somethign like this:

    - ```c++

            //Here "operator +" denotes a function which does + operation on the parameters
            int operator + (int firstNumber, int secondNumber) {
                //Some internal implementation
            }

            float operator + (float firstNumber, float secondNumber) {
                //Some internal implementation
            }

            long operator + (long firstNumber, long secondNumber) {
                //Some internal implementation
            }

            double operator + (double firstNumber, double secondNumber) {
                //Some internal implementation
            }
      ```
    
    - Now let's create an overloaded + operator for class ComplexNumber as well.

    - This is the sum method that we created in the previous section:

    - ```c++
            ComplexNumber operator + (ComplexNumber firstNumber, ComplexNumber secondNumber) {
                int real_part = firstNumber.getRealPart() + secondNumber.getRealPart();
                int imaginary_part = firstNumber.getImaginaryPart() + secondNumber.getImaginaryPart();
                return ComplexNumber(real_part, imaginary_part);
            }
      ```
    
    - What basically happens here is that when the code is getting compiled, the compiler tries to select the correct implementation for each of the operations based on the arguments (operands) being passed (operated on). There is an implementation present internally for each of the operations that we've been doing until now on in-built data types. So during compilation, the compiler tries to find the correct implementation. If it is unable to find for the set of operands then it gives an error.

    - Note that operator overloading is not limited to arithmetic operators. Almost all operators including arithmetic, relational, logical, assignment, etc can be overloaded.

    - **Syntax of operator overloading is**:

    - ```c++
            return_type operator op (data_type param1, ...) {
        }
      ```

    - In the above example:

    - ```c++ 
            ComplexNumber operator + (ComplexNumber firstNumber, ComplexNumber secondNumber) {
                //Addition Logic
            }
      ```

    - This type of function is known as operator function. The function name is "operator" followed by the operator symbol.