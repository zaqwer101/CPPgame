//
// Created by zaqwer on 03.05.18.
//

#include "Fireball.h"

Fireball::Fireball(Creature *caster, int power, int manacost) : MagicSpell(caster, "fireball", "fire", 4, power, manacost, 2) {}

void Fireball::use() {
    getCaster()->attack_magic();
}
