/*
 * Prefer using make_shared and make_unique over new
 * 
 * make_shared, make_unique, allocate_shared:
 *  - take variadic number of arguments
 *  - perfect forward them to ctor of type T
 *  - return smart pointer to dynamically allocated object on heap
 *  
 * Allocate_shared:
 *  - Just wraps the object in a shared_ptr but allocates memory using a custom allocater
 *  
 * Pros:
 *  1) Can use with auto and reduce code duplication in specifying the type to construct
 *  
 *  2) Exception safe:
 *      - foo(shared_ptr<Widget>(new Widget), getPriority());
 *          - getPriority can be invoked between newing Widget and passing the object to shared_ptr ctor
 *          - Exception in getPriority at that point will cause resource leak
 *      -foo(make_shared<Widget>(), getPriority()); 
 *          - make_shared alloactes the new object and stores it in shared_ptr as a single action
 *          
 * Cons:
 *  1) Can't pass custom deleter to shared_ptrs using make_shared or make_unique
 *  2) Templated make_shared / make_unqiue functions perfect forward args to ctors using parenthesis, not braces
 *      -> Can't pass initializer_list as argument to the ctor of type
 *          
 * Shared_ptr only pro:
 *  1) Control block efficiency
 *      - using new with shared_ptr does memory allocation for object, then another for the control block of the shared_ptr
 *      - make_shared allocates both object and control block in same memory allocation
 *      
 * Shared_ptr only con:
 *  1) make_shared allocates sizeof(object) + sizeof(control block)
 *      -> Can't be used with a class that defines its own operator new and delete, they will get sizes wrong
 *  
 *  2) Because control block and object are stored in same memory allocation, object can't be deleted until no weak_ptrs have references to it
 *
 * SUMMARY:
 *  - make functions are faster, more efficient in space and more exception safe than passing new smart pointer ctor
 *  - Can't use make functions when using custom deleters or passing braced initializers to type
 *  - don't used make_shared if type has custom memory management
 */

#include <memory>
#include <iostream>

namespace item21
{
    struct Widget
    {
        void foo()
        {
            std::cout << "foo()" << std::endl;
        }
    };

    void bar(const std::shared_ptr<Widget> sp)
    {
        sp->foo();
    }

    void test()
    {
        using namespace std;

        shared_ptr<Widget> sp1 { new Widget };
        auto sp2 { make_shared<Widget>() };

        unique_ptr<Widget> up1 { new Widget };
        auto up2 { make_unique<Widget>() };

        sp1->foo();
        sp2->foo();

        up1->foo();
        up2->foo();
    }
}
