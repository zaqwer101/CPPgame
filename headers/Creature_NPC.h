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
    Creature_NPC(string name, int hp, int mana, int armor, int damage, bool aggressive);
    
    /**
     * Будет ли NPC нападать на всех героев (Hero), которых встречает
     * @return 
     */
    bool isAggressive(); 

private:
    bool _aggressive;
};

#endif /* CREATURE_NPC_H */

