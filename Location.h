#ifndef LOCATION_H
#define LOCATION_H

#include<iostream>
#include<vector>

class Creature;

using namespace std;

class Location {

public:
    Location(int x, int y);
    
    /**
     * Получить координаты локации
     * @return Вектор, где 0 - x, 1 - y
     */
    vector<int> getPosition();
    
    /**
     * Добавить существо в локацию
     * @param Указатель на добавляемое существо
     */
    void addMember(Creature* creature);

    /**
     * Получить список ссылок на существ в локации
     */
    vector<Creature*> getMembers();
    

private:
    int x, y; /// Координаты локации
    vector<Creature*> members;
};

#endif /* end of include guard LOCATION_H */

