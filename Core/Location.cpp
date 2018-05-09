#include "Location.h"

Location::Location(int x, int y)
{
    this->x = x;
    this->y = y;
}

vector<int> Location::getLocationPosition()
{
   vector<int> position; 
   position.push_back(this->x);
   position.push_back(this->y);

   return position;
}

void Location::addMember(Creature* creature)
{
    this->members.push_back(creature);
}

vector<Creature*> Location::getMembers()
{
    return this->members;
}
