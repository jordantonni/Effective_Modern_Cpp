/*
 * Use explicitly typed initializer idiom to force auto to correct type
 * 
 * auto can deduce the wrong type of variable due to proxy types being used in libraries, such as in std
 * 
 * Proxy type:
 *  Used to support features that the underlying real type doesnt support
 *      -e.g. vector<bool> stores bools as bits, therefore can't have a reference to individual one
 *      - vector<bool>::reference is a proxy type to support that, so operator[] returns that type
 *      - auto will deduce its type to be of that, and not bool!
 *      
 * Need to force auto to use correct type via:
 *  - auto featureFive = static_cast<bool>(features(w)[5])
 *
 *
 * SUMMARY:
 *  - Inivisible proxy types can cause auto to deduce the wrong type for a variable
 *  - Explicitly typed initializer idiom can force the correct type deduction
 */

#include <vector>

namespace item06
{
    class Widget
    {};

    std::vector<bool> features(Widget& w);

    void test()
    {
        /*
         * Calling something such as:
         * 
         * Widget w;
         * auto featureFive = features(w) [5];
         * 
         * would fail as vector<bool> has a nested proxy type for storing bools as bits, therefore it returns a ::reference instead of a bit reference 
         * from operator[], as bit reference is not allowed
         * 
         * autos' type is deduced as vector<bool>::reference
         * Should be bool
         */
    }
}
