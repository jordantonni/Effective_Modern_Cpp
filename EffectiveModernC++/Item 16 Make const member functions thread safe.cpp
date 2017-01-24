/*
 * Make const member functions thread safe
 * 
 * const member functions will be treated read-only, therefore runtime system will allow multiple threads to call simultaneously
 * 
 * Logical constness is not the same as bitwise const
 *  - Bitwise const, what compiler enforces, doesnt allow anything member variables to change
 *  - Logical const, what we SHOULD use, doesnt allow any of the meaningful state to change
 *      - i.e. keeping track of how many times function was invoked, or caching data would be allowed in const function
 *      - declaring members as mutable allows us to do this
 *          - Can change a mutable member in a const function
 *      
 * Problem
 *  - these mutable members will give race conditions in multi-threaded code then
 *  
 * Solution
 *  - use std::atomic when only one variable is being change
 *  - use std::mutex and lock it when entering a const method that modifies >1 mutable member
 *
 * SUMMARY:
 *  - Make const member functions thread safe
 *  - std::mutex to lock down a function for single thread access
 *  - std::atmic is faster but only good for manipulation of single variable
 */

#include <mutex>

namespace item16
{
    class Widget
    {
        mutable int cachedVal { 0 };
        mutable std::mutex m;
    public:
        void calcSomething() const  // Thread safe due to mutex! Otherwise would get race condition on cachedVal!
        {
            std::lock_guard<std::mutex> g{m};

            // .. do some calc
            ++cachedVal;
        }
    };

}
