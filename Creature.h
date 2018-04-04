#include<iostream>

using namespace std;

#ifndef CREATURE_H
#define CREATURE_H

class Creature {
public:
    Creature(string name, int hp, int mana, int armor, int damage);
    struct _stats getStats();
    
    void attack(Creature target);
    void takeDamage_phys(int damage);
    
    void takeExp(int exp);
    void lvlUp();

private:
    struct _stats 
    {
        string name;
        int hp,maxhp;
        int mana, maxmana;
        int armor, maxarmor;
        int damage, maxdamage;
        
        int level, exp, exp_to_level;
    };
    _stats stats;
};

#endif /* CREATURE_H */

