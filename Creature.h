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
    Creature(string name, int hp, int mana, int armor, int damage, bool _is_NPC, string type, int time_attack);
    struct _stats getStats();
    map<string,int> timings;

    int attack(Creature &_target);
    void takeDamage_phys(int damage);
    
    void die();
    bool isAlive();
    
    /**
     * Получить очки опыта
     */
    void takeExp(int exp);
    
    /**
     * Повысить уровень
     */
    void lvlUp();
    
    /**
     * Изменить максимальный уровень урона существа
     */
    void changeDamage(int value);
    
    /**
    * Изменить максимальный уровень здоровья существа.
    */
    void changeMaxHP(int value);
    
    /// Debug method
    void __debug_printStats();
    
    /**
     * Является ли существо NPC
     */
    bool is_NPC();
    
    /**
     * Получить текущую локацию существа
     */
    Location* getLocation();

    /**
     * Изменить локацию существа
     * @param Указатель на целевую локацию
     */
    void changeLocation(Location* location);

    /**
     * Находится ли существо в сражении с данный момент
     */
    bool isInBattle();

    /**
     * Выбрать цель для атаки
     * @param Указатель на существо противника
     */
    void selectTarget(Creature* target);

    /**
     * Получить текущую цель существа
     * @return Указатель на существо противника
     */
    Creature* getTarget();

    /**
     * Узнать, чем в данный момент занимается существо
     */
    string getCurrentAction();

    /**
     * Сколько шагов осталось до окончания текущего действия
     * @return Количество шагов
     */
    int getActionRemainingTime();

    /**
     * Выполнить шаг времени для текущего задания
     */
    void currentActionStep();

private:
    string currentAction;
    int currentActionRemainingTime;

    bool is_in_battle;
    _stats stats;
    bool alive;
    virtual void lvlUp_upgradeStats() = 0;
    bool _is_NPC;
    Creature *target;
    Location *location; /// Указатель на текущую локацию существа
};

#endif 
