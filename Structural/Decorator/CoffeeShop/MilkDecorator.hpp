#ifndef MILK_DECORATOR_HPP
#define MILK_DECORATOR_HPP

#include "Coffee.hpp"

class MilkDecorator : public Coffee
{
    public:

        MilkDecorator(Coffee *coffee) : myCoffee(coffee) {}
        std::string getDescription() const { return myCoffee->getDescription() + ", Milk"; }
        float getCost() const { return myCoffee->getCost() + 0.4; }
        int getTime() const { return myCoffee->getTime() + 10; }
        
    private:

        Coffee *myCoffee;
};

#endif

