#ifndef CREATURE_NPC_H
#define CREATURE_NPC_H
#include<iostream>
#include "../headers/Creature.h"
using namespace std;

/**
 Абстрактный класс, от которого будут наследоваться все NPC-существа в мире
 */
class Creature_NPC : public Creature {
public:
    Creature_NPC(string name, int hp, int mana, int armor, int damage, bool aggressive, string type);
    
    /**
     * Будет ли NPC нападать на всех героев (Hero), которых встречает
     * @return 
     */
    bool isAggressive(); 

    /**
     * Функция, которой ИИ "действует"
     */
    virtual void AI() = 0;

private:
    bool _aggressive;
};

#endif /* CREATURE_NPC_H */

