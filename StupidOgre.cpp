#include "StupidOgre.h"
#include "Core.cpp"

StupidOgre::StupidOgre(const string &name) : Creature_NPC(name, 100, 0, 2, 5, true, "Ogre", 5) {}

void StupidOgre::lvlUp_upgradeStats() {
    this->changeDamage(2);
    this->changeMaxHP(20);
}

void StupidOgre::AI() {
    if (this->getCurrentAction() == "idle") {
        if (getTarget() == NULL) {
            for (Creature *c : this->getLocation()->getMembers()) {
                if (c->getStats().type == "Hero") {
                    this->selectTarget(c);
                    break;
                }
            }
        } else {
            attack(*getTarget());
            LOG(getStats().name + " атаковал " + getTarget()->getStats().name);
        }
    }
}

