/*
 * Distinguish between () and {} when creating objects
 *
 * Uniform Initialization A.K.A Braced Initialization
 *  - Works with all types
 *      - Initializer_list ctor
 *      - Default initialization for non-static data members
 *      - Initialize uncopyable objects: std::atomic<int> ai { 0 };
 *      
 * C++ Most Vexing Parse:
 *  - Anything that can be parsed as a declaration in C++ must be interpreted as one
 *      - Widget() - Doesn't call default ctor, instead declares a function returning a Widget!
 *  - Widget{} - Using uniform initialization correctly calls default ctor
 *  
 * 
 * Bad relationship with initializer_lists and ctors:
 *  - Using uniform initialization will pretty much ALWAYS call a ctor that has an initializer_list as it's paramter
 *      - Even when other ctors have the exact same types for the arguments being passed in
 *  -> Results in casting being done when it doesnt need to and the wrong ctors being called
 *
 *
 * SUMMARY:
 *  - Braced initialization is the most widely usable initialization syntax
 *      - Stops narrowing conversions and most vexing parse
 *  - Ctor overload resolution with braced initialization will always try to favour ctor with initializer_list
 *      - Not want you want most of the time
 *  - std::vector<numeric_type> ctor behaves diffierently depending on if you use braced initializer or normal parens
 *      - vector<int> (10,20) -> {20, 20, 20, 20, 20, 20, 20, 20, 20, 20}
 *      - vector<int> {10,20} -> {10, 20}
 */

#include <initializer_list>

namespace item07
{
    class Widget
    {
    public:
        Widget()
        {}// Default ctor
        Widget(std::initializer_list<int> il)
        {} // Init list ctor
    };

    void test()
    {
        Widget w1;  // Default ctor
        Widget w2{};// Init list ctor with empty list
        Widget w3();// Vexing parse -> declares a function!
        Widget{{}}; // Calls default ctor, using the braced initializer syntax!
    }
}
