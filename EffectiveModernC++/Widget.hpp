#pragma once
#include <memory>
#include <string>

namespace item22
{
    class Widget
    {
    public:
        Widget();
        ~Widget();
        void foo() const;

    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;
    };
}
