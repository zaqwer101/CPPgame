#ifndef CREATURE_NPC_H
#define CREATURE_NPC_H
#include<iostream>
#include "Creature.h"
using namespace std;

class Creature_NPC : public Creature { /// Абстрактный класс, от которого будут наследоваться все NPC-существа в мире
public:
    Creature_NPC(string name, int hp, int mana, int armor, int damage, bool aggressive, string type, int time_attack, LocationPoint *locationPoint);
    
    /**
     * Будет ли NPC нападать на всех героев (Hero), которых встречает
     */
    bool isAggressive(); 

    /**
     * Функция, которой ИИ "действует" каждую секунду
     */
    virtual void AI() = 0;

private:
    bool _aggressive;
};

#endif /* CREATURE_NPC_H */

