/*
 * Prefer const_interators over iterators
 * 
 * const_iterator is STL equilivant to pointer-to-const object
 * 
 * Pre c++98 had poor support for const_iterators
 * C++11 and 14 makes it much easier
 * 
 * cbegin, cend etc provide easy way to get them.
 * 
 * Non-member versions of begin, end, cbeing, cend, rbegin, rend, crbeing, crend should be prefered
 *  - Because some containers,, std::array etc, don't provide member versions
 *  - non member versions are availble for all
 *  - They just call member versions of they exist
 *  - More generic
 *  
 *
 * SUMMARY:
 *  - Use const_iterators whenever you can
 *  - Remember that a const_iterator only says you can't change the object POINTED TO
 *      - Can still insert things into the container though them!
 *  - Perfer non-member versions of begin, cend, end etc etc
 */

#include <vector>
#include <algorithm>
#include <iterator>

namespace item13
{
    void test()
    {
        std::vector<int> values;

        // Find where 1337 is in the vector, insert 69 there, moving 1337 up one
        // Can use const iterators (via cbegin and cend) as they only ensure you don't modify the values
        // Can still modify the container!
        auto it = std::find(std::cbegin(values), std::cend(values), 1337);
        values.insert(it, 69);
    }
}
