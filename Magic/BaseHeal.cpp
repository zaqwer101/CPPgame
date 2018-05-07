#include "BaseHeal.h"
#include "../Creatures/Creature.h"

BaseHeal::BaseHeal(Creature *caster, int power, int manacost) : MagicSpell(caster, "heal", "heal", 2, power, manacost,
                                                                           1) {}

void BaseHeal::use() {
    getCaster()->heal(this->getPower());
}

