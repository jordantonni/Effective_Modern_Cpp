/*
 * Use constexpr when possible
 * 
 * constexpr on objects
 *  - Means the object is const
 *  - Value of object will be known at compile time
 *  -> can be put in read-only memory
 *  -> used for integral constant expressions, such as specifying size of array
 *  
 * constexpr on functions
 *  - If arguments provided are constexpr, the function itself will evaluate at compile time
 *  - If not, it will evaluate at runtime as normal
 *  
 * constexpr restrictions on functions
 *  - C++11: could only return a single line
 *  - C++14: Multiple lines, as long as the input and return values are literal types (values that can be determined at compile time)
 *  
 * constexpr ctors
 *  - Making a constexpr ctor means the objects values can be created at compile time
 *      -> allows the instance to be declared as constexpr also
 *      -> used as input to a constexpr function!
 *
 * Use constexpr whenever possible, this means when you are willing to ensure the function will always be constexpr!
 *
 * SUMMARY:
 *  - constexpr objects are const and initialized with values known at compile time
 *  - constexpr functions can return values at compile time if called with constexpr values
 *      - runtime if not. Don't need two different versions!
 *  - constexpr objects and functions can therefore be used in a wider range of areas than non-constexpr
 *  - constexpr defines part of the interface, therefore can't really change it after the fact!
 */

namespace item15
{
    class Widget
    {
        int x;
    public:
        constexpr Widget(const int x_i) noexcept    // Constexpr ctor allows object instance to be used at compile time!
            : x{ x_i }
        {}

        constexpr int getVal() const noexcept
        {
            return x;
        }
    };

    constexpr auto getValPlusWidget(const int val, const Widget& w) noexcept
    {
        return val + w.getVal();
    }


    void test()
    {
        constexpr int x = 1337;
        constexpr Widget w { 69 };

        constexpr int xPlus = getValPlusWidget(x, w); // Works as everything is constexpr 
    }
}
