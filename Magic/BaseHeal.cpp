#include "BaseHeal.h"
#include "../Creatures/Creature.h"

BaseHeal::BaseHeal(int power, int manacost) : MagicSpell("heal", "heal", 2, power, manacost, 1) {}

void BaseHeal::use() {
    getCaster()->heal(this->getPower());
}

