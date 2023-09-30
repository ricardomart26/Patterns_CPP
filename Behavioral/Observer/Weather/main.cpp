
#include "IObserver.hpp"
#include "WeatherSubject.hpp"
#include "CurrentConditionDisplay.hpp"
#include "StatisticDisplay.hpp"
#include "ForecastDisplay.hpp"

int printMenu(const std::vector<std::string> &commands)
{

    int input = 0;
    while (true)
    {
        system("clear");

        std::cout << "Welcome to the Weather Monitoring System CLI\n\n";

        std::cout << "Available Commands:\n";
        for (size_t i = 0; i < commands.size(); i++)
            std::cout << i + 1 << ". " << commands[i] << "\n";

        std::cout << "\nPlease enter a command (1-6): ";
        int input;
        std::cin >> input;
        if (input > 0 && input < commands.size() + 1)
            break ;
    }
    return input;
}

int main(int argc, char **av)
{
    WeatherSubject subject;
    std::vector<std::string> commands {
        "Add Current Conditions Display",
        "Add Statistics Display",
        "Add Forecast Display",
        "Remove Display",
        "Simulate Weather Update",
        "Exit"
    };


    while (true)
    {
        int option = printMenu(commands);

        if (option == 1)
        {
            CurrentConditionDisplay observer(subject);
        }
        else if (option == 2)
        {
            StatisticsDisplay observer(subject);
        }
        else if (option == 3)
        {
            ForecastDisplay observer(subject);
        }
    }

    return (0);
}


/**
 *
 * Welcome to the Weather Monitoring System CLI
 *
 * Available Commands:
 * 1. Add Current Conditions Display
 * 2. Add Statistics Display
 * 3. Add Forecast Display
 * 4. Remove Display
 * 5. Simulate Weather Update
 * 6. Exit
 *
 * Please enter a command (1-6):
*/