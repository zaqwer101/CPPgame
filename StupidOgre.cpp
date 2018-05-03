#include "StupidOgre.h"

StupidOgre::StupidOgre(const string &name) : Creature_NPC(name, 100, 0, 2, 5, true, "Ogre", 2) {}

void StupidOgre::lvlUp_upgradeStats() {
    this->changeDamage(2);
    this->changeMaxHP(20);
}

void StupidOgre::AI() {
    if (this->getAction() == ACTION_IDLE) {
        if (getTarget() == nullptr) {
            for (Creature *c : this->getLocation()->getMembers()) {
                if (c->getStats().type == "Hero") {
                    this->selectTarget(c);
                    actionStart(ACTION_ATTACK, this->timings[ACTION_ATTACK]);
                    break;
                }
            }
        } else {
            actionStart(ACTION_ATTACK, this->timings[ACTION_ATTACK]);
        }
    }
}