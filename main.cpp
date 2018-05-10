#include<iostream>
#include "Creatures/Hero.h"
#include "Creatures/Creature.h"
#include "Core/Location.h"
#include "Creatures/StupidOgre.h"
#include "Magic/Fireball.h"
#include "Magic/BaseHeal.h"
#include <string>

using namespace std;

static void worldActionStep(vector<Location *> world) {
    for (Location *l : world) {
        for (Creature *c : l->getMembers()) {

            if(c->is_NPC())
            {
                dynamic_cast<Creature_NPC*>(c)->AI();
            }
            c->actionStep();
        }
    }
}

int main() {

    vector<Location *> world;
    Location l1 = Location(1, 1);
    world.push_back(&l1);

    Hero platon = Hero("Platon");
    StupidOgre enemy = StupidOgre("Angry ogre");

    platon.changeLocation(&l1);
    enemy.changeLocation(&l1);

    platon.addSpell(new Fireball(&platon, 10, 20));
    platon.addSpell(new BaseHeal(&platon, 30, 10));

    while (platon.isAlive() && enemy.isAlive()) {
        worldActionStep(world);

        // *** HERO AI ***

        if (platon.getTarget() && platon.isIdle()) {
            if (platon.getStats().hp <= 50 && platon.hasEnoughMana(platon.getSpells()[1])) {
                platon.castSpell(platon.getSpells()[1]); // хилимся
            } else {
                platon.castSpell(platon.getSpells()[0]);
            }
        }

        // ***         ***

    }
    for (string msg : platon.getLog()) {
        cout << msg << endl;
    }
    return 0;
}
