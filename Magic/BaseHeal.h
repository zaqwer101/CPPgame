#ifndef CPPGAME_BASEHEAL_H
#define CPPGAME_BASEHEAL_H


#include "MagicSpell.h"

class BaseHeal : public MagicSpell {
public:
    BaseHeal(int power, int manacost);

    void use() override;

};

#endif //CPPGAME_BASEHEAL_H
