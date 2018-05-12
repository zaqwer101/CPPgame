#include "Location.h"
#include "../Creatures/Creature.h"

Location::Location(int x, int y, int size_x, int size_y)
{
    this->x = x;
    this->y = y;
    this->size_x = size_x;
    this->size_y = size_y;

    for (int i=0; i<size_y; i++)
        for(int f=0; f<size_x; f++)
            this->location.push_back(new LocationPoint {f, i, nullptr, true, this});
}

vector<int> Location::getLocationPosition()
{
   vector<int> position; 
   position.push_back(this->x);
   position.push_back(this->y);

   return position;
}

void Location::addMember(Creature* creature, LocationPoint *locationPoint)
{
    if(locationPoint->member == nullptr) {
        members.push_back(creature);
        locationPoint->member = creature;
    }
}

vector<Creature*> Location::getMembers()
{
    return this->members;
}

vector<LocationPoint *> Location::getLocation() {
    return location;
}

void Location::removeMember(Creature *creature) {
    if(creature->getLocation() == this)
    {
        int index = -1;
        // Получаем индекс существа в локации
        for(int i=0; i<getMembers().size(); i++)
        {
            if(getMembers()[i] == creature)
            {
                index = i;
                break;
            }
        }

        if(index != -1) {
            getMembers().erase(getMembers().begin() + index);
            creature->getLocationPoint()->member = nullptr;
        }
        else
            throw 228;
    }

}
