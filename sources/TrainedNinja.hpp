#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Ninja.hpp"
#include <stdio.h>
#include <string>

using namespace std;


const int hp_t = 120;
const int speed_t = 12;

namespace ariel{
    class  TrainedNinja : public Ninja{

        public:
            TrainedNinja(const string &name , const Point &point)
            : Ninja(name, point, hp_t , speed_t){}
    };
}



#endif
