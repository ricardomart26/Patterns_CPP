#ifndef COFFEE_HPP
#define COFFEE_HPP


#include <string>
#include <ostream>

class Coffee 
{

    public:
        virtual std::string getDescription() const = 0;
        virtual float getCost() const = 0;
        virtual int getTime() const = 0;

        friend std::ostream& operator<<(std::ostream& os, const Coffee &coffee) 
        {
            os << coffee.getDescription() << " " << coffee.getCost() << "€ " << coffee.getTime() << "s";
            return os;
        }

};

#endif
