#ifndef FORECAST_DISPLAY_HPP
#define FORECAST_DISPLAY_HPP


#include "IObserver.hpp" // Include the Observer interface or base class

class ForecastDisplay : public IObserver {

public:
    ForecastDisplay(WeatherSubject &subject) : myCurrentTemperature(0.0f),
        myLastTemperature(0.0f),
        myCurrentHumidity(0.0f),
        myLastHumidity(0.0f),
        myCurrentWind(0.0f),
        myLastWind(0.0f),
        mySubject(subject)
    {
        mySubject.addObserver(this);
    }

    // Implement the update method to receive weather updates from the subject
    void update(float temperature, float humidity, float wind) override {
        // Store the current and last Temperature values
        myLastTemperature = myCurrentTemperature;
        myCurrentTemperature = temperature;

        myLastHumidity = myCurrentHumidity;
        myCurrentHumidity = humidity;

        myLastWind = myCurrentWind;
        myCurrentWind = wind;

        display();
    }

    // Display a weather forecast based on pressure changes
    void display() const {
        std::cout << "Forecast Display:" << std::endl;

        if (myCurrentTemperature > myLastTemperature) {
            std::cout << "Expecting improving weather with higher temperature." << std::endl;
        } else if (myCurrentTemperature < myLastTemperature) {
            std::cout << "Expecting deteriorating weather with lower temperature." << std::endl;
        } else {
            std::cout << "No significant change in weather temperature." << std::endl;
        }


        if (myCurrentHumidity > myLastHumidity) {
            std::cout << "Expecting improving weather with bigger humidity." << std::endl;
        } else if (myCurrentHumidity < myLastHumidity) {
            std::cout << "Expecting deteriorating weather with lower humidity." << std::endl;
        } else {
            std::cout << "No significant change in weather humidity." << std::endl;
        }


        if (myCurrentWind > myLastWind) {
            std::cout << "Expecting weather with higher wind speed." << std::endl;
        } else if (myCurrentWind < myLastWind) {
            std::cout << "Expecting weather with lower wind speed." << std::endl;
        } else {
            std::cout << "No significant change in weather wind speed." << std::endl;
        }

        std::cout << std::endl;
    }


    ~ForecastDisplay()
    {
        mySubject.removeObserver(this);
    }

    private:

        float myCurrentTemperature;
        float myLastTemperature;

        float myCurrentHumidity;
        float myLastHumidity;

        float myCurrentWind;
        float myLastWind;

        WeatherSubject &mySubject;

};

#endif
