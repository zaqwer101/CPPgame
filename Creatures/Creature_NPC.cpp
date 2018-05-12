#include "Creature_NPC.h"

Creature_NPC::Creature_NPC(string name, int hp, int mana, int armor, int damage, bool isAggressive, string type,
                           int time_attack, LocationPoint *locationPoint) :
        Creature(name, hp, mana, armor, damage, true, type, time_attack, locationPoint) {
    this->_aggressive = isAggressive;
}


bool Creature_NPC::isAggressive()
{
    return this->_aggressive; 
}



