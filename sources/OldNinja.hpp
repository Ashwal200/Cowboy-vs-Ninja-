#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include "Ninja.hpp"
#include <stdio.h>
#include <string>

using namespace std;

const int hp_o = 150;
const int speed_o = 8;

namespace ariel{
    class  OldNinja : public Ninja{
        public:
            OldNinja(const string &name , const Point &point) 
            : Ninja(name,point, hp_o , speed_o){}
    };
}



#endif
