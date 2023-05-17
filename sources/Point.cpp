#include <stdio.h>
#include <cmath>
#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    
    Point::Point(double _x, double _y) : _x(_x), _y(_y) {}
    
    Point::Point() : _x(0), _y(0) {}
    
    bool Point::operator==(const Point& other) const 
    {
	if(_x == other.getX() && _y == other.getY())
	{
		return true;
	}
	return false;
    }
    
    bool Point::operator!=(const Point& other) const 
    {
    	return !(*this == other);
    }
    double Point::getX() const
    {
        return _x;
    }
    
    void Point::setX(double number) 
    {
    	_x = number;
    }
    
    void Point::setY(double number)
    {
    	_y = number;
    }
    
    double Point::getY() const
    {
        return _y;
    }

    double Point::distance(const Point &point) const
    {
    	double dis = sqrt(pow(point._x - _x, 2) + pow(point._y - _y, 2));
        return dis;
    }

    string Point::print() const
    {
        string point = "(" + to_string(_x) + "," + to_string(_y) + ")";
        cout << "(" << _x << "," << _y << ")" << endl;
        return point;
    }

    Point Point::moveTowards(Point src, Point dest, double distance)
    {
        if (distance < 0)
            throw invalid_argument("Not valid distance");
        if (distance == 0)
            return src;
        else if (distance >= src.distance(dest))
            return dest;
        else
        {
            double dist = distance / src.distance(dest);
            return Point((1 - dist) * src.getX() + (dist)*dest.getX(), (1 - dist) * src.getY() + (dist)*dest.getY());
        }
    }


}
