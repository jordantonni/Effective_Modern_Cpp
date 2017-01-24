/*
 *  Prefer nullptr to 0 and NULL
 *
 * - Don't overload on pointer and integral types
 *  - 0 is an int, NULL is a define
 *  - Overloading on pointers that are set to NULL or 0 can end up calling the function for an int, not a pointer
 *  
 * nullptr
 *  - type nullptr_t
 *  - implicitly converts to all pointer types
 *
 * Templates
 *  - Type deduction will define 0 and NULL to be integral types
 *  - Wont be able to call a function taking a smart pointer with them
 *
 *
 * SUMMARY:
 *  - Use nullptr 
 *  - Don't use NULL or 0
 *  - Don't overload on integral types or pointer types
 */

#include <memory>
#include <mutex>

namespace item08
{
    class Widget
    {};

    int f1(std::shared_ptr<Widget> spW)
    {
        return 1;
    }

    double f2(std::unique_ptr<Widget> upW)
    {
        return 2;
    }

    bool f3(Widget* pW)
    {
        return true;
    }

    template <typename FunctionType, typename MutexType, typename PtrType>
    decltype(auto) lockAndCall(FunctionType func, MutexType& mux, PtrType ptr)
    {
        std::lock_guard<MutexType> lock(mux);
        return func(ptr);
    }

    std::mutex m1, m2, m3;

    void test()
    {
        //        auto result1 = lockAndCall(f1, m1, 0);    // PtrType -> int, can't convert int to shared pointer in f1 call
        //        auto result2 = lockAndCall(f2, m2, NULL); // PtrType -> int, same as above for f2 call
        auto result3 = lockAndCall(f3, m3, nullptr);    // Works as nullptr is convereted to any pointer type, so f3 is fine
    }
}
