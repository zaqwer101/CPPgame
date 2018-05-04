#ifndef CPPGAME_FIREBALL_H
#define CPPGAME_FIREBALL_H


#include "MagicSpell.h"
#include "../Creatures/Creature.h"

class Fireball : public MagicSpell {
public:
    Fireball(int power, int manacost);

    Fireball(const string &name, const string &type, int cooldown, int power, int manacost, int cast_time);

    void use() override;
};


#endif //CPPGAME_FIREBALL_H
