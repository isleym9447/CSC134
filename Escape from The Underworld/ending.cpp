#include "ending.h"
#include <iostream>
using namespace std;

bool checkEnding(Player& p){
    if(p.hp <= 0){
        cout << "\n💀 You collapsed in Asphodel. Your shade drifts… *Trapped in the Underworld.*\n";
        return true;
    }
    if(p.soul <= 0){
        cout << "\n🕯️ Your soul-light gutters out. *Trapped in Tartarus.*\n";
        return true;
    }
    if(p.roomsCleared >= 8){
        if(p.align == Alignment::Merciful && p.soul >= p.maxSoul/2)
            cout << "\n🌿 Gentle winds from Elysium greet you. *Ascend to Elysium (Merciful Rebirth).* \n";
        else if(p.align == Alignment::Vengeful)
            cout << "\n🔥 You claw your way up, leaving scorched footprints. *Reborn—Vengeful.*\n";
        else
            cout << "\n🌫️ The mists part. *Reborn—Neutral Wanderer.*\n";
        return true;
    }
    return false;
}