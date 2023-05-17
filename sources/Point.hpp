#ifndef POINT_HPP
#define POINT_HPP
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;

    public:
        Point();

        Point(double point_x, double point_y);
        
        bool operator==(const Point& other) const ;
        
        bool operator!=(const Point& other) const ;

        double getX() const;
        
        void setX(double num);

        double getY() const;
        
        void setY(double num);

        double distance(const Point &point) const;

        string print() const;

        static Point moveTowards(Point src , Point dest , double distance);
    };
}

#endif
