#include<iostream>
#include "Creature.h"
using namespace std;

int main() 
{
    Creature tester = Creature("Tester", 1, 1, 1, 10);
    Creature dummy = Creature("Dummy", 350, 0, 0, 0);
    
    while (dummy.isAlive())
    {
        tester.attack(dummy);
    }
    
    cout << "Уровень:" << tester.getStats().level << endl 
            << "EXP: " << tester.getStats().exp << "/" << tester.getStats().exp_to_level << endl;
    
    return 0;
}

