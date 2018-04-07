#include<iostream>
#include "../headers/Hero.h"
#include "../headers/Creature.h"
using namespace std;

int main() 
{
    Hero zaqwer101 = Hero("Platon");
    Hero dummy = Hero("Dummy");
    
    zaqwer101.__debug_printStats();
    
    while(dummy.isAlive())
    {
        cout << zaqwer101.getStats().name << " атаковал " << dummy.getStats().name << ", нанеся " << zaqwer101.attack(dummy) << " единиц урона" << endl;
    }

    zaqwer101.takeExp(300);
    zaqwer101.__debug_printStats();
}

