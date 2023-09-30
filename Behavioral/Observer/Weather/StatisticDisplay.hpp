#ifndef STATISTIC_DISPLAY_HPP
#define STATISTIC_DISPLAY_HPP

#include "IObserver.hpp"
#include "WeatherSubject.hpp"


class StatisticsDisplay: public IObserver
{

    public:
        StatisticsDisplay(WeatherSubject &subject)
            : mySubject(subject) 
        {
            mySubject.addObserver(this);
        }

        void update(float temperature, float humidity, float wind) override 
        {
            myTemperature.push_back(temperature);
            myHumidity.push_back(humidity);
            myWind.push_back(wind);
            display();
        }

        ~StatisticsDisplay() { mySubject.removeObserver(this); }

        // Display statistics based on stored weather data
        void display() const 
        {
            std::cout << "Statistics Display:" << std::endl;
            std::cout << "Temperature - Avg: " << calculateAverage(myTemperature)
                    << ", Max: " << findMax(myTemperature)
                    << ", Min: " << findMin(myTemperature) << std::endl;
            std::cout << "Humidity - Avg: " << calculateAverage(myHumidity)
                    << ", Max: " << findMax(myHumidity)
                    << ", Min: " << findMin(myHumidity) << std::endl;
            std::cout << "Pressure - Avg: " << calculateAverage(myWind)
                    << ", Max: " << findMax(myWind)
                    << ", Min: " << findMin(myWind) << std::endl;
            std::cout << std::endl;
        }

    private:

        float calculateAverage(std::vector<float> data) const
        {
            if (data.empty())
                return 0.0f;
            float total = 0.0f;

            for (const float &d: data)
                total += d;

            return (total / data.size());
        }        

        float findMin(const std::vector<float> &data) const
        {
            if (data.empty())
                return 0.0f;
            
            float min = *(data.begin());

            for (const float &d: data)
                min = min > d ? d : min;

            return (min);
        }        

        float findMax(std::vector<float> data) const
        {
            if (data.empty())
                return 0.0f;

            float max = *(data.begin());

            for (const float &d: data)
                max = max < d ? d : max;

            return (max);
        }        


        std::vector<float> myTemperature;
        std::vector<float> myHumidity;
        std::vector<float> myWind;
        WeatherSubject &mySubject;
};


#endif