#ifndef EXPRESSO_HPP
#define EXPRESSO_HPP

#include "Coffee.hpp"
#include <ostream>

class Expresso: public Coffee 
{
    public:
        
        Expresso() {};

        std::string getDescription() const { return "Expresso"; };
        float getCost() const { return 0.5; };
        int getTime() const { return 30; };

};

#endif
