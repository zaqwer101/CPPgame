#ifndef CPPGAME_MAGICSPELL_H
#define CPPGAME_MAGICSPELL_H

#include <iostream>

class Creature;

using namespace std;

class MagicSpell {
public:
    MagicSpell(string name, string type, int cooldown, int power, int manacost, int cast_time);

    /**
     * Использовать заклинание от имени кастера
     */
    virtual void use();

    string name;
    int cooldown;

    /// Время, оставшееся до истечения кулдауна и появления возможности использовать заклинание
    int remaining_time;

    int getPower();

    string getType();

    int getManacost();

    Creature *getCaster();

    void setCaster(Creature *caster);

    int getCastTime();

private:
    string type;
    int power;
    int manacost;
    int cast_time;
    Creature *caster;
};

#endif //CPPGAME_MAGICSPELL_H
