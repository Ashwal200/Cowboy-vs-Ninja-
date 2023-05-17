#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <stdio.h>
#include <string>

using namespace std;



namespace ariel{
    class  Character{
        private:
            Point _location;
            string _name;
            int _hp = 0;
            int _hit = 0;
            double _distance;
            bool _partOf = false;
            
        
        public:
            Character(const string & , const Point &);
            
            Character(const string & , const Point & , int);
	    
	    Character(const Character&);

            Character(Character&&) noexcept;

            Character& operator=(const Character &);
            
            Character& operator=(Character &&) noexcept;

            virtual ~Character() {}
            
            string getName();
	    int getHit();
            void hit(int);
	    const Point getLocation() const;
            void setLocation(Point);
            bool isAlive() const;
            virtual string print() = 0;
            bool getPartOf();
            void setPartOf(bool);
            double distance(const Character*) const;

            virtual void attack(Character *) = 0;
            int getHp();
            

    };
};



#endif
