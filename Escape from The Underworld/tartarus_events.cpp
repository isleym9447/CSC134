#include "tartarus_events.h"
#include "oracle.h"
#include <iostream>
using namespace std;

static void tartarusPunisher(Player& p){
    cout << "\n⛓️  A Punisher of Tartarus descends.\n";
    bool stand = skillCheck(p, "Stand your ground", 8);
    if(!stand){ cout << "Crushed under dread. (HP -3, Soul -1)\n"; p.hp-=3; p.soul-=1; return; }
    bool riposte = skillCheck(p, "Riposte through the chain", 9);
    if(riposte){ cout << "You break a link. (+1 boon)\n"; p.boonStacks+=1; }
    else { cout << "Driven back. (HP -2)\n"; p.hp -= 2; }
}

static void tartarusBargain(Player& p){
    cout << "\n🪙 A warden offers a cruel bargain: trade Soul for safety.\n";
    cout << "Accept? (y/n): ";
    string s; getline(cin, s);
    if(!s.empty() && (s[0]=='y'||s[0]=='Y')){
        cout << "You harden your heart. (Soul -1, HP +2)\n";
        p.soul -= 1; p.hp = min(p.maxHP, p.hp+2);
        p.align = (p.align==Alignment::Merciful)? Alignment::Neutral : Alignment::Vengeful;
    } else {
        cout << "You refuse. (Mercy steadies you. +1 Soul)\n";
        p.soul = min(p.maxSoul, p.soul+1);
        p.align = (p.align==Alignment::Vengeful)? Alignment::Neutral : Alignment::Merciful;
    }
}

static void tartarusRest(Player& p){
    cout << "\n🧊 A narrow alcove to catch your breath.\n";
    bool calm = skillCheck(p, "Calm the terror", 7);
    if(calm){ cout << "A moment of stillness. (HP +2)\n"; p.hp=min(p.maxHP,p.hp+2); }
    else { cout << "Nightmares bite. (HP -1)\n"; p.hp -= 1; }
}

bool tartarusRandomEvent(Player& p){
    int r = R.i(1,100);
    if(r<=40)      tartarusPunisher(p);
    else if(r<=65) tartarusBargain(p);
    else if(r<=80) oracleEvent(p);
    else           tartarusRest(p);
    return p.hp>0 && p.soul>0;
}