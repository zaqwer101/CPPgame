#include "../headers/Location.h"

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
}

void Location::addMember(Creature* creature)
{
    this->members.push_back(creature);
}

vector<Creature*> Location::getMembers()
{
    return this->members; 
}

int* Location::getPosition()
{
    int *ar = new int[2] {this->x, this->y};
    return ar;
}

