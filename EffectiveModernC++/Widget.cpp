#include "Widget.hpp"
#include <string>
#include <iostream>

namespace item22
{
    struct Widget::Impl
    {
        std::string widget_name;

        void foo()
        {
            std::cout << "This Widget is called " << widget_name << std::endl;
        }
    };

    Widget::Widget()
        : pImpl { std::make_unique<Impl>() }
    { }

    /*
     * Must define Widgets dtor here as otherwise the default implementation will be invoked
     * Which will in turn invoke unique_ptrs delete on Impl, this asserts that Impl is complete type
     * 
     * Default ctor will be inline and not see Impls definition.
     * 
     * Defining it here ensures that it has seen Impls definition!
     */
    Widget::~Widget() = default;

    void Widget::foo() const
    {
        pImpl->foo();
    }
}
