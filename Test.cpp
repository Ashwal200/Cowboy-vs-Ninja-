#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include <random>
#include <chrono>

using namespace ariel;



// Check each class first:

// ------ POINT ------
TEST_CASE("Constructor method") {
    Point p1(1, 5);
    
    CHECK_EQ(p1.getX(), 1);
    CHECK_EQ(p1.getY(), 5);

    Point p2(1.2345, 5.678910);
    CHECK_EQ(p2.getX(), 1.2345);
    CHECK_EQ(p2.getY(), 5.678910);

    Point p3(-10, -12);
    CHECK_EQ(p3.getX(), -10);
    CHECK_EQ(p3.getY(), -12);

}


TEST_CASE("Distance method") {
    Point p1(6, 9);
    Point p2(2, 12);
    Point p3(3, 13);


    CHECK_EQ(p1.distance(p2), 5);
    CHECK_EQ(p1.distance(p2), p1.distance(p3));
}


// ------ Cowboy ------
TEST_CASE("Constructor method") {
    Point p(3, 10);
    Cowboy c("Check" , p);
    
    CHECK_EQ(c.getName(), "Check");
    CHECK_EQ(c.getLocation(), p);

    
    CHECK_EQ(c.getHit(), 0);
    CHECK_EQ(c.getHp(), 110);
    CHECK_EQ(c.getPartOf(), false);
    CHECK_EQ(c.isAlive() , true);

}


TEST_CASE("Distance method") {
    Point p1(6, 9);
    Point p2(2, 12);
    Point p3(3, 13);
    
    Cowboy c("Check" , p1);
    Cowboy c2("Check2" , p2);

    CHECK_EQ(c.getLocation().distance(c2.getLocation()), 5);
    
}

TEST_CASE("Shoot method") {
    Point p1(6, 9);
    Point p2(2, 12);
    
    Cowboy c("Check" , p1);
    Cowboy c2("Check2" , p2);

    CHECK_EQ(c.hasboolets() , true);
    CHECK_NOTHROW(c.shoot(&c2));
    CHECK_THROWS_AS(c.shoot(nullptr) , std::runtime_error);
    
}

TEST_CASE("Hit & Hp method") {
    Point p1(6, 9);
    Point p2(2, 12);
    Point p3(3, 13);
    
    Cowboy c("Check" , p1);
    Cowboy c2("Check2" , p2);
    CHECK_NE(c.getLocation() , c2.getLocation());
    
    CHECK_EQ(c2.getHp() , c.getHp());
    c.shoot(&c2);
    CHECK_NE(c2.getHp() , c.getHp());
    CHECK_EQ(c2.getHp() , 100);
    for (size_t i = 0; i < 5; i++)
    {
        c.shoot(&c2);
    }
    CHECK_EQ(c2.getHp() , 0);
    CHECK_EQ(c2.getHit() , 110);
    CHECK_THROWS(c2.shoot(&c));

    CHECK_THROWS(c2.hit(-1));
    
}


// ------ Ninja ------

TEST_CASE("Constructor YoungNinja ") {
    YoungNinja n("Check", Point(1, 1));
    CHECK_EQ(n.getName(), "Check");
    CHECK_EQ(n.getLocation().distance(Point(1, 1)), 0);
    CHECK_NE(n.getLocation().distance(Point(6, 6)), 0);
    CHECK_EQ(n.getSpeed() , 14);
    CHECK(n.isAlive());
}

TEST_CASE("Constructor TrainedNinja ") {
    TrainedNinja n("Check", Point(1, 1));
    CHECK_EQ(n.getName(), "Check");
    CHECK_EQ(n.getLocation().distance(Point(1, 1)), 0);
    CHECK_NE(n.getLocation().distance(Point(6, 6)), 0);
    CHECK_EQ(n.getSpeed() , 12);
    CHECK(n.isAlive());
}

TEST_CASE("Constructor OldNinja ") {
    OldNinja n("Check", Point(1, 1));
    CHECK_EQ(n.getName(), "Check");
    CHECK_EQ(n.getLocation().distance(Point(1, 1)), 0);
    CHECK_NE(n.getLocation().distance(Point(6, 6)), 0);
    CHECK_EQ(n.getSpeed() , 8);
    CHECK(n.isAlive());
}

TEST_CASE("Move method") {
    OldNinja no("Check", Point(0, 0));
    YoungNinja ny("Check", Point(0, 0));
    TrainedNinja nt("Check", Point(0, 0));
    OldNinja far("Check2", Point(0, 8));
    YoungNinja faraway("Check2", Point(0, 22));
    no.move(&far);
    ny.move(&far);
    nt.move(&far);
    CHECK_EQ(no.getLocation(), far.getLocation());
    CHECK_EQ(ny.getLocation(), far.getLocation());
    CHECK_EQ(nt.getLocation(), far.getLocation());
    nt.move(&faraway);
    ny.move(&faraway);
    no.move(&faraway);
    CHECK_NE(no.getLocation(), faraway.getLocation());
    CHECK_NE(nt.getLocation(), faraway.getLocation());
    CHECK_EQ(ny.getLocation(), faraway.getLocation());

}

TEST_CASE("Slash method") {
    OldNinja no("Check", Point(0, 0));
    YoungNinja ny("Check", Point(0, 0));
    CHECK_EQ(ny.getHp(), 150);
    no.slash(&ny);
    CHECK_NE(ny.getHp(), 150);
    CHECK_EQ(ny.getHp(), 110);
    TrainedNinja nt("Check", Point(0, 0));
    for (size_t i = 0; i < 5; i++)
    {
        no.slash(&nt);
    }
    CHECK_EQ(nt.getHp(), 0);
    CHECK(!nt.isAlive());

    TrainedNinja ntdie("Check1", Point(0, 9));
    for (size_t i = 0; i < 5; i++)
    {
        no.slash(&ntdie);
    }
    CHECK_EQ(ntdie.getHp(), 0);
    CHECK(!ntdie.isAlive());

}

// ------ Team ------

TEST_CASE("Team Constructor") {
    Cowboy *c1 = new Cowboy("c1" , Point(1,1));
    Cowboy *c2 = new Cowboy("c2" , Point(1,1));
    Ninja *n1 = new OldNinja("n1" , Point(1,1));
    Ninja *n2 = new OldNinja("n2" , Point(1,1));

    Team team1(c1);
    team1.add(c2);
    CHECK_EQ(team1.getSize() , 2);
    CHECK_EQ(team1.stillAlive(), 2);

    Team team2(n1);
    team2.add(n2);
    CHECK_EQ(team2.getSize() , 2);
    CHECK_EQ(team2.stillAlive(), 2);

}


TEST_CASE("Add method") {
    Cowboy *c1 = new Cowboy("c1" , Point(1,1));
    Cowboy *c2 = new Cowboy("c2" , Point(1,1));

    Team team1(c1);
    team1.add(c2);
    CHECK_THROWS_AS(Team team2(c1) , std::runtime_error);
    CHECK_THROWS_AS(Team team2{nullptr},std::runtime_error);
    
    Cowboy *c3 = new Cowboy("c2" , Point(1,1));
    Cowboy *c4 = new Cowboy("c21" , Point(1,1));
    Cowboy *c5 = new Cowboy("c22" , Point(1,1));
    Cowboy *c6 = new Cowboy("c23" , Point(1,1));
    Cowboy *c7 = new Cowboy("c24" , Point(1,1));
    Cowboy *c8 = new Cowboy("c25" , Point(1,1));
    Cowboy *c9 = new Cowboy("c26" , Point(1,1));
    Cowboy *c10 = new Cowboy("c72" , Point(1,1));
    Cowboy *c31 = new Cowboy("c82" , Point(1,1));
    Cowboy *c32 = new Cowboy("c82" , Point(1,1));
    Team teamfull(c3);
    teamfull.add(c4);
    teamfull.add(c5);
    teamfull.add(c6);
    teamfull.add(c7);
    teamfull.add(c8);
    teamfull.add(c9);
    teamfull.add(c10);
    teamfull.add(c31);
    teamfull.add(c32);

    Cowboy *toomany = new Cowboy("cec82" , Point(1,1));
    CHECK_THROWS_AS(Team teamfull(toomany) , std::runtime_error);
}

TEST_CASE("Attack method") {
    Cowboy *c1 = new Cowboy("c1" , Point(0,1));
    Cowboy *c2 = new Cowboy("c2" , Point(0,12));
    Ninja *n1 = new OldNinja("n1" , Point(0,1));
    Ninja *n2 = new OldNinja("n2" , Point(0,15));

    Team team1(c1);
    team1.add(n1);
    Team team2(c2);
    team2.add(n2);

    team1.attack(&team2);
    CHECK_EQ(c2->getHp() , 100);
    CHECK_EQ(n2->getHp() , 150);
    team1.attack(&team2);
    CHECK_EQ(c2->getHp() , 90);
    CHECK_EQ(n2->getHp() , 150);
    team1.attack(&team2);
    CHECK_EQ(c2->getHp() , 40);
    team1.attack(&team2);
    CHECK_FALSE(c2->isAlive());
    CHECK_EQ(n2->getHp() , 150);
    team1.attack(&team2);
    team1.attack(&team2);
    team1.attack(&team2);
    team1.attack(&team2);
    team1.attack(&team2);
    CHECK_EQ(n2->getHp() , 0);
    CHECK_FALSE(n2->isAlive());
    CHECK_THROWS_AS(team1.attack(&team2) , std::runtime_error);
    
}



TEST_CASE("Differences between Team and Team2") {
    Cowboy *c1 = new Cowboy("c1" , Point(0,1));
    Cowboy *c2 = new Cowboy("c2" , Point(0,12));
    Ninja *n1 = new OldNinja("n1" , Point(0,1));
    Ninja *n2 = new OldNinja("n2" , Point(0,15));

    Team team(c1);
    team.add(n1);
    team.add(n2);
    team.add(c2);
    int i = 0;
    for(auto member : team.getTeamMembers())
    {
        if (i < 2)
        {
            CHECK_EQ(member->getHp() , 110);
        }
        else
        {
            CHECK_EQ(member->getHp() , 150);
        }
        i++;
    }

    Cowboy *c12 = new Cowboy("c1" , Point(0,1));
    Cowboy *c22 = new Cowboy("c2" , Point(0,12));
    Ninja *n12 = new OldNinja("n1" , Point(0,1));
    Ninja *n22 = new OldNinja("n2" , Point(0,15));

    Team2 team2(c12);
    team2.add(n12);
    team2.add(n22);
    team2.add(c22);
    
    i = 0;
    for(auto member : team2.getTeamMembers())
    {
        if (i == 0 || i == 3)
        {
            CHECK_EQ(member->getHp() , 110);
        }
        else
        {
            CHECK_EQ(member->getHp() , 150);
        }
        i++;
    }    
}
