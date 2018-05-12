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

    Location l1 = Location(0,0,10,10);
    Location *location_pointer = &l1;
    Hero hero = Hero("Platon", location_pointer->getLocation()[0]);
    hero.changeLocation(location_pointer, location_pointer->getLocation()[1]);

    for(auto message : hero.getLog())
    {
        cout << message << endl;
    }

    return 0;
}
