#include "Location.h"

Location::Location(int x, int y, int size_x, int size_y)
{
    this->x = x;
    this->y = y;
    this->size_x = size_x;
    this->size_y = size_y;

    for (int i=0; i<size_y; i++)
        for(int f=0; f<size_x; f++)
            this->location.push_back(new LocationPoint {f, i, nullptr, true});
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
