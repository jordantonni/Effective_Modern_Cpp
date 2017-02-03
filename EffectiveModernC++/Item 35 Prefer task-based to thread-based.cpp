/*
 *
 *
 *
 *
 * SUMMARY:
 *  -
 */

#include <iostream>
#include <future>

namespace item35
{
    void foo()
    {
        std::cout << "foo()\n";
    }

    int bar()
    {
        std::cout << "bar()\n";
        return 1337;
    }

    void test()
    {
        for (int i = 0; i < 20; ++i)
        {
            auto fut = std::async(std::launch::async, foo);
            auto f = std::async(std::launch::async,bar);
            auto hjds = std::async(std::launch::async, foo);
            auto hdfj = std::async(std::launch::async,bar);
            auto hfje = std::async(std::launch::async, foo);
            auto uer = std::async(std::launch::async,bar);
        }

    }
}
