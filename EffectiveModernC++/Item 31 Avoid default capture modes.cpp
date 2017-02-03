/*
 *
 *
 *
 *
 * SUMMARY:
 *  -
 */

#include <functional>
#include <vector>
#include <iostream>

namespace item31
{
    using FilterVector = std::vector<std::function<void(void)>>;
    FilterVector filters;

    void getFilterVal()
    {
        int leet = 1337;

        filters.emplace_back([lamb_local = leet]
        {
            std::cout << lamb_local << std::endl;
        });
    }

    void test()
    {
        getFilterVal();
        
        filters[0]();
    }
    
    
}