/*
 *
 *
 * SUMMARY:
 *  -
 */

namespace intro
{
    
    void foo(int a, int& b, const int& c, int&& d, const int&& e)
    {
        // a,b,c,d,e are all l-values.
        // The arguments that foo takes are either l or r values

        // The types of a,b,c,d,e are given below
        
        a;  // lvalue
        b;  // lvalue ref
        c;  // const lvalue ref (Can take an lvalue or an rvalue argument)
        d;  // rvalue ref
        e;  // const rvalue ref (Takes in an l or r value and keeps it const)
    }

}