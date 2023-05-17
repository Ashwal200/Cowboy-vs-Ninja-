#ifndef NINJA_HPP
#define NINJA_HPP
#include "Point.hpp"
#include "Character.hpp"
#include <stdio.h>
#include <string>

using namespace std;



namespace ariel{
    class  Ninja : public Character{
        private:
            int _speed = 0;
        public:

        Ninja();

        Ninja(const string&, const Point& , int, int);
        
        void move(Character* enemy);

        void slash(Character* enemy);

        int getSpeed();

        string print() override;
        
        void attack(Character * enemy) override;
    };
}



#endif
