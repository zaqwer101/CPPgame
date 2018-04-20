#ifndef CREATURE_H
#define CREATURE_H

#include<iostream>
#include "Location.h"
#include<map>

using namespace std;

struct _stats 
{
        string name;

        /**
         * Тип существа (e.g. "Ogre"). 
        */
        string type;
        int hp,maxhp;
        int mana, maxmana;
        int armor, maxarmor;
        int damage, maxdamage;
        
        int level, exp, exp_to_level;
};

class Creature {
public:
    Creature(string name, int hp, int mana, int armor, int damage, bool _is_NPC, string type);
    struct _stats getStats();
    map<string,int> timings;

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
    
    /// Debug method
    void __debug_printStats();
    
    /**
     * Является ли существо NPC
     * @return 
     */
    bool is_NPC();
    
    /**
     * Получить текущую локацию существа
     */
    Location* getLocation();

    /**
     * Изменить локацию существа
     * @param Ссылка на целевую локацию
     */
    void changeLocation(Location* location);

    /**
     * Находится ли существо в сражении с данный момент
     */
    bool isInBattle();

    /**
     * Выбрать цель для атаки
     * @param Ссылка на существо противника
     */
    void selectTarget(Creature* target);

    /**
     * Получить текущую цель существа
     * @return Ссылка на существо противника
     */
    Creature* getTarget();



private:
    bool is_in_battle;
    _stats stats;
    bool alive;
    virtual void lvlUp_upgradeStats() = 0;
    bool _is_NPC;
    Creature* target;
    Location* location; /// Ссылка на текущую локацию существа
};

#endif 
