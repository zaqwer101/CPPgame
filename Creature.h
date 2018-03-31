#include<iostream>

using namespace std;

#ifndef CREATURE_H
#define CREATURE_H

class Creature {
public:
    Creature();
    struct stats getStats();
    void attack(Creature target);
    void takeDamage_phys(int damage);
    void takeExp(int exp);
    void lvlUp();

private:
    struct stats 
    {
        string name;
        int hp,maxhp;
        int armor, maxarmor;
        int damage, maxdamage;
        
        int level, exp, exp_to_level;
    };
};

#endif /* CREATURE_H */

