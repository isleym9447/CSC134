#include "intro.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

RNG R;

string alignStr(Alignment a){
    if(a==Alignment::Merciful) return "Merciful";
    if(a==Alignment::Vengeful) return "Vengeful";
    return "Neutral";
}

void asciiIntro() {
    cout <<
R"( 
   ____  _          _        ____           _                 _ 
  / ___|| |__   ___| |_     |  _ \ ___  ___| | ___  _   _  __| |
  \___ \| '_ \ / _ \ __|____| |_) / _ \/ __| |/ _ \| | | |/ _` |
   ___) | | | |  __/ ||_____|  _ <  __/\__ \ | (_) | |_| | (_| |
  |____/|_| |_|\___|\__|    |_| \_\___||___/_|\___/ \__,_|\__,_|
)" << "\n";
    cout << "     Flames lick the banks of the Styx. Skulls watch in silence.\n";
}

// -------- Gods --------
God randomGod() {
    vector<God> g = {
        {"Athena","Strategic Insight (+1 to all rolls).", +1, 0, 0, "Aegis Glint","Once: +4 to one roll."},
        {"Ares","Bloodlust (+2 HP max).", 0, +2, 0, "War Cry","Once: +4 to one roll."},
        {"Hermes","Fleetfoot (+1 to all rolls).", +1, 0, 0, "Winged Sandal","Once: +4 to one roll."},
        {"Poseidon","Tide-Blessed (+1 Soul, +1 max Soul).", 0, 0, +1, "Trident Echo","Once: +4 to one roll."},
        {"Hades","Underworld Favor (+2 Soul max).", 0, 0, +2, "Stygian Coin","Once: +4 to one roll."},
        {"Artemis","Hunter’s Focus (+1 to all rolls).", +1, 0, 0, "Moon Arrow","Once: +4 to one roll."},
        {"Zeus","Thunder’s Boon (+2 HP max).", 0, +2, 0, "Bolt Fragment","Once: +4 to one roll."}
    };
    return g[R.i(0, (int)g.size()-1)];
}

void initBaseStats(Player& p){
    p.maxHP = 8; p.hp = p.maxHP;
    p.maxSoul = 6; p.soul = p.maxSoul;
}

void applyGodPassives(Player& p){
    p.maxHP += p.god.maxHPBonus;  p.hp = p.maxHP;
    p.maxSoul += p.god.soulBonus; p.soul = p.maxSoul;
}

static void bar(const string& label, int v, int vmax){
    cout << label << " [";
    int width = 12, fill = max(0, min(width, (v*width)/max(1,vmax)));
    for(int i=0;i<fill;i++) cout << '#';
    for(int i=fill;i<width;i++) cout << '-';
    cout << "] " << v << "/" << vmax << "\n";
}

void showHUD(const Player& p){
    cout << "\n================= STYX PASSAGE =================\n";
    cout << "Demigod: " << p.name << " | Parent: " << p.god.name
         << " | Align: " << alignStr(p.align) << " | Rooms: " << p.roomsCleared << "\n";
    bar("HP  ", p.hp, p.maxHP);
    bar("SOUL", p.soul, p.maxSoul);
    cout << "Passive: " << p.god.passive
         << " | Oracle Boons: +" << p.boonStacks << " roll\n";
    cout << "God Item: " << p.god.itemName << (p.itemAvailable? " (ready)":" (used)") << "\n";
    cout << "================================================\n";
}

// -------- Dice & checks --------
int rollDie(int sides) { return R.i(1, sides); }
int roll2d6() { return rollDie(6) + rollDie(6); }

int askUseItem(Player& p){
    if(!p.itemAvailable) return 0;
    cout << "Use your god item \"" << p.god.itemName << "\" for +4 to this roll? (y/n): ";
    string s; getline(cin, s);
    if(!s.empty() && (s[0]=='y'||s[0]=='Y')) {
        p.itemAvailable = false;
        cout << ">> " << p.god.itemName << " flashes! (+4)\n";
        return 4;
    }
    return 0;
}

int skillCheck(Player& p, const string& label, int target){
    cout << "\n-- Check: " << label << " (Target " << target << ") --\n";
    int base = roll2d6();
    int bonus = p.god.rollBonus + p.boonStacks;
    int item  = askUseItem(p);
    int total = base + bonus + item;
    cout << "You roll 2d6: " << base << " + bonuses(" << bonus << ") + item(" << item << ") = " << total << "\n";
    return total >= target ? 1 : 0;
}