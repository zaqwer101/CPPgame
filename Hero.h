#ifndef HERO_H
#define HERO_H

#include "Creature.h"


class Hero : public Creature {
public:
    
    Hero(string name);
    void lvlUp_upgradeStats() override;

};

#endif /* HERO_H */

