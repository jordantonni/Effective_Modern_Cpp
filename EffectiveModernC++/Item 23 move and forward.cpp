/*
 *
 *
 *
 *
 * SUMMARY:
 *  -
 */
#include <iostream>
#include <string>

namespace item23
{
    using namespace std;


    void processString(const string& s)
    {
        std::cout << "lvalue -> " << s << endl;
    }

    void processString(string&& s)
    {
        std::cout << "rvalue -> " << s << endl;
    }


    template <typename T>
    void process(T&& param)
    {
        //        processString(param);
        processString(std::forward<T>(param));
    }


    class Widget
    {
    public:
//        template <typename T>
//        void setName(T&& na)
//        {
//            name = na;
//        }

        void setName(const string& na)
        {
            name = na;
        }

        void setName(string&& na)
        {

            name = std::move(na);
        }

    private:
        string name;
    };

    void foobar(string s)
    {
        s = "foobar'd";
    }

    template<typename T>
    void setSign(T&& text)
    {
        foobar(text);
    }

    void u(string s)
    {
        s = "hehe";
        int x;
    }
    void t(const string& s)
    {
        u(s);
    }


    void test()
    {
//        string s { "text" };
        //        process(s);
        //        process(std::move(s));

        string me{"Jay"};
        t(me);
        


    }
}
