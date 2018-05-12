#ifndef LOCATION_H
#define LOCATION_H

#include<iostream>
#include<vector>

class Creature;

using namespace std;

struct LocationPoint
{
    int x, y;
    Creature *member;
    bool isPassable;
};

class Location {

public:
    Location(int x, int y, int size_x, int size_y);
    int size_x, size_y;
    /**
     * Получить координаты локации
     * @return Вектор, где 0 - x, 1 - y
     */
    vector<int> getLocationPosition();

    /**
     * Добавить существо в локацию
     * @param creature Указатель на добавляемое существо
     */
    void addMember(Creature* creature);

    /**
     * Получить список ссылок на существ в локации
     */
    vector<Creature*> getMembers();
    

private:
    int x, y; /// Координаты локации
    vector<LocationPoint *> location;
    vector<Creature*> members;
};

#endif /* end of include guard LOCATION_H */

