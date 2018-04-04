#include "Creature.h"

Creature::Creature(string name, int hp, int mana, int armor, int damage) 
{
    this->stats.armor = armor;
    this->stats.maxarmor = armor;
    this->stats.name = name;
    this->stats.hp = hp;
    this->stats.maxhp = hp;
    this->stats.mana = mana;
    this->stats.maxmana = mana;
    this->stats.damage = damage;
    this->stats.maxdamage = damage;
    
    this->stats.level = 1;
    this->stats.exp = 0;
    this->stats.exp_to_level = 100;
}


