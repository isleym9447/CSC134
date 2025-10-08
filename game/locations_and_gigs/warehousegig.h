#ifndef WAREHOUSEGIG_H
#define WAREHOUSEGIG_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// shared player data from charcreate.cpp
extern int health;
extern int streetcred;
extern int eddies;
extern string weapon;
extern vector<string> inventory;

// warehouse gig sections
void warehousegig();     // main entry
void travelmenu();       // travel phase
void gunsblazing();      // combat path
void stealthpath();      // stealth path
void displayhud();       // HUD banner

#endif
