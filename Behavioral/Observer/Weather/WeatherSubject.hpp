#ifndef WEATHER_SUBJECT_HPP
#define WEATHER_SUBJECT_HPP

#include <iostream>
#include <forward_list>

class IObserver;

class WeatherSubject {

    public:

        WeatherSubject() {}

        void    addObserver(IObserver *observer)
        {
            myObservers.push_front(observer);
        }

        void    removeObserver(IObserver *observer)
        {
            myObservers.remove(observer);
        }

        void update() {}

    private:

        std::forward_list<IObserver *> myObservers;

};


#endif