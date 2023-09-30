#ifndef CURRENT_CONDITION_DISPLAY_HPP
#define CURRENT_CONDITION_DISPLAY_HPP

#include "IObserver.hpp"
#include "WeatherSubject.hpp"

class CurrentConditionDisplay: public IObserver
{

    public:
        CurrentConditionDisplay(WeatherSubject &subject)
            : mySubject(subject), myTemperature(0.0f), myHumidity(0.0f), myWind(0.0f) 
        {
            mySubject.addObserver(this);
        }

        void update(float temperature, float humidity, float wind) override 
        {
            myTemperature = temperature;
            myHumidity = humidity;
            myWind = wind;
            display();
        }

        ~CurrentConditionDisplay() { mySubject.removeObserver(this); }

        void display() const
        {
            std::cout << "Current Conditions Display:" << std::endl;
            std::cout << "Temperature: " << myTemperature << "°C" << std::endl;
            std::cout << "Humidity: " << myHumidity << "%" << std::endl;
            std::cout << "Wind: " << myWind << "km" << std::endl;
            std::cout << std::endl;
        }

    private:

        float myTemperature;
        float myHumidity;
        float myWind;
        WeatherSubject &mySubject;

};

#endif