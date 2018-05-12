#include "Hero.h"

Hero::Hero(string name, LocationPoint *locationPoint) : Creature(name, 100, 100, 0, 8, false, "Hero", 3, locationPoint) {}

void Hero::lvlUp_upgradeStats() {
    this->changeDamage(2);
    this->changeMaxHP(10);
}
