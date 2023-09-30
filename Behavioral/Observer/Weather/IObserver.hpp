#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP


#include <iostream>
#include "WeatherSubject.hpp"
#include <vector>

class IObserver {

    public:

        virtual ~IObserver() {}
        virtual void update(float temperature, float humidity, float wind) = 0;

};

#endif