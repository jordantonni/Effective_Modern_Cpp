/*
 * 
 *
 *
 *
 *
 * SUMMARY:
 *  -
 */
#include <iostream>
#include <string>
#include <iostream>

namespace item23
{
    class Widget
    {
    public:
        int size;

        Widget(const int si)
            : size{ si }
        {
            std::cout << "Ctor" << std::endl;
        }

        ~Widget()
        {};

        Widget(const Widget& rhs)
            : size{ rhs.size }
        {
            std::cout << "Copy ctor" << std::endl;
        }

        Widget(Widget&& rhs)
            : size { rhs.size }
        {
            std::cout << "Move ctor" << std::endl;
        }

        Widget& operator=(const Widget& rhs)
        {
            if (this != &rhs)
            {
                size = rhs.size;
            }
            std::cout << "Copy assignment" << std::endl;
            return *this;
        }
    };

    Widget foo(Widget& w)
    {
        std::cout << "foo()" << std::endl;
        w.size = 1337;
        Widget retVal { w.size };

        return retVal;
    }


    void test()
    {
        Widget w1 { 10 };

        foo(w1);
    }
}
