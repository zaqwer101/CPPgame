#include<iostream>

using namespace std;

#ifndef CREATURE_H
#define CREATURE_H

struct _stats 
{
        string name, type;
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
    
    int attack(Creature &target);
    void takeDamage_phys(int damage);
    
    void die();
    bool isAlive();
    
    void takeExp(int exp);
    void lvlUp();
    
    void changeDamage(int value);
    
    /**
    * Изменить максимальный уровень здоровья существа.
    * @param value
    */
    void changeMaxHP(int value);
    
    /// Debug methods
    void __debug_printStats();
    
    
private:
    _stats stats;
    bool alive;
    virtual void lvlUp_upgradeStats() = 0;
};

#endif /* CREATURE_H */

