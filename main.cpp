#include<iostream>
#include "Hero.h"
#include "Creature.h"
#include "Location.h"
#include "StupidOgre.h"
#include <ncurses.h>
#include <string>

using namespace std;

/*static void drawInterface(Hero *hero) {
    int row, col;
    row = getmaxy(stdscr);
    col = getmaxx(stdscr);

    string str_exp = "Level: " + to_string(hero->getStats().level) + " (" + to_string(hero->getStats().exp) + "/" +
                     to_string(hero->getStats().exp_to_level) + ")";
    string str_location = "Location: " + to_string(hero->getLocation()->getPosition()[0]) + "/" +
                          to_string(hero->getLocation()->getPosition()[1]);
    string str_hero =
            hero->getStats().name + " (" + to_string(hero->getStats().hp) + "/" + to_string(hero->getStats().maxhp) +
            ")";

    mvwprintw(stdscr, 0, 0, str_hero.c_str());
    mvwprintw(stdscr, 0, static_cast<int>(col / 2 - str_location.length() / 2), str_location.c_str());
    mvwprintw(stdscr, 0, static_cast<int>(col - str_exp.length()), str_exp.c_str());
    mvwprintw(stdscr, 1, col / 2 - hero->actionGet().length() / 2, hero->actionGet().c_str());
    mvwprintw(stdscr, 2, 0, "Log:");

    vector<string> log = hero->getLastLog(row - 3);
    for (int i = 0; i < log.size(); i++) {
        mvwprintw(stdscr, i + 3, 0, log[i].c_str());
    }


}
*/
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

/*void ncurses_handler()
{
    initscr();

    vector<Location *> world;
    Location l1 = Location(1, 1);
    world.push_back(&l1);
    Hero platon = Hero("Hero");
    StupidOgre enemy = StupidOgre("Angry ogre");
    platon.changeLocation(&l1);
    enemy.changeLocation(&l1);

    while (platon.isAlive()) {
        worldActionStep(world);
        drawInterface(&platon);
        getch();
        clear();
    }
    getch();
    endwin();
}
*/
int main() {

    vector<Location *> world;
    Location l1 = Location(1, 1);
    world.push_back(&l1);

    Hero platon = Hero("Platon");
    StupidOgre enemy = StupidOgre("Angry ogre");

    platon.changeLocation(&l1);
    enemy.changeLocation(&l1);

    while (platon.isAlive()) {
        worldActionStep(world);
        cout << enemy.getLastLog(1)[0] << endl;
    }

    return 0;
}
