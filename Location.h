#ifndef LOCATION_H

#define LOCATION_H
#include "Creature.h"
#include<iostream>
#include<vector>

using namespace std;

class Location {

public:
    Location(int x, int y);
    
    /**
     * Получить координаты локации
     */
    vector<int> getPosition();
    
    /**
     * Добавить существо в локацию
     * \param Ссылка на добавляемое существо
     */
    void addMember(Creature* creature);

    /**
     * Получить список ссылок на существ в локации
     */
    vector<Creature*> getMembers();
    

private:
    /**
     * Координаты локации
     */
    int x, y; 
    vector<Creature*> members;
};

#endif /* end of include guard LOCATION_H */

