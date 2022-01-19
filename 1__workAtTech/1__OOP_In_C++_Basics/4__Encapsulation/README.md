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

3. Pointer to Class:

    - As we've previously learned that we can access different properties of an object like this:
    
        ```c++
            object.property
        ```
    - This is known as the dot member selection operator (or simply Dot Operator). It is used to access a class member through the object.

    - Just like variables, objects are also stored in memory and take up some space. Since they are stored in memory, they will also have an address at which they are stored. 
    
    - To get the address of a variable, we use a pointer. Similarly, we can create pointers to class objects as well.

    ```c++
        Phone phone_var("Apple", "iPhone 11", 4, 64);   
        Phone *ptr = &phone_var;
    ```

    - Here ptr is a pointer variable of type Phone* and points to the address of phone_var.

    - Similar to how we can access class members of an object through the dot member selection operator, we can access them through the arrow member selection operator if we've a pointer to the object.

    ```c++
        ClassName object;
        ClassName *obj_ptr = &object;
        cout << obj_ptr->attribute_name
    ```

    ```c++
        Phone phone_var("Apple", "iPhone 11", 4, 64);
        cout << phone_var.brand << endl; //This will print Apple
        Phone *phone_ptr = &phone_var;
        cout << phone_ptr->brand << endl; //This will print Apple
    ```

    - Arrow member selection operator (or simply Arrow Operator) is used to access a class member through a pointer to an object.

    - Note that arrow operators can be used on a class pointer but not on pointers of primitive data types (int, float, etc).

4. ```this``` keyword/pointer:

    - As you must have noticed that while passing a parameter to a constructor or any other class function, we have been using a parameter name that is different from the actual property name.

    - Examples:
        
        ```c++
            Phone (string brandValue, string modelValue, int ramValue, int storageValue) {
                brand = brandValue;
                model = modelValue;
                ram = ramValue;
                storage = storageValue;
            }
            void setBrand(string brandValue) {
                brand = brandVal;
            }
        ```
    
    - We have been using variable names like brandValue, modelValue, ramValue, storageValue, etc instead of brand, model, ram, storage. We are doing to avoid something like this:

        //Note that this will not work
        ```c++
        Phone (string brand, string model, int ram, int storage) {
            brand = brand;
            model = model;
            ram = ram;
            storage = storage;
        }
        ```
    
    - Example of ``this`` pointer

        ```c++
            Phone (string brand, string model, int ram, int storage) {
                this->brand = brand;
                this->model = model;
                this->ram = ram;
                this->storage = storage;
            }
        ```
        ```c++
            void setBrand(string brand) {
                this->brand = brand;
            }
        ```

    - Here, ``this`` pointer refers to a pointer to the actual object on which the function is being called. In the case of a constructor, it is the pointer to the object that will be created by the constructor.

    - In the above example where we're doing:

        ```c++
            this->brand = brand;
        ```
    
    - ```this->brand`` denotes the brand attribute of the object
    - ```brand``` denotes the function parameter 
    
    - ```this``` pointer can be used to reference the object only inside its class. We can use this along with an arrow operator anywhere inside the class to access or modify any attribute in the object or to call a method internally.

    - Note that ```this->``` is mandatory only when we've another variable with the same name as a class member, i.e., when there is ambiguity between a variable name and a class member. This is why we didn't have to use this-> when we were using a different parameter name.

5. ```getters``` and ```setters```:

    - It is always a good idea to keep all the class attributes as private. As we have seen in the previous section, we can expose an attribute, say theme, like this:

        ```c++
            class CalculatorApp {
            private:
                string theme;
            public:
                CalculatorApp (string theme) {
                    this->theme = theme;
                }

                string getTheme() {
                    return this->theme;
                }

                void setTheme(string theme) {
                    this->theme = theme;
                }
            };
        ```

    - These methods are commonly known as ```getters``` and ```setters```. They are widely used in commercial applications where object-oriented programming is used.


