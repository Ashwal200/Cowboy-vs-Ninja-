#ifndef TEAM_HPP
#define TEAM_HPP
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#include "Character.hpp"
#include "Point.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
using namespace ariel;

namespace ariel{

    class  Team{
        private:
            vector<Character*> _teamMembers;
            Character * _leader = nullptr;
            Character* min_gap(Character*, Team*);
            void findLeader();

        public:
            Team(Character *);
                        
            Team(const Team &);

            Team(Team &&) noexcept;

            Team &operator=(const Team &);

            Team &operator=(Team &&) noexcept;
		
	    virtual ~Team();
            
            virtual void add(Character *);

            void attack(Team *);

            int getSize();

            vector <Character*> getTeamMembers();

            int stillAlive(); 

            void print();
            
                    


    };
}



#endif
