/*
 * Use weak_ptr to point to shared_ptr managed objects that can dangle
 * 
 * weak_ptr is an augmentation of shared_ptr
 *  - Can't be dereferenced itself
 * 
 * Doesn't affect reference count of shared_ptr
 *  - Control block for shared_ptr has a weak count though, it increment this
 * 
 * Derefernce to use?
 *  - Can't just check if it's non dangling then use it, other thread could delete it between the test and use
 *  - Need to lock it, done via weak_ptr::lock()
 *      - Converts the weak_ptr into a shared_ptr and returns that
 *      
 * Good to use of things such as:
 *  - Cache of object 
 *  - Observer pattern for each subject to keep track of the observers it has
 *  - Stop circular references from not deleting
 *  
 * Note: when a weak_ptr checks to see if it has expired, it does so via checking the reference count in the shared_ptr control block
 *  - Not the weak_count
 *  
 * SUMMARY:
 *  - Use weak_ptr for shared_ptrs than may dangle
 *  - caching, observer lists and prevention of shared_ptr cycles
 */

#include <memory>

namespace item20
{
    class Widget
    {};

    void test()
    {
        std::shared_ptr<Widget> spW { new Widget };

        std::weak_ptr<Widget> wpW { spW };  // Doesnt add to reference count, can dangle, can't dereference itself

        std::shared_ptr<Widget> useWeakPtr = wpW.lock();    // Returns a shared_ptr from weak_ptr, can use this
    }
}
