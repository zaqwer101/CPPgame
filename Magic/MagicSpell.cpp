//
// Created by zaqwer on 03.05.18.
//

#include "MagicSpell.h"
#include "../Creatures/Creature.h"

MagicSpell::MagicSpell(Creature *caster, string name, string type, int cooldown, int power, int manacost,
                       int cast_time) {
    this->type = type;
    this->cooldown = cooldown;
    this->power = power;
    this->manacost = manacost;
    this->caster = caster;
    this->name = name;
    this->cast_time = cast_time;
    this->caster->setCooldown(name, 0);
}

int MagicSpell::getPower() {
    return this->power;
}

string MagicSpell::getType() {
    return this->type;
}

void MagicSpell::use() {}


int MagicSpell::getManacost() {
    return manacost;
}

Creature *MagicSpell::getCaster() {
    return caster;
}

void MagicSpell::setCaster(Creature *caster) {

    this->caster = caster;

}

int MagicSpell::getCastTime() {
    return this->cast_time;
}

