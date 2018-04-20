#include "Creature.h"

Creature::Creature(string name, int hp, int mana, int armor, int damage, bool is_NPC, string type, int time_attack) {
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
    
    this->_is_NPC = is_NPC;
    this->stats.type = type;

    is_in_battle = false;

    this->currentAction = "idle";
    this->currentActionRemainingTime = 0;

    this->timings["attack"] = time_attack;
    this->target = NULL;
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

int Creature::attack(Creature &_target) {
    this->currentAction = "attack";
    this->currentActionRemainingTime = this->timings["attack"];

    this->is_in_battle = true;

    int tmp = _target.stats.hp;
    if (_target.isAlive())
        _target.takeDamage_phys(this->stats.damage);

    if (!_target.isAlive())
    {
        this->takeExp(_target.stats.maxhp);
        this->is_in_battle = false; // Противник погиб, мы больше не сражаемся
    }
    return tmp - _target.stats.hp;
}

void Creature::takeExp(int exp) {
    int delta = exp;
    
    while(delta >= 0)
    {
        this->stats.exp += delta;
    
        if (this->stats.exp >= this->stats.exp_to_level)
        {
            delta -= this->stats.exp_to_level;
            lvlUp(); 
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
    this->lvlUp_upgradeStats(); 
}

void Creature::changeDamage(int value)
{
    this->stats.maxdamage += value;
    this->stats.damage += value;
}

void Creature::changeMaxHP(int value)
{
    this->stats.maxhp += value;
    this->takeDamage_phys(value * -1); // 
}

void Creature::__debug_printStats() {
    cout <<
        "----------------" << endl << 
        "Name: " << this->stats.name << endl <<
        "HP: " << this->stats.hp << "/" << this->stats.maxhp << endl <<
        "Damage: " << this->stats.damage << endl <<
        "Level: " << this->stats.level << endl <<
        "EXP: " << this->stats.exp << "/" << this->stats.exp_to_level << endl << 
        "----------------" << endl;
}

bool Creature::is_NPC()
{
    return _is_NPC;
}

void Creature::changeLocation(Location* location)
{
    this->location = location;
    this->location->addMember(this);
}

Location* Creature::getLocation()
{
    return this->location;
}

bool Creature::isInBattle() {
    return this->is_in_battle;
}

void Creature::selectTarget(Creature *target) {
    this->target = target;
}

Creature *Creature::getTarget() {
    return this->target;
}

string Creature::getCurrentAction() {
    return this->currentAction;
}

int Creature::getActionRemainingTime() {
    return this->currentActionRemainingTime;
}

void Creature::currentActionStep() {
    currentActionRemainingTime--;
    if (currentActionRemainingTime <= 0) {
        currentAction = "idle";
        currentActionRemainingTime = 0;
    }
}
