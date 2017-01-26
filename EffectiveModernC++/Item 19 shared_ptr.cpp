/*
 * Use shared_ptr for shared ownership of a resource
 * 
 * - Reference counted
 *  - Object pointed to is only deleted once all other shared_ptrs that point to it are deleted
 *  - ctors increment count
 *  - dtors decrement count
 *  - copy ctor inc count of rhs item to copy and decrement count of item *this used to hold
 *  - move ctor no effect on count. Sets old to null 
 *  
 * No support for arrays
 *  - std::shared_ptr<T[]> NOT ALLOWED
 * 
 * - Control Block (Dynamically Allocated)
 *  - Holds ref count
 *  - Weak ptr count
 *  - Custom Deleter (Unlike unique_ptr, does not form part of shared_ptr Type, allows for shared_ptrs with diff deleters to be stored in same container)
 *  - Custom Allocator
 *
 * - Control Block Creation
 *  - make_shared: always make a control block (As it creates the object to manage, so it can't have existed before)
 *  - ctor via unique_ptr: uniq_ptr doesnt have its own control block, so it has to create one. unique_ptr set to null
 *  - ctor via raw ptr: always creates control block
 *  - ctor via shared/weak_ptr: never creates control block
 *  
 * - Issues:
 *  - If you pass same raw pointer multiple shared_ptrs, multiple control blocks are made -> multiple ref counts of same object -> multiple delete calls, BAD!
 *  - Same can happen when adding (this) to a shared_ptr from method call! As this is raw ptr
 *  
 * - Solution:
 *  - Dont pass raw ptr to shared ptr
 *  - Inherit from std::enable_shared_from_this<Class> to allow adding (this) to shared ptr, then call shared_from_this()
 *      - shared_from_this() gets already created control block and make the shared_ptr use that!
 *  
 * SUMMARY:
 *  - shared_ptr can be at least twice as big as unique_ptr due to control blocks
 *  - overhead to use due to atomic reference counting and virtual function for deleter
 *  - custom deleter doesnt form part of type, so shared ptrs to same type but having different deleters can be put in same container
 *  - Don't create shared_ptrs from raw pointers
 */
#include <vector>
#include <memory>

namespace item19
{
    class Widget;
    std::vector<std::shared_ptr<Widget>> processedItems;

    class Widget : public std::enable_shared_from_this<Widget>
    {
    public:
        void process()
        {
            // Putting this into vector<shared_ptr> means passing the raw pointer to it
            // This creates a new control block for that shared pointer
            // If there is another shared_ptr to that same object, they both have their own ref count, so will be deleted twice!
            //            processedItems.emplace_back(this);

            processedItems.emplace_back(shared_from_this()); // This counter acts that and allows this to be added without duplicating control block
        }
    };

    void test()
    {
        std::shared_ptr<Widget> p { new Widget };

        p->process();
        p.reset();
    }
}
