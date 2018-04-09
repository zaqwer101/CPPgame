#include<iostream>
#include "Hero.h"
#include "Creature.h"
#include "Location.h"
using namespace std;

int main() 
{
    
   Location l1 = Location(1,1);
   cout << l1.getPosition()[0] << "/" << l1.getPosition()[1] << endl;

   Hero platon = Hero("Platon");
    
   platon.changeLocation(&l1);

   cout << l1.getMembers()[0]->getStats().name << endl;

   cout << platon.getLocation()->getPosition()[0] << "/" << platon.getLocation()->getPosition()[1] << endl;

}
