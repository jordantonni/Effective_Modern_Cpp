/*
 * Prefer scoped enums to unscoped
 * 
 * Declaring a name inside {} limits the scope of the name inside them
 * - This isnt the case with enums
 *  - enum Color { red, white }; red and white now pollute the global namespace
 *
 * Scoped enums don't
 *  - enum class Color { red, white }; 
 * 
 * Scoped enums are strongly typed, cannot be implicitly converted to integral types
 *  - unscoped enums could
 * 
 * Can't forward declare unscoped enums
 *  - Compiler doesn't know their size as they have no default underlying type
 * 
 * Scoped enums have default underlying type of int
 *  - Can be forward declared
 *
 *
 * SUMMARY:
 *  - Better scope
 *  - Only convert to integral types with a cast (safer)
 *  - Specfying underyling type. Default is int
 *  - Can be forward declared
 */

namespace item10
{
    // Use char as underlying type
    enum class Color : char
    {
        red,
        white,
        blue
    };

    void test()
    {
        Color carPaint = Color::red;

        if (0 == static_cast<int>(carPaint)) // Explicit cast to integral type
        { }
    }
}
