/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 14, 2018, 2:51 PM
 */

#include <iostream>

class Base {
    int m_x;
public:
    Base(int x = 0) : m_x{x}
    {
    }
    friend class Test; // This is important point here!!!!!!!!!!!
};

class Test {
    int* m_x;
public:
    Test(int val = 0) : m_x{new int(val)}
    {
    }

    void setX(int val) {
        *m_x = val;
    }

    void print() {
        std::cout << "OUTPUT: " << *m_x << '\n';
    }

    ~Test() {
        delete m_x;
    }

    Test& operator=(Test &rhs) { /*assignment operator overloading for same 
                                  * type of classes
                                  */
        if (this != &rhs)
            *m_x = *rhs.m_x;
        return *this;
    }

    Test& operator=(Base &b) {/*assignment operator overloading for different 
                               * type of classes
                               */
        *m_x = b.m_x;
        return *this;
    }

};

int main() {

    Test t1 = 10;
    t1.print();

    Base b = 20;

    t1 = b;
    t1.print();

    return 0;
}

