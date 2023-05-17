#include <iostream>
#include <string>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <typeinfo>
using namespace std;

namespace ariel
{
    Character::Character(const string &name , const Point &place) : _name(name) , _location(place) , _hp(110){}

    Character::Character(const string &name , const Point &place , int hpl) : _name(name) , _location(place) , _hp(hpl){}


	    Character::Character(const Character &copy) : _name(copy._name), _location(copy._location), _hp(copy._hp), _partOf(copy._partOf), _hit(copy._hit) {}

    Character::Character(Character && movec) noexcept : _name(move(movec._name)), _location(move(movec._location)), _hp(movec._hp), _partOf(movec._partOf), _hit(movec._hit) {}

    Character& Character::operator=(const Character &copyA)
    {
        if (this == &copyA)
            return *this;

        _name = copyA._name;
        _location = copyA._location;
        _hp = copyA._hp;
        _partOf = copyA._partOf;
        _hit = copyA._hit;

        return *this;
    }

    Character& Character::operator=(Character &&moveA) noexcept
    {
        if (this == &moveA)
            return *this;

        _name = move(moveA._name);
        _location = move(moveA._location);
        _hp = moveA._hp;
        _partOf = moveA._partOf;
        _hit = moveA._hit;

        return *this;
    }

    int Character::getHp()
	{
		return _hp;
	}
   const Point Character::getLocation() const
	{
		return _location;
	}
  string Character::getName()
	{
		return _name;
	}
   bool Character::isAlive() const
	{
		if (this->_hp > 0)
		{
			return true;
		}
		
		return false;
	}
	
	double Character::distance(const Character* charac) const
	{
		if(charac == nullptr)
		{
			throw runtime_error("somthing went wrong");
		}
		return _location.distance(charac->_location);
	}

	bool Character::getPartOf() {return _partOf;}
	
	void Character::setPartOf(bool flage)
	{
		_partOf = flage;
	}



	void Character::attack(Character * enemy){}

	int Character::getHit()
	{
		return _hit;
	}
    void Character::hit(int num)
	{
	if(num < 0) throw invalid_argument("Negetive number");
		_hit += num;
		_hp -= num;
	}

	void Character::setLocation(Point new_location)
	{
		_location = new_location;
	}
}
