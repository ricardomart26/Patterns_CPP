
#include "Expresso.hpp"
#include "MilkDecorator.hpp"
#include "SugarDecorator.hpp"
#include <iostream>
#include <vector>


void print_menu(Coffee *expresso)
{
    std::vector<std::string> topings = {"Milk", "Sugar", "Done"};
    
    while (1)
    {
    
        for (size_t i = 0; i < topings.size(); i++)
        {
            std::cout << i + 1 << " " << topings[i] << std::endl;
        }
        int option;
        std::cin >> option;
        option--;
        if (option >= 0 && option < topings.size())
        {
            if (topings[option] == "Done")
                break;
            if (topings[option] == "Milk")
                expresso = new MilkDecorator(expresso);
            else if (topings[option] == "Sugar")
                expresso = new SugarDecorator(expresso);
            topings.erase(topings.begin() + option);
        }
        std::system("clear");
        std::cout << "Choose a number to add toppings to your coffee: \n";
    }
    std::cout << *expresso << std::endl;

}


int main(int argc, char **av)
{
    std::system("clear");

    std::cout << "Welcome to the coffee shop!\n\n";
    std::cout << "Choose a number to add toppings to your coffee: \n";

    Coffee *expresso = new Expresso();
    print_menu(expresso);
}

