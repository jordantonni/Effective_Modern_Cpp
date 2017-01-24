/*
 *  Declare overriding functions override
 *  
 * For overriding to occur:
 *  - Base function must be virtual
 *  - Function name must be same ( bar dtors )
 *  - Params the same
 *  - const the same
 *  - return type same
 *  - exception specifications same
 *  - reference qualifiers must be same
 *  
 * Override ensures that you arent defining a new method, but instead that you are overridng base method implementation
 * 
 * Contextual Keywords (only reserved in certain contexts)
 *  - override, at end of member function declaration
 *  - final, at end of member function declaration or after class name declaration
 *      - Disallows overriding or inheritance of method, class respectively
 *      
 * Member function reference qualifiers
 *  - Similar to const, allow you to specifiy different versions of member methods
 *      - What version is invoked depends on if the instance is an lvalue or an rvalue
 *
 * SUMMARY:
 *  - Declare overriding functinons as override
 *  - Member function reference qualifiers allow you to overload methods if they are called with lvalue or rvalue instances of (*this)
 *      - Same as const ^^
 */

#include <iostream>

namespace item12
{
    // Reference Qualifiers
    class Widget
    {
    public:
        void doSomething() &
        {
            std::cout << "Called from an lvalue instance" << std::endl;
        }

        void doSomething() &&
        {
            std::cout << "Called from an temporary rvalue instance" << std::endl;
        }
    };

    void test()
    {
        Widget lval;
        lval.doSomething(); // invokes 1st method
        std::move(lval).doSomething(); // invokes 2nd method
    }
}
