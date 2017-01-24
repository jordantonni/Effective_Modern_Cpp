/*
 * Understand Special member function generation
 * 
 * Default ctor - Generated if no user defined ctor
 * dtor         - Virtual only of base class dtor is virtual, no except
 * copy ctor    - Memberwise copy construction of members, only if no user def move ops or copy assignment
 * copy assign  - Memberwise copy ass of members, only if no user def move ops or copy ctor
 * move ctor    - Memberwise move of members, only of no copy op, move op or dtor
 * move ass     - Memberwise move ass of members, only if no user def copy op, move op or dtor
 * 
 *
 * default
 *  - Can get the default imps if you want them back
 *  
 * Rule of three:
 *  - If you change dtor, copy ctor or copy assignment, you need to change other 2
 *  - Why?
 *      - Typically meant you had a resource management class so:
 *          - 1) Resource management on the copy ops would be different than default (i.e. no a shallow copy)
 *          - 2) Destruction of the resource, i.e. freeing, would be required
 *          
 * Rule of five: Rule of three can be good indication to also change the move operators
 *
 *
 * SUMMARY:
 *  - Member function templates don't stop these being generated.
 *  - Use = default to bring back default generated versions if you want them
 */

namespace item17
{
    class Widget
    {
    public:
        // Default ctor and dtor
        virtual ~Widget() = default;
        Widget() = default;

        // Default copy ops
        Widget(const Widget&) = default;
        Widget& operator=(const Widget&) = default;

        // Default move ops
        Widget(Widget&&) = default;
        Widget& operator=(Widget&&) = default;

    };
}