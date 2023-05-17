#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
#include "Ninja.hpp"
#include <stdio.h>
#include <string>

using namespace std;


const int hp_y = 100;
const int speed_y = 14;
namespace ariel{
    class  YoungNinja : public Ninja{
        public:
            YoungNinja(const string &name , const Point &point)
          
            : Ninja(name, point, hp_y, speed_y){}
            
    };
};



#endif
