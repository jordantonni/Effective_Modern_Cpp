/*
 * pImpl idiom, use unique_ptr and define generated member methods in implementation
 *
 *
 * unique_ptr is perfect for storing implementation class
 *  - Will be destructed once the normal class goes out of scope automatically
 *  
 * Be wary of:
 *  - Default dtor of class can be left, as the unique_ptr to impl class will be deleted by default dtor just fine
 *  - problem is that the default dtor generated is inline and will just have its code to delete the unique_ptr put at the closing scope below
 *      - at this point the impl class is not defined, it is an incomplete type, and so the static_assert in unique_ptr will fail
 *  
 *  -Solution is to ensure when the dtor is called, it has seen the definition for impl class
 *      - Do this via declaring the dtor as default in the implementation file
 *      - This means the default dtor will still be used, which is fine, BUT
 *      - No longer inline, which means its code isnt just pasted at the point of closing scope where impl def hasnt been seen
 *      - it is instead invoked at a time when impl is a complete type
 * 
 *
 * Copy operations:
 * 
 * 
 * 
 * Shared_ptr extras:
 *  - unique_ptr deleter is part of its type, -> things it deletes must be known at compile type -> types much be complete (to know how to delete them)
 *  - shared_ptr deleter is not part of type, and so deleter can be sorted out at run time
 *
 * SUMMARY:
 *  - 
 */

#include "Widget.hpp"

namespace item22
{
    void test()
    {
        Widget w;
        w.foo();
    } // Will invoke Widgets' destructor on w
}
