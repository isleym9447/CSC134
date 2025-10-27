#include "asphodel_events.h"
#include "oracle.h"
#include <iostream>
using namespace std;

static void asphodelCombat(Player& p){
    cout << "\n👹 A wandering shade scours the ash.\n";
    bool init = skillCheck(p, "Initiative (avoid ambush)", 8);
    if(!init){ cout << "Caught off-guard. (HP -2)\n"; p.hp -= 2; }
    bool hit = skillCheck(p, "Cut through the cinder", 7);
    if(hit){
        cout << "The shade unravels.\n";
        cout << "Spare the remnant? (m)ercy / (v)engeance: ";
        string s; getline(cin, s);
        if(!s.empty() && (s[0]=='m'||s[0]=='M')){
            cout << "Mercy given. (+1 Soul)\n";
            p.soul = min(p.maxSoul, p.soul+1);
            p.align = (p.align==Alignment::Vengeful)? Alignment::Neutral : Alignment::Merciful;
        } else {
            cout << "Ended. (HP +1)\n";
            p.hp = min(p.maxHP, p.hp+1);
            p.align = (p.align==Alignment::Merciful)? Alignment::Neutral : Alignment::Vengeful;
        }
    } else {
        cout << "It scars you before vanishing. (HP -3, Soul -1)\n";
        p.hp -= 3; p.soul -= 1;
    }
}

static void asphodelShrine(Player& p){
    cout << "\n💎 A soot-black shrine hums faintly.\n";
    bool safe = skillCheck(p, "Discern lingering curse", 7);
    if(safe){
        cout << "A ember-blessing warms you. (HP +2, Soul +1)\n";
        p.hp = min(p.maxHP, p.hp+2);
        p.soul = min(p.maxSoul, p.soul+1);
    } else {
        cout << "Cinder curse clings. (Next roll -1, HP -1)\n";
        p.boonStacks = max(0, p.boonStacks-1);
        p.hp -= 1;
    }
}

static void asphodelRest(Player& p){
    cout << "\n🛶 A cool eddy in the Styx invites rest.\n";
    bool watch = skillCheck(p, "Keep watch", 6);
    if(watch){ cout << "You rest safely. (HP +2)\n"; p.hp=min(p.maxHP,p.hp+2); }
    else { cout << "Disturbed slumber. (HP -1)\n"; p.hp -= 1; }
}

bool asphodelRandomEvent(Player& p){
    int r = R.i(1,100);
    if(r<=35)      asphodelCombat(p);
    else if(r<=60) asphodelShrine(p);
    else if(r<=75) oracleEvent(p);
    else           asphodelRest(p);
    return p.hp>0 && p.soul>0;
}