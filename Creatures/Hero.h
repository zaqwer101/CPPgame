#ifndef HERO_H
#define HERO_H

#include "Creature.h"


class Hero : public Creature { /// Класс героя, единственного в мире наследника данного класса
public:
    
    Hero(string name, LocationPoint *locationPoint);
    void lvlUp_upgradeStats() override;

};

#endif /* HERO_H */

