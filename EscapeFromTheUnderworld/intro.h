#pragma once
#include <bits/stdc++.h>
using namespace std;

enum class Alignment { Merciful, Neutral, Vengeful };

// -------- RNG --------
struct RNG {
    mt19937 rng{ (uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count() };
    int i(int lo, int hi) { uniform_int_distribution<int> d(lo,hi); return d(rng); }
    bool chance(int pct) { return i(1,100) <= pct; }
};
extern RNG R;

// -------- Core Data --------
struct God {
    string name;
    string passive;
    int rollBonus = 0;
    int maxHPBonus = 0;
    int soulBonus = 0;
    string itemName;
    string itemDesc;
};

struct Player {
    string name;
    God god;
    int hp=0, maxHP=0;
    int soul=0, maxSoul=0;
    int boonStacks=0;
    bool itemAvailable=true;
    Alignment align=Alignment::Neutral;
    int roomsCleared=0;
};

// -------- API from intro.cpp --------
void asciiIntro();
God  randomGod();
void initBaseStats(Player& p);
void applyGodPassives(Player& p);
void showHUD(const Player& p);

// dice & checks
int  rollDie(int sides);
int  roll2d6();
int  askUseItem(Player& p);        // +4 once if used
int  skillCheck(Player& p, const string& label, int target);
string alignStr(Alignment a);