#ifndef SUGAR_DECORATOR_HPP
#define SUGAR_DECORATOR_HPP

#include "Coffee.hpp"

class SugarDecorator : public Coffee
{
    public:

        SugarDecorator(Coffee *coffee) : myCoffee(coffee) {}
        std::string getDescription() const { return myCoffee->getDescription() + ", Sugar"; }
        float getCost() const { return myCoffee->getCost() + 0.1; }
        int getTime() const { return myCoffee->getTime() + 2; }
        
    private:

        Coffee *myCoffee;
};

#endif

