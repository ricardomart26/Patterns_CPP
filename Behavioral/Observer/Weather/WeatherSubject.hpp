#ifndef WEATHER_SUBJECT_HPP
#define WEATHER_SUBJECT_HPP

#include <iostream>
#include <forward_list>
#include "CurrentConditionDisplay.hpp"

class IObserver;

class WeatherSubject {

    public:

        WeatherSubject(): myObserversSize(0) {}

        void    addObserver(IObserver *observer)
        {
            myObservers.push_front(observer);
            myObserversSize++;
        }

        void    removeObserver(IObserver *observer)
        {
            myObservers.remove(observer);
            myObserversSize--;
        }


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

        void displayMenu() 
        {
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
                    CurrentConditionDisplay observer(*this);
                }
                else if (option == 2)
                {
                    StatisticsDisplay observer(*this);
                }
                else if (option == 3)
                {
                    ForecastDisplay observer(*this);
                }
                else if (option == 4)
                {
                    // this->removeObserverByInput();
                }
            }
        }

        // void removeObserverByInput()
        // {
        //     std::size_t i = 1;
        //     std::cout << "Available Displays: \n";
        //     for (auto it = myObservers.begin(); it != myObservers.end(); it++)
        //     {
        //         std::string message;
        //         if (dynamic_cast<CurrentConditionDisplay *>(*it) == nullptr)
        //             message = "Current Condition Display";
        //         else if (dynamic_cast<ForecastDisplay *>(*it) == nullptr)
        //             message = "Forecast Display";
        //         else if (dynamic_cast<StatisticsDisplay *>(*it) == nullptr)
        //             message = "Statistics Display";
        //         std::cout << i++ << ". " << message << "\n";
        //     }
        //     std::cout << i++ << "Back to Main Menu";
        //     int option;
        //     std::cin >> option;


        //     if (option == myObserversSize) {
        //         return displayMenu();
        //     } else {
        //         removeObserver(observer);
        //     }

        
            


        //     // Available Displays:
        //     // 1. Current Conditions Display
        //     // 2. Statistics Display
        //     // 3. Forecast Display
        //     // 4. Back to Main Menu
        // }

    private:

        std::forward_list<IObserver *> myObservers;
        size_t myObserversSize;

};


#endif