#include "Creature.h"

Creature::Creature(string name, int hp, int mana, int armor, int damage) {
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
    
    this->alive = true;
}

struct _stats Creature::getStats(){
    return this->stats;
}

void Creature::takeDamage_phys(int damage) {
    this->stats.hp = this->stats.hp - (damage - this->stats.armor);
    
    if(this->stats.hp <= 0)
    {
        this->die();
    }
}

void Creature::attack(Creature &target) {
    if(target.isAlive())
        target.takeDamage_phys(this->stats.damage);
    
    if( !target.isAlive() ) 
    {
        this->takeExp(target.stats.maxhp);
    }
}

void Creature::takeExp(int exp) {
    int delta = exp;
    
    while(delta >= 0)
    {
        this->stats.exp += delta;
    
        if (this->stats.exp >= this->stats.exp_to_level)
        {
            delta -= this->stats.exp_to_level;
            lvlUp(); // exp_to_level увеличилась, exp = 0
        }
        else
            break;
    }

}

void Creature::die() {
    this->stats.hp = 0;
    this->alive = false;
}

bool Creature::isAlive() {
    return this->alive;
}

void Creature::lvlUp() {
    this->stats.exp = 0;
    this->stats.exp_to_level *= 2;
    this->stats.level ++;
}



