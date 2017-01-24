/*
 * Use alias declarations over typedefs
 *
 * alias templates
 *  - template <typename T>
 *    using MyList = std::List<T, MyAlloc<T>>;
 *  
 *  - This had to be hacked together using nested typedefs in templated structs before
 *  
 * Don't have to use typename keyword to declare variables of templated alias types
 *  - Had to do this using old nested typdef inside template class before
 *  - Why? Because alias declaration is a type, not a dependent type unlike above method
 *  
 * type_traits
 *  - Alow you to remove const, reference to add lvalue ref to types
 *      - std::remove_const<T>::type
 *  
 *  - C++11 aliases provide modern way to do it wihtout havint to use nested ::type
 *      - std::remove_const<T>
 *
 *
 * SUMMARY:
 *  - alias declarations support templatization
 *  - don't have to use ::type suffix from structs
 *  - don't have to use typename in templates to refer to it
 *  - type traits transforms in C++14 have alias versions
 */

#include <list>

namespace item09
{
    class Widget
    {};

    // Old way to define a synonym for a templated List 
    template <typename T>
    struct MyList
    {
        typedef std::list<T> type; // Nested typedef
    };

    // To use it as a type for a variable in another template, have to precede it with typename
    template <class T>
    class aggre
    {
        typename MyList<T>::type wid_list; /* Have to specify ::type is a typename, as it is dependent on T
                                            * if T was a type that MyList was specialized on, it could be something else!
                                            */
    };

    // New way of doing it with alias
    template <typename T>
    using MyTList = std::list<T>;

    void test()
    {
        aggre<int> myAggre;
    }
}
