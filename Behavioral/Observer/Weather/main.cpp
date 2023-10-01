
#include "IObserver.hpp"
#include "WeatherSubject.hpp"
#include "CurrentConditionDisplay.hpp"
#include "StatisticDisplay.hpp"
#include "ForecastDisplay.hpp"


int main(int argc, char **av)
{
    WeatherSubject subject;

    subject.displayMenu();

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