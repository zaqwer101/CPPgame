#ifndef CPPGAME_STUPIDOGRE_H
#define CPPGAME_STUPIDOGRE_H


#include "Creature_NPC.h"

class StupidOgre : public Creature_NPC { /// Тестовый NPC-противник с примитивным ИИ
public:
    StupidOgre(const string &name, LocationPoint *locationPoint);

    void lvlUp_upgradeStats() override;

    void AI() override;
};


#endif //CPPGAME_STUPIDOGRE_H
