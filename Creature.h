#ifndef CREATURE_H
#define CREATURE_H

#include<iostream>
#include "Location.h"
#include<map>
#include <functional>

using namespace std;

#define ACTION_IDLE 0
#define ACTION_ATTACK 1


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


class Creature { /// Базовый класс существа
public:
    Creature(string name, int hp, int mana, int armor, int damage, bool _is_NPC, string type, int time_attack);
    struct _stats getStats();

    /// Ассоциативный массив, в котором хранится время, необходимое на выполнение определенных действий
    map<int, int> timings;

    void attack();
    void takeDamage_phys(int damage, Creature* attacker);
    
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
     * @param location Указатель на целевую локацию
     */
    void changeLocation(Location* location);

    /**
     * Находится ли существо в сражении с данный момент
     */
    bool isInBattle();

    /**
     * Выбрать цель для атаки
     * @param target Указатель на существо противника
     */
    void selectTarget(Creature* target);

    /**
     * Получить текущую цель существа
     * @return Указатель на существо противника
     */
    Creature* getTarget();

    /**
     * Узнать, чем в данный момент занимается существо
     * @return Строка-ключ массива timings
     */
    int actionGet();

    /**
     * Сколько шагов осталось до окончания текущего действия
     */
    int actionGetTime();

    /**
     * Выполнить шаг времени для текущего задания
     */
    void actionStep();

    /**
     * Начать выполнение действия
     * @param action
     */
    void actionStart(int action);

    /**
     * Записать сообщение в лог существа
     */
    void LOG(string message);

    /**
     * Возвращает некоторое количество последних записей лога
     * @param count Количество записей с конца
     */
    vector<string> getLastLog(int count);

    

private:

    int currentAction;
    int currentActionRemainingTime;
    bool is_in_battle;
    _stats stats;
    bool alive;
    virtual void lvlUp_upgradeStats();
    bool _is_NPC;
    Creature *target;
    /// Указатель на текущую локацию существа
    Location *location;
    vector<string> log;
    int step;
};

#endif 
