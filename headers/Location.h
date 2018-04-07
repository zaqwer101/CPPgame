#ifndef LOCATION_H

#define LOCATION_H

#include<iostream>
#include "Creature.h"
#include<vector>
using namespace std;

class Location {

public:
    Location(int x, int y);

    /**
     *  Получить вектор ссылок на существ в локации
     */
    vector<Creature*> getMembers();

    /**
     *  Добавить существо в локацию
     *  \param creature Ссылка на существо
     */
    void addMember(Creature* creature);

    /**
     *  Получить координаты локации
     *  \return Массив из двух элементов вида {x, y}
     */
    int* getPosition();
private:

    /**
     *  Вектор ссылок на существ в локации
     */
    vector<Creature*> members;
    int x, y;
};


#endif

