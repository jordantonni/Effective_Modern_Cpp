/*
 *  Understand auto type deduction
 *  
 *  auto type deduction follows the same rules as T does in template type deduction
 *      - auto act like T
 *      - const auto and const auto& act like ParamType
 *  
 *  1 difference:
 *      - auto x = { 27 }  // Braced initializer syntax makes x be of Type: std::initializer_list<int>
 *      - auto x { 27 }    // But this is of type int !
 *
 * SUMMARY:
 *  - Auto type deduction is same as Template Type deduction
 *      - Apart from assigment via braced initializer syntax
 *  - Using auto as return type or lambda parameter makes it use Temaplte type deduction
 *      - Meaning it wont accept a std::initializer_list
 */

namespace item02
{
    void test()
    {
        auto x = 27;        // int
        const auto cx = x;  // const int
        const auto& rx = x; // lvalue const ref

        
    }
}