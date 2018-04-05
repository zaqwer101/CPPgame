#ifndef CREATURE_H
#define CREATURE_H

#include<iostream>
using namespace std;

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
    Creature(string name, int hp, int mana, int armor, int damage, bool _is_NPC);
    struct _stats getStats();
    
    int attack(Creature &target);
    void takeDamage_phys(int damage);
    
    void die();
    bool isAlive();
    
    /**
     * Получить очки опыта
     * @param exp
     */
    void takeExp(int exp);
    
    /**
     * Повысить уровень
     */
    void lvlUp();
    
    /**
     * Изменить максимальный уровень урона существа
     * @param value
     */
    void changeDamage(int value);
    
    /**
    * Изменить максимальный уровень здоровья существа.
    * @param value
    */
    void changeMaxHP(int value);
    
    /// Debug methods
    void __debug_printStats();
    
    /**
     * Является ли существо NPC
     * @return 
     */
    bool is_NPC();
    
private:
    _stats stats;
    bool alive;
    virtual void lvlUp_upgradeStats() = 0;
    bool _is_NPC;
};

#endif /* CREATURE_H */

