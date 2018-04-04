#include<iostream>

using namespace std;

#ifndef CREATURE_H
#define CREATURE_H

struct _stats 
{
        string name;
        int hp,maxhp;
        int mana, maxmana;
        int armor, maxarmor;
        int damage, maxdamage;
        
        int level, exp, exp_to_level;
};

class Creature {
public:
    Creature(string name, int hp, int mana, int armor, int damage);
    struct _stats getStats();
    
    void attack(Creature &target);
    void takeDamage_phys(int damage);
    
    void die();
    bool isAlive();
    
    void takeExp(int exp);
    void lvlUp();

    
private:
    _stats stats;
    bool alive;
};

#endif /* CREATURE_H */

