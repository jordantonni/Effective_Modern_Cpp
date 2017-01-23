/*
 *
 *
 *
 *
 * SUMMARY:
 *  -
 */

#include <list>

namespace item09
{
    template <typename T>
    struct MyList
    {
        typedef std::list<T> type;
    };


    class Widget
    {};

    template <class T>
    class aggre
    {
        typename MyList<T>::type wid_list;
    };

    void test()
    {
        aggre<int> myAggre;
    }
}
