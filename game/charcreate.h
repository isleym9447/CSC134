//used chatgpt for this 

// charcreate.h
#ifndef CHARCREATE_H
#define CHARCREATE_H

#include <string>
#include <vector>
using namespace std;

// ===== GLOBAL VARIABLES =====

extern int haircolorchoice;
extern int eyecolorchoice;
extern int hairstylechoice;
extern int lifepathchoice;
extern string playername;


extern int streetcred;
extern int eddies;
extern vector<string> inventory;
extern string vehicle;
extern bool corpoinfluence;

// ===== HELPER FUNCTIONS =====
string haircolor(int haircolorchoice);
string eyecolor(int eyecolorchoice);
string hairstyle(int hairstylechoice);
string lifepath(int lifepathchoice);

// ===== CHARACTER CREATOR =====
void charcreate();


// ===== PLAYER UTILITIES =====
void checkstats();     // show player stats
void quitgame();       // clean exit
int getplayerchoice(); // wrapper for inputs (handles 0 & 9)





#endif
