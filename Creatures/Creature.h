/*
 * TODO: Реализовать дальность атаки
 * Если существо атакует, то сражение начинается с максмальной дальности его оружия.
 * TODO: Добавить существу дополнительный параметр - скорость - количество ОД, необходимых существу на сокращение расстояния между собой и противником.
 *
 */

#ifndef CREATURE_H
#define CREATURE_H

#include<iostream>
#include "../Core/Location.h"
#include<map>
#include "../Magic/MagicSpell.h"

using namespace std;

#define ACTION_IDLE 0
#define ACTION_ATTACK 1
#define ACTION_CAST_SPELL 2
#define ACTION_DISANCE_REDUCION 3
struct stats {
    string name;
    /**
     * Тип существа (e.g. "Ogre").
    */
    string type;
    int hp, maxhp;
    int mana, maxmana;
    int armor, maxarmor;
    int damage, maxdamage;
    int speed, maxspeed;
    int attack_range;

    int level, exp, exp_to_level;
};
struct cooldown {
    string name;
    int value;
};

class Creature { /// Базовый класс существа
public:

    Creature(string name, int hp, int mana, int armor, int damage, bool _is_NPC, string type, int time_attack);

    struct stats getStats();

    /// Ассоциативный массив, в котором хранится время, необходимое на выполнение определенных действий
    map<int, int> timings;

    /// Кулдауны предметов и заклинаний
    vector<cooldown> cooldowns;

    int getCooldown(string name);

    void setCooldown(string name, int value);

    /// Список всех заклинаний, доступных существу
    vector<MagicSpell *> spellBook;

    void attack_phys();

    void attack_magic();

    void takeDamage_phys(int damage, Creature *attacker);

    void takeDamage_magic(Creature *attacker, MagicSpell *spell);

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
    Location *getLocation();

    /**
     * Изменить локацию существа
     * @param location Указатель на целевую локацию
     */
    void changeLocation(Location *location);

    /**
     * Находится ли существо в сражении с данный момент
     */
    bool isInBattle();

    /**
     * Выбрать цель для атаки
     * @param target Указатель на существо противника
     */
    void selectTarget(Creature *target);

    /**
     * Получить текущую цель существа
     * @return Указатель на существо противника    this->_is_NPC = is_NPC;

     */
    Creature *getTarget();

    /**
     * Узнать, чем в данный момент занимается существо
     * @return Строка-ключ массива timings
     */
    int getAction();

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
    void actionStart(int action, int action_duration);

    /**
     * Записать сообщение в лог существа
     */
    void LOG(string message);

    /**
     * Возвращает некоторое количество последних записей лога
     * @param count Количество записей с конца
     */
    vector<string> getLastLog(int count);

    vector<string> getLog();

    /**
     * Добавить заклинание в список доступных
     * @param spell
     */
    void addSpell(MagicSpell *spell);

    /**
     * Получить список заклинаний существа
     */
    vector<MagicSpell *> getSpells();

    /**
     * Получить заклинание по его имени
     */
    MagicSpell *getSpell(string name);

    /**
     * Использовать магию
     */
    void castSpell(MagicSpell *spell);

    /**
     * Получить сопротивление воздействию
     * @param type Тип воздействия
     * @return Значение сопротивления (коэффицент уменьшения урона)
     */
    int getResist(string type);

    MagicSpell *getCurrentSpell();

    void updateCooldowns();

    void heal(int value);

    bool isIdle();

    bool hasEnoughMana(MagicSpell *cast);

    void attack();

    /// Получить дальность атаки существа
    int getAttackRange();

    /// Получить расстояние до существа
    int getDistanceTo(Creature *target);

    /// Сократить расстояния до цели
    void reduceDistance();

private:
    /**
     * Сопротивления к различным типам воздействия
     */
    map<string, int> resists;
    int currentAction;
    int currentActionRemainingTime;
    bool is_in_battle;
    stats _stats;
    bool alive;

    virtual void lvlUp_upgradeStats();

    bool _is_NPC;
    Creature *target;
    Location *location;
    vector<string> log;
    int step;
    string currentSpell;
    int distance_to_target;
};

#endif 
