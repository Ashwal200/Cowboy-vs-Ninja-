#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"

using namespace std;

namespace ariel
{
    
	Ninja::Ninja(const string& name , const Point& place ,int hpl, int speed) : Character(name, place , hpl)
	{
		_speed = speed;
	}

	int Ninja::getSpeed()
	{
		return _speed;
	}

	void Ninja::slash(Character* enemy)
	{
		if(enemy == nullptr || !enemy->isAlive() || this == enemy) 
		{
			throw runtime_error("Can't use nullptr element");	
		}
		if (getLocation().distance(enemy->getLocation()) <= 1.0)
		{
			enemy->hit(40);
		}
		
	}
	
	void Ninja::attack(Character* enemy)
	{
		if (getLocation().distance(enemy->getLocation()) <= 1.0)
		{
			slash(enemy);
			
		}
		else if (getLocation().distance(enemy->getLocation()) > 1.0)
		{
			move(enemy);
		}
	}

	string Ninja::print() 
	{
		string printstate = "N( " + getName() + " )\n";
        if (isAlive())
        {
            printstate += "Hit: " + to_string(getHit()) + "\nLocation :" + " " + this->getLocation().print() + "\n";
        }
        else
        {
            printstate += + "\nLocation :" + this->getLocation().print() + "\n";
        }

        cout << printstate;

        return printstate;
	
	}

	void Ninja::move(Character * enemy)
	{
		setLocation(Point::moveTowards(this->getLocation() , enemy->getLocation() , this->getSpeed()));
	}

}
