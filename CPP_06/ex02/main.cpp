#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

/*
**  dynamic_cast:
**  dynamic_cast does the same thing as static cast, but
**  the cast occured on run time.
**  It is used for run time polymorphism
*/

Base*   generate(void)
{
    int i = rand() % 3;

    switch(i)
    {
        case (0):
            return (new A());
            break;
        case (1):
            return (new B());
            break;
        case (2):
            return (new C());
            break;
        default:
            break;
    }
    return (NULL);
}

void    identify(Base* p)
{
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);
    if (a)
        std::cout << "A" << std::endl;
    if (b)
        std::cout << "B" << std::endl;
    if (c)
        std::cout << "C" << std::endl;
    return ;
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(const std::exception &e)
    {
        (void)e;
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch(const std::exception &e)
    {
        (void)e;
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch(const std::exception &e)
    {
        (void)e;
    }
    return ;
}

int main(void)
{
    srand(time(0)); //use to initialize rand()

    A a;
    B b;
    C c;

    std::cout << "Value of A, B, C by pointer" << std::endl;
    identify(&a);
    identify(&b);
    identify(&c);
    std::cout << "Value of A, B, C by reference" << std::endl;
    identify(a);
    identify(b);
    identify(c);

    std::cout << "Test" << std::endl;
    {
        Base *test = generate();
        identify(test);
        Base &test1 = *test;
        identify(test1);
        delete (test);
    }
    {
        Base *test = generate();
        identify(test);
        Base &test1 = *test;
        identify(test1);
        delete (test);
    }
    {
        Base *test = generate();
        identify(test);
        Base &test1 = *test;
        identify(test1);
        delete (test);
    }
    {
        Base *test = generate();
        identify(test);
        Base &test1 = *test;
        identify(test1);
        delete (test);
    }
    return (0);
}