# Classes & Objects

1. Class Defination

    - Attributes of a class

    - Functions of a class

    - Class Members

2. Creating Objects

3. Constructor

    - A constructor is a special type of class function with the name that is the same as the class name. It is used for creating objects of the class it belongs to.

    - Object creation is done through constructors.

    - We do not mention the return type in the constructor function.

    - It is a special function used to create an object of the same class in which the constructor is defined.

    - A constructor with parameters is known as a "parameterized constructor".

    - A constructor without any parameters is known as the "default constructor".

4. Static Class Members

    - Static Class Attribute

        - A static class attribute can be created by adding static keyword before the data type like this:

            ```c++
            static data_type variable_name
            ```

    - Statice Class Function

        - A static class function can be created in the same way by adding a static keyword before it. In this case, before the return type like this:
            
            ```c++
            static return_type function_name(params) {
                //Function logic
            }
            ```

    - There are certain class members(attributes & functions) which we may want to access without creating an object of that class.

    - Note that static class members are not tied to any object and so cannot access any of the non-static class members. Static class members can however access other static class members.