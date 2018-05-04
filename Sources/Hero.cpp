#include "../Headers/Hero.h"

Hero::Hero(string name) : Creature(name, 100, 100, 0, 8, false, "Hero", 3) {}

void Hero::lvlUp_upgradeStats() {
    this->changeDamage(2);
    this->changeMaxHP(10);
}
