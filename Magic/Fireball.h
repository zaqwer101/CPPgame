#ifndef CPPGAME_FIREBALL_H
#define CPPGAME_FIREBALL_H


#include "MagicSpell.h"
#include "../Creature.h"

class Fireball : public MagicSpell {
public:
    Fireball(int power, int manacost);

    void use() override;
};


#endif //CPPGAME_FIREBALL_H
