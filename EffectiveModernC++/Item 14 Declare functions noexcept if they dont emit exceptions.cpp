/*
 * Declare functions noexcept if they dont emit exceptions
 * 
 * C++98 exception specifiers werent very good
 *  - throw() meant doesnt thorow exceptions
 *  - Wasnt enforced and was too hard to maintain
 * 
 * C++11
 *  - Only cares if function does or doesnt throw
 *  - noexcept means function guarantees it wont throw exception
 *  
 * Faster code for noexcept functions
 *  - Compilers don't have to set up stack unwinding semantics for noexcept functions
 * 
 * Move operations
 *  - std::vector allcocates more memory for itself when size > capacity
 *      - All items are either copied or moved if they support it
 *  - Push back provides stron exception guarantee as if all the copies dont work, the original vector state is fine
 *      - Move operations thus need to be no except to allow vector<T>::push_back to provde same guarantee
 *      - Therefore, std::containers will only take advantage of move operations of they are noexcept!
 *      
 *      Move if you can, copy if you must. Strategy.
 *      
 * Std::swap
 *  - Swap is used by many STL algorithims and containers
 *  - std::swap being noexept depends on if user-defined swaps are noexcept
 *  
 * Conditionally noexcept
 *  - noexcept (noexcept(swap(a*b))) appears at end function declaration
 *  - Says functions is only noexcept of other thing is noexcept also
 * 
 * Narrow and Wide contracts
 *  - Wide Contract: No preconditions, no constraints on arguments
 *  - Narrow Contract: Preconditions on if it can be called, constrains on arguments passed in
 *  
 *  - noexcept on narrow contracts are hard as they can do undefined behaviour on bad input
 *  - Reserve noexcept for wide contracts
 *
 *
 * SUMMARY:
 *  - Declare a function noexept if you are sure it doesnt throw and are willing to maintain that it never will
 *  - noexcept is part of interface, callers will depend on it
 *  - more optimizable
 *  - Very valuable on move operations, swap, memory dealloc functions and dtors
 *  - Most functions are exception neutral though so don't try and put on everything
 */

namespace item14
{
    
}