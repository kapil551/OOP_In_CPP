# Encapsulation

1. Introduction:

    - If an app is supposed to allow/disallow you to access/modify a few of its attributes then there is a requirement for access control.

    - This is known as information hiding where one object or function is not allowed to access or modify an attribute of another object.

    - In this specific example, you are allowed to view the name of the app but neither you nor your phone is allowed to modify the name of the app.

    - The app might not allow you to view specific attributes as well such as the number of times you have opened the app. Your actions might indirectly modify that attribute but the app cannot allow you to modify that attribute directly.

    - In Object-Oriented Programming, this is done through "Encapsulation".

    - Encapsulation refers to the bundling of data with the methods that operate on that data. Here, we are bundling all the attributes (data) with the methods to create a class.

    - By doing this we can restrict the direct access to some of an object's members by allowing read/write through other methods only.

    - How do we actually restrict access to attributes?
        
        - ```Access Specifier```

2. Access Specifier/Modifier: public/private

    - Let's look at what public and private means that we saw in the class definition template:

        ```c++
        class ClassName {
            private:
                data_type attribute_name;
                data_type attribute_name;
                .
                .
                .
                return_type function_name( args ) {
                    //Some logic
                }
                
            public:
                data_type attribute_name;
                data_type attribute_name;
                .
                .
                .
                return_type function_name( args ) {
                    //Some logic
                }
                
        };```
    
    - public/private keywords used here are known as access specifiers or access control modifiers.

    - It is used to specify and control the visibility of a class member.
    
        - public: Public class members are accessible everywhere.
        
        - private: Private class members can be accessed only within that class.

    - Note that we can set any class member as private. It is not only for attributes. We use private to restrict access/modification of class members outside the class.


    - Let's make all the attributes of the Phone class as private.

        ```c++
        class Phone {

            private:
                string brand;
                string model;
                int ram;
                int storage;
                
            public:
                Phone () {
                    //any initialization logic
                }
                
                Phone (string brandValue, string modelValue, int ramValue, int storageValue) {
                    brand = brandValue;
                    model = modelValue;
                    ram = ramValue;
                    storage = storageValue;
                }
                
                void dialCall (string number) {
                    cout << "Calling " << number << " from " << brand << ":" << model << "\n";
                }
                
                void receiveCall (string number) {
                    cout << "Receiving call from " << number << " on " << brand << ":" << model << "\n";
                }
        }; 
        ```
    - Now, none of the attributes of the Phone class are accessible to anyone outside the Phone class. We can still access these attributes inside the class. In the above example, we are using them in the constructor and the dialCall and receiveCall methods.

    - Now for an object my_iPhone_11 of class Phone, these things are invalid as the access is present only inside the class Phone:

        ```c++
        my_iPhone_11.brand = "Apple";
        cout << my_iPhone_11.brand;
        ```

    - Whereas these things are still valid:

        ```c++
        Phone my_iPhone_11 ("Apple", "iPhone 11", 4, 64);
        Phone my_iPhone_11 = Phone ("Apple", "iPhone 11", 4, 64);
        my_iPhone_11.dialCall ("9732130450");
        ```
    
    - ```In C++, all class members are by default private. If we do not specify public/private then the class member is treated as private.```

