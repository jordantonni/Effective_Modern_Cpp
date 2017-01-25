/*
 * Use unique_ptr for exclusive ownership of a resource
 *
 * - Unique pointer should be the default smart pointer you ise
 *  - Fast and as memory efficient as raw pointer if you use lamdba with no state for deleter
 * 
 * - Move only type
 *  - Can't be copied, only moved
 *  
 * - Custom deleter
 *  - default calls delete, best usage to implement deleter as lamba with no state
 *  - deleter forms part of the unique_ptrs type, along with the type you point to
 * 
 * - Good for Pimpl idiom
 * 
 * - Normal version and array version
 *  - unique_ptr<T[]> 
 *  - Better to use std::array, std::vector, std::string though
 *  
 * - Implicitly converts to std::shared_ptr
 *  - Can store a unique_ptr in a shared_ptr
 *  - Will set unique_ptr to null
 *
 *
 * SUMMARY:
 *  - Small, fast and move-only
 *  - converts to smart_ptr easily
 *  - 
 */
#include <string>
#include <memory>
#include <iostream>

namespace item18
{
    class Character
    {
    public:
        explicit Character(const std::string& name)
            : name { name }
        {}

        virtual std::string get_response() = 0;

        virtual ~Character()
        {}

    private:
        std::string name {};
    };

    class Friendly : public Character
    {
    public:
        explicit Friendly(const std::string& name, int)
            : Character { name }
        {}

        std::string get_response() override
        {
            return "Hi there traveller";
        }
    };

    class Enemy : public Character
    {
    public:
        explicit Enemy(const std::string name, const unsigned max_health = 100)
            : Character{ name }
            , max_health{ max_health }
        {}

        std::string get_response() override
        {
            return "Watch your step, punk";
        }

    private
    :
        unsigned max_health { 0 };
    };

    enum class CharType : char
    {
        Friend,
        Enemy
    };

    template <typename... Args>
    auto
    char_factory(const CharType ct, Args&&... params)
    {
        auto del = [] (Character* cP)
                {
                    std::cout << "Deleting char" << std::endl;
                    delete cP;
                };

        std::unique_ptr<Character, decltype(del)> pChar { nullptr, del };

        if (ct == CharType::Friend)
        {
            pChar.reset(new Friendly(std::forward<Args>(params)...));
        }
        else if (ct == CharType::Enemy)
        {
            pChar.reset(new Enemy{ std::forward<Args>(params)... });
        }
        return pChar;
    }

    std::unique_ptr<Character>
    uniq_enemy(const std::string name, int health)
    {
        return std::make_unique<Enemy>(name, health);
    }


    void test()
    {
        // Factory function returns unieuq_ptr to Character object
        auto marcus { char_factory(CharType::Friend, "Marcus", 0u) };
        auto mr_evil { char_factory(CharType::Enemy, "Mr Evil", 150u) };


        // Unique_ptr implicitly converts to shared ptr
        std::shared_ptr<Character> sh = uniq_enemy("Uniq to shared", 1337);
        std::cout << sh->get_response() << std::endl;

        std::cout << marcus->get_response() << std::endl;
        std::cout << mr_evil->get_response() << std::endl;
    }
}
