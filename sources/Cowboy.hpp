#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <stdio.h>
#include <string>
#include "Character.hpp"
#include "Point.hpp"

using namespace std;
namespace ariel{
    class  Cowboy : public Character{
        private:
        // To improve code readability and maintainability 6 is magic number.
            const int MAX_BULLETS = 6;
            int _bullets = MAX_BULLETS;	
        public:

        Cowboy(const string& name , const Point& point);
        
        

	void loosBullet();

        void shoot(Character* enemy);

        bool hasboolets();
	
        void reload();
        
        void attack(Character * enemy) override;

        string print() override;
    };
};



#endif
