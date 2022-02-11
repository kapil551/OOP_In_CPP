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

3. Compile-time Polymorphism:

    - The word Polymorphism means having many forms (Poly: Many, Morph: Form).

    - Have we seen any form of polymorphism till now in this course?

    - Function Overloading???

    - Operator Overloading???

    - Yes, both function overloading and operator overloading are forms of polymorphism.

        - Function overloading allows us to have a function in different forms (with different implementations)
        - Operator overloading allows us to have an operator in different forms (with different implementations)

    - In both function overloading and operator overloading, the compiler decides which implementation of the function/operator to choose for a particular function call or operation.

    - This type of polymorphism is known as compile-time polymorphism.

    - Why is it not just called polymorphism?

    - It has a specific name 'Compile-time Polymorphism' because there is another type of polymorphism where the implementation is not decided during compile time. We'll learn about it in a later chapter.

4. Function Hiding:

    - As we learned earlier that we can have functions with the same name but differerent parameters through function overloading.

    - We already know that we can have functions with the same method name and same parameters in different classes if the classes are independent of each other. Go through the below code and run it to see what happens.

    - ```c++

            #include <bits/stdc++.h>
            using namespace std;

            class MobilePhone {
            public:
                void print() {
                    cout << "MobilePhone" << endl;
                }
            };

            class Laptop {
            public:
                void print() {
                    cout << "Laptop" << endl;
                }
            };

            int main() {
                MobilePhone mobilePhone;
                Laptop laptop;
                mobilePhone.print(); //This will print "MobilePhone"
                laptop.print(); //This will print "Laptop"
                return 0;
            }

      ```

    - Since these classes are independent of each other, one class does not care about which methods are there in the other class.

    - Now, let's say there are 2 classes and both of them are related through inheritance.

    - ```c++
            #include <bits/stdc++.h>
            using namespace std;

            class BaseClass {
            public:
                void print() {
                    cout << "Base Class" << endl;
                }
            };

            class DerivedClass: BaseClass {
            public:
                void print() {
                    cout << "Derived Class" << endl;
                }
            };

            int main() {
                BaseClass base;
                DerivedClass derived;
                base.print(); //This will print "Base Class"
                derived.print(); //This will print "Derived Class"
                return 0;
            }

            Output:

                Base Class
                Derived Class

      ```
    - Here, we are seeing the same behavior as the case when there was no relationship. The function of the respective class is called. But there is a different reason for it.

    - ```c++

            #include <bits/stdc++.h>
            using namespace std;

            class BaseClass {
            public:
                void print() {
                    cout << "Base Class" << endl;
                }

                void print(int num) {
                    cout << "Base Class " << num << endl;
                }

                void print(string name) {
                    cout << "Base Class " << name << endl;
                }
            };

            class DerivedClass: BaseClass {
            public:
                void print() {
                    cout << "Derived Class" << endl;
                }
            };

            int main() {
                BaseClass base;
                DerivedClass derived;
                base.print(); 
                base.print(42); 
                base.print("workat.tech"); 
                
                derived.print(); 
                derived.print(42); 
                derived.print("workat.tech"); 
                return 0;
            }
      ```
    
    - Here we have created a function named print:

        - in the derived class
        - with the same name as multiple functions in the base class

    - Ideally, all the public members (properties and functions) of the base class should be available through the derived class as well (because of inheritance).

    - So the expected behavior here is:

        - base.print(); //This will print "Base Class"
        - base.print(42); //This will print "Base Class 42"
        - base.print("workat.tech"); //This will print "Base Class workat.tech"
        - derived.print(); //This will print "Derived Class"
        - derived.print(42); //This should ideally print "Base Class 42"
        - derived.print("workat.tech"); //This should ideally print "Base Class workat.tech"
        
    - Now run the above code.

    - After running it, we can see that we get a compilation error because:

        - any function named print from the base class
        - won't be available through the derived class
        
    - This is not the expected behavior, right?

    - This is known as function hiding. Whenever a function with the same name is present in both base class and derived class, the functions with that name in the base class won't be available through the derived class irrespective of the parameters.

    - This is the reason why "Base Class" was getting printed on doing base.print() and "Derived Class" on doing derived.print() in this code:

        - ```c++
                BaseClass base;
                DerivedClass derived;
                base.print(); //This will print "Base Class"
                derived.print(); //This will print "Derived Class"
          ```

5. Function Templates:

    - We have previously learned that we can have multiple functions with the same name but different parameters in the same file/class through Function Overloading.

    - Example

    - ```c++ 
            int max_num (int firstNumber, int secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
            long max_num (long firstNumber, long secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
            float max_num (float firstNumber, float secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
            double max_num (double firstNumber, double secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }

            int main() {
                int firstInt = 5, secondInt = 7;
                float firstFloat = 3.14159, secondFloat = 2.71828;
                long firstLong = 54362478632846, secondLong = 7148342783278;
                double firstDouble = 2.71828182845, secondDouble = 3.1415926535;
                
                cout << max_num(firstInt, secondInt) << endl;
                cout << max_num(firstFloat, secondFloat) << endl;
                cout << max_num(firstLong, secondLong) << endl;
                cout << max_num(firstDouble, secondDouble) << endl;

            }
      ```
    
    - This is a very valid use case but the issue here is that we have to write a lot of code with the exact same logic. If you notice carefully, the only difference between these functions is the data types being used. Each of the above functions can be logically written as:

    - ```c++
            data_type max_num (data_type firstNumber, data_type secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
      ```

    - Won't it be great if we can just write like this and the compiler takes care of all the other stuff. Turns out that C++ actually allows us to achieve this type of polymorphism through something known as TEMPLATES!

    - ```c++

            #include <bits/stdc++.h>
            using namespace std;

            template <class data_type>
            data_type max_num (data_type firstNumber, data_type secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }

            int main() {
                int firstInt = 5, secondInt = 7;
                float firstFloat = 3.14159, secondFloat = 2.71828;
                long firstLong = 54362478632846, secondLong = 7148342783278;
                double firstDouble = 2.71828182845, secondDouble = 3.1415926535;
                
                cout << max_num(firstInt, secondInt) << endl;
                cout << max_num(firstFloat, secondFloat) << endl;
                cout << max_num(firstLong, secondLong) << endl;
                cout << max_num(firstDouble, secondDouble) << endl;
                
                return 0;
            }
      ```
    
    - As you can see that we have been able to replace the four functions with just a single function by using templates. 
    
    - Let's look at how to use templates:

        - ```c++
            template <class identifier>
          ```

    - Here,

        - template is a keyword to tell the compiler that we are creating a template.
        - class is used to tell the compiler that we are creating a datatype or class template.
        - identifier is used to tell the compiler what the name of the template would be. This is similar to naming a variable or macro and could be almost anything that we want to name it. In the above example it is data_type.

    - Now, we would have to replace the data types everywhere in the function where we want to use a template data type which we have done like this in the above code:

    - ```c++
            data_type max_num (data_type firstNumber, data_type secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
      ```

    - In the above code, we have replaced the actual data types with the template type that we created.

    - Now how this works internally is that during compilation, whenever the compiler comes across any function calls to a template function, it creates a new function based on the data types of the arguments.

    - The newly created function is then used for that particular function call.

    - In our above example, all the 4 functions that we replaced with the template function will be created by the compiler as all 4 of them are supposed to be used in the main method.

    - Note: the function body needs to be exactly same across multiple functions to replace them with a template function.

    - Note: For the identifier (template name), a shorter name like T is commonly used which we will be using henceforth. Use T as the template name instead of "data_type" (the name that we used in the previous example).

    - ```c++
            template<class T>
            T max_num (T firstNumber, T secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
      ```

    - Now, let's take another case.

    - In the max_num example, let's say that we had to find the max of firstLong and firstInt like this:

        - ```c++ 
                cout << max_num(firstLong, firstInt) << endl;
          ```
    - Here, the return type is supposed to be long.

    - Our template function won't work because both the parameters have the same template data type in our template function whereas in the function call, we have long and int data as arguments. A function which can take these two as arguments can't be produced from this template function.

    - ```c++ 
            template <class T>
            T max_num (T firstNumber, T secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
      ```
    
    - What can we do now?

    - Just like having a template data type T, we can have another data type, say, U. We can rewrite the above code as:

    - ```c++
            template <class T, class U>
            T max_num (T firstNumber, U secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
      ```
    - Here, what is happening is that the first parameter will take data of type T, the second parameter will take data of type U and the function will return data of type T.

    - In our example with long and int, the compiler will use this template to create a function like this:

    - ```c++
            long max_num (long firstNumber, int secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
      ```
    - So now our problem is solved! Will this also work for (int, int), (float, float), (long, long), (double, double)?

    - The answer is yes. Here, T and U are independent of each other. T can be any data type, U can be any data type independent of each other. So it is possible to have T being int and independently U also being int.

    - Therefore, we can use the above template method for all the 5 use cases:

        - (int, int)
        - (float, float)
        - (long, long)
        - (double, double)
        - (long, int)
    
    - As you can notice, the template is not just restricted to these 5 pairs of arguments. (int, long), (float, int) and any other pair of data types will be valid here.

    - Let's rewrite the previous code to use the template with T and U:

    - ```c++
            #include <bits/stdc++.h>
            using namespace std;

            template <class T, class U>
            T max_num (T firstNumber, U secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }

            int main() {
                int firstInt = 5, secondInt = 7;
                float firstFloat = 3.14159, secondFloat = 2.71828;
                long firstLong = 54362478632846, secondLong = 7148342783278;
                double firstDouble = 2.71828182845, secondDouble = 3.1415926535;
                
                cout << max_num(firstInt, secondInt) << endl;
                cout << max_num(firstFloat, secondFloat) << endl;
                cout << max_num(firstLong, secondLong) << endl;
                cout << max_num(firstDouble, secondDouble) << endl;

                //Newly added function calls. All of these are valid and will work
                cout << max_num(firstLong, firstInt) << endl;
                cout << max_num(firstInt, firstLong) << endl;
                cout << max_num(firstDouble, firstFloat) << endl;
                cout << max_num(firstDouble, firstInt) << endl;
            }
      ```

    - As we can see that the template can take both class and primitive data types (int, float, long, etc), it must be obvious that we can create a template where a class object is passed as a parameter as well.

    - Examples:
    
    - ```c++
            template <class T>
            T max_obj (T firstObject, T secondObject) {
                if (firstObject.some_attribute > secondObject.some_attribute) {
                    return firstObject;
                }
                return secondObject;
            }
       ```
    
    - ```c++
            template <class T, class U>
            int func (T firstObject, U secondObject) {
                int result = 0;
                //Some logic
                return result;
            }
       ```
    
    - FYI:

    - In case of templates, we've been calling the functions like this:

    - ```c++
            cout << max_num(firstInt, secondInt) << endl;
      ```

    - Here, we are relying on the compiler to deduce the type/class of the arguments and use the right function accordingly.

    - There is a way in which instead of relying on the compiler to deduce the type/class, we can specify it to the compiler directly.

    - For the below template function with only a single type/class:

    - ```c++
            template <class T>
            T max_num (T firstNumber, T secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
      ```

    - We can do like this:

    - ```c++
            cout << max_num<int>(firstInt, secondInt) << endl;
      ```

    - For the below template function with more than one template type/class:

    - ```c++
            template <class T, class U>
            T max_num (T firstNumber, U secondNumber) {
                if (firstNumber > secondNumber) {
                    return firstNumber;
                }
                return secondNumber;
            }
      ```
    
    - We can do like this for (int, int):

    - ```c++ 
            cout << max_num<int, int>(firstInt, secondInt) << endl;
      ```

    - For (long, int):

    - ```c++
            cout << max_num<long, int>(firstLong, firstInt) << endl;
      ```

    - This is just an FYI. In general, we might not have to do this.
