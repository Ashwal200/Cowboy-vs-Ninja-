#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;
#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
using namespace ariel;

namespace ariel
{
	Cowboy::Cowboy(const string& name , const Point& place) :Character(name , place , 110)
	{}
	

	bool Cowboy::hasboolets()
	{
		if (_bullets > 0)
		{
			return true;
		}
		
		return false;
	}

	void Cowboy::loosBullet()
	{
		_bullets--;
	}
	
	void Cowboy::attack(Character * enemy)
	{

		if (_bullets != 0)
		{
			shoot(enemy);
			
		}
		else if (_bullets == 0)
		{
			reload();
		}
	}
	
	void Cowboy::shoot(Character* enemy)
	{
		if(enemy == nullptr || !enemy->isAlive() || this == enemy) 
		{
			throw runtime_error("Can't use nullptr element");	
		}
		if (_bullets != 0)
		{
			loosBullet();
			enemy->hit(10);
			
		}

	}

	void Cowboy::reload()
	{
		if(isAlive()) {_bullets = 6;}
		else throw runtime_error("The cowboy is dead");
	}

	string Cowboy::print() 
	{
		string printstate = "C( " + getName() + " )\n";
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
}
