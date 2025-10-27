#include "elysium_events.h"
#include "oracle.h"
#include <iostream>
using namespace std;

static void elysiumDuel(Player& p){
    cout << "\n⚔️  A champion challenges you to a friendly duel.\n";
    bool poise = skillCheck(p, "Poise & Timing", 7);
    if(poise){ cout << "Graceful victory. (+1 boon, +1 Soul)\n"; p.boonStacks+=1; p.soul=min(p.maxSoul,p.soul+1); }
    else { cout << "Stumbled. (HP -2)\n"; p.hp -= 2; }
}

static void elysiumGift(Player& p){
    cout << "\n🎁 A laurel-crowned spirit offers counsel.\n";
    bool heed = skillCheck(p, "Heed the counsel", 6);
    if(heed){ cout << "Wisdom settles. (HP +1, Soul +1)\n"; p.hp=min(p.maxHP,p.hp+1); p.soul=min(p.maxSoul,p.soul+1); }
    else { cout << "Pride stings. (HP -1)\n"; p.hp -= 1; }
}

static void elysiumRest(Player& p){
    cout << "\n🌙 You lounge beside a quiet stream.\n";
    p.hp = min(p.maxHP, p.hp+2);
    cout << "(HP +2)\n";
}

bool elysiumRandomEvent(Player& p){
    int r = R.i(1,100);
    if(r<=30)      elysiumDuel(p);
    else if(r<=55) elysiumGift(p);
    else if(r<=70) oracleEvent(p);
    else           elysiumRest(p);
    return p.hp>0 && p.soul>0;
}