/*
 *  Understand decltype
 *
 * decltype gives you the type of a name or expression
 * 
 * Used in conjuction with auto to set the return type of a function 
 * 
 *
 * SUMMARY:
 *  - Gives the type of the expression 
 */

namespace item03
{
    // -> return type syntax has to be at the end, as it needs to have seen the parameters, in this case val, before it is came across
    template<typename T>
    auto foo(T val) -> decltype(val.someMehtod())
    {
        // auto specifies that the return type will be deduced
        // ->declytype gets the type of the expression that we will return!
        return val.someMethod();
    }

    // c++14 can do this
    template<typename T>
    decltype(auto) bar(T val)
    {
        // declytype(auto) means deduce the return type, and apply declytype rules i.e. don't strip off references
        return val.someMethod();
    }

}