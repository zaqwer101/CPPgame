#include<iostream>
#include "Hero.h"
#include "Creature.h"
#include "Location.h"
#include "StupidOgre.h"
#include <ncurses.h>

using namespace std;

static void worldActionStep(vector<Location *> world) {
    for (Location *l : world) {
        for (Creature *c : l->getMembers()) {

            if(c->is_NPC())
            {
                dynamic_cast<Creature_NPC*>(c)->AI();
            }
            c->currentActionStep();
        }
    }
}

int main() {
    int step = 0;
    vector<Location *> world;
    Location l1 = Location(1, 1);
    world.push_back(&l1);

    Hero platon = Hero("Platon");
    StupidOgre enemy = StupidOgre("Ogre");

    platon.changeLocation(&l1);
    enemy.changeLocation(&l1);

    while (platon.isAlive()) {
        step++;
        cout << "Шаг: " << step << endl;
        worldActionStep(world);
    }
}
