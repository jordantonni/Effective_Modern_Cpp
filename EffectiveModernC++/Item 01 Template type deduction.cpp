/*
 *  Understand template type deduction
 *  
 *  template<typename T>
 *  void foo (ParamType p)
 *
 * The type of the expression / argument sent to a template is used in two ways:
 *  1) Deduce the type for T
 *  2) Deduce the type for the Parameter in the parameter list
 *  
 * Depending on the type declared for the paramter (ParamType) , T is deduced in different ways:
 *  Case 1) ParamType is a pointer or ref - T* or T&
 *              - Remove reference from the argument
 *              - ParamType has same type as the argument
 *                  - If ParamType adorn iteself with const, T won't be const for the full template. 
 *  Case 2) ParamType is a universal reference - T&&
 *              - If argument is lvalue -> T and ParamType are lvalue ref
 *              - If argument is rvalue -> Case 1 rule apply
 *  Case 3) ParamType is a value type - T
 *              - Remove reference from argument 
 *              - Ignore any const or volative modifiers
 *
 * SUMMARY:
 *  - References are ignore for template type deducation, all treated as non-reference
 *      - Unless paramter is Universal Ref and is passed lvalue -> Then ref is included in type
 *  - const is removed on type when functions that take by value
 *  - Arrays and Function names get turned to pointers types
 *      - Unless ParamType takes them as reference
 */

namespace item01
{
    int x = 27;
    const int const_x = x;
    const int& ref_x = x;

    // Case 1   - Paramtype is Ref / Pointer - T& / T*
    template <typename T>
    void foo(T& param){}

    //          - Paramtype is a const Ref / Pointer - const T& / const T*
    template <typename T>
    void bar(const T& param){}

    void case1()
    {
        foo(x);         // T: int, (T&): int&
        foo(const_x);   // T: const int, (T&): const int&
        foo(ref_x);     // T: const int, (T&): const int&

        foo(x);         // T: int, T(&): const int&     Note how T is no longer const for the entire template
        foo(const_x);   // T: int, T(&): const int&     because ParaType adorns T with const T&
        foo(ref_x);     // T: int, T(&): const int&     this keeps the ref const for the function.

    }

    // Case 2   - ParamType is Universal Ref - T&&
    template <typename T>
    void foo2(T&& param){}

    void case2()
    {
        foo2(x);         // T: int&, (T&&): int&                All args are lvalues, so T and ParamType are int&
        foo2(const_x);   // T: const int&, (T&&): const int&     
        foo2(ref_x);     // T: const int&, (T&&): const int&    
        foo2(27);        // T: int, (T&&): int&&

    }

    // Case 3   - ParamType is value  -T
    template <typename T>
    void foo3(T param) {}

    void case3()
    {
        foo3(x);        // T: int, (T): int     ParamType takes by value, so the type of the template and Paramtype doesnt
        foo3(const_x);  // T: int, (T): int     need to care about const. 
        foo3(ref_x);    // T: int, (T): int     As it works with a copy anyway!
        foo3(27);       // T: int, (T): int
    }


}
