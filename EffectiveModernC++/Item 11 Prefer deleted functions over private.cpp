/*
 *  Deleted functions over private undefined
 *
 * Old style was to declare an unwanted function private and not provde implementation
 *  - Linker errors still possible as members and friends can see them, linker will fail with no implementation
 *  
 * C++'s heritage from C means any type than can be viewed as vaguely numerical, will be implicitly convereted to int
 *  - Bad
 *  - Means passing a char, bool, double to a function taking a int will work
 *  - delete allows you to explicitly delete versions that take such argument types
 *  
 * Disallowing template instantiations from special pointer types
 *  - void*: Can't be dereferenced, incremented etc
 *  - char*: usually refers to a string
 *  
 *  - A function taking a pointer to these should possibly be disallowed
 *  - template<>
 *    void func<void>(void*) = delete;
 *  
 *   
 * delete
 *  - Compile time fail if invoked (better)
 *  - public, the fact the function is deleted forms part of your interface
 *  - Can stop function being called with implicitly convereted integral arguments
 *  - Can stop function template instantaions with specific types
 *  
 *
 * SUMMARY:
 *  - Use delete over private undefined
 *  - Can delete non-member functions and template instantations
 */

namespace item12
{
    bool isLucky(int a);
    bool isLucky(char) = delete;    // Stops isLucky being called with a char that would normally be implicitly convereted to an int
}
