#include "../headers/Creature_NPC.h"

Creature_NPC::Creature_NPC(string name, int hp, int mana, int armor, int damage, bool isAggressive) : Creature(name, hp, mana, armor, damage, true) {
    
    this->_aggressive = isAggressive;
}




