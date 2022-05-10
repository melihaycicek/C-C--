// C++ program to demonstrate the working of friend class

#include <iostream>
using namespace std;

// forward declaration
class ClassB;

class ClassA : deneme {
    public:
        int numA;

        // friend class declaration
        friend class ClassB;
        struct test
        {
            /* data */
        };
        

    public:
        // constructor to initialize numA to 12
        ClassA() : numA(12) {}
};



