#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>
#include "Team.hpp"
#include <limits.h>

using namespace std;

namespace ariel
{
    Team::Team(Character *leader)
    {

        _leader = leader;
	add(leader);
    }
	
    
    Team::Team(const Team &copy) : _leader(copy._leader), _teamMembers(copy._teamMembers) {}

    Team::Team(Team &&movec) noexcept : _leader(movec._leader), _teamMembers(movec._teamMembers) {}
    
    Team &Team::operator=(const Team &copyA)
    {
        if (this == &copyA)
            return *this;

        this->_leader = copyA._leader;
        this->_teamMembers = copyA._teamMembers;
        return *this;
    }

    Team &Team::operator=(Team &&moveA) noexcept
    {
        if (this == &moveA)
            return *this;

        this->_leader = moveA._leader;
        this->_teamMembers = moveA._teamMembers;
        return *this;
    }

    Team::~Team()
    {
        for (Character* member : _teamMembers)
        {
            delete member;
        }
    }	
	
    int Team::getSize()
    {
        return _teamMembers.size();
    }
    

vector<Character*>::iterator findPosition(vector<Character*>& teamMembers, bool isCowboy)
{
    return find_if(teamMembers.begin(), teamMembers.end(), [isCowboy](Character* member) {
        bool isMemberCowboy = (dynamic_cast<Cowboy*>(member) != nullptr);
        return (isCowboy && !isMemberCowboy);
    });
}

void Team::add(Character* new_member)
{
    if (new_member == nullptr || !new_member->isAlive() || new_member->getPartOf() || getSize() >= 10)
    {
        throw std::runtime_error("We have an issue with this operation");
    }
    else
    {
        bool isCowboy = (dynamic_cast<Cowboy*>(new_member) != nullptr);

        auto iterator = findPosition(_teamMembers, isCowboy);

        _teamMembers.insert(iterator, new_member);

        new_member->setPartOf(true);
    }
}


	
    vector <Character*> Team::getTeamMembers()
    {
    	return _teamMembers;
    }

	Character* Team::min_gap(Character* leader, Team* enemies) {
	    Character* closestEnemy = nullptr;

	    // Get leader's location
	    Point leaderLocation = leader->getLocation();

	    for (Character* member : enemies->getTeamMembers()) {
		if (member != nullptr && member->isAlive()) {
		    Point memberLocation = member->getLocation();
		    if (closestEnemy == nullptr || leaderLocation.distance(memberLocation) < leaderLocation.distance(closestEnemy->getLocation())) {
		        closestEnemy = member;
		    }
		}
	    }

	    return closestEnemy;
	}


    void Team::attack(Team * enemies)
    {
	if(enemies == nullptr || stillAlive() == 0 || enemies->stillAlive() == 0)
	{
	    throw runtime_error("somthing went wrong");
	}
        if (_leader != nullptr && !_leader->isAlive())
        {
        	findLeader();
        }
        Character * closest_enemy = nullptr ;//min_gap(_leader , enemies);
	if (enemies->stillAlive() > 0)
	{

		closest_enemy =  min_gap(_leader , enemies);
		
	}			
	
	//else return;
	for (auto attacker : _teamMembers)
	    {

		if (attacker != nullptr && attacker->isAlive() && closest_enemy != nullptr && closest_enemy->isAlive())
		{
		    attacker->attack(closest_enemy);

		}
		else if(attacker != nullptr && attacker->isAlive() && !closest_enemy->isAlive())
		{
			closest_enemy = min_gap(_leader , enemies);
            attacker->attack(closest_enemy);	
		}
		
	    }
                    
        
    }


    int Team::stillAlive()
    {
        int number = 0;
        for (Character* member : _teamMembers)
        {
            if (member->isAlive())
            {
                number++;
            }
        }
        return number;
    }

    void Team::print()
    {
        for (Character* member : _teamMembers)
        {
            if (member != nullptr)
            {
            	member->print();
            }
        }   
    }
    
    void Team::findLeader()
    {
        Character *newLeader = nullptr;
        double minDistance = numeric_limits<double>::max();

        for (auto fighter : _teamMembers)
        {
            if (fighter->isAlive() && fighter != _leader)
            {
                double distance = _leader->getLocation().distance(fighter->getLocation());
                if (distance < minDistance)
                {
                    minDistance = distance;
                    newLeader = fighter;
                }
            }
        }

        if (newLeader != nullptr)
            _leader = newLeader;
    }

}
