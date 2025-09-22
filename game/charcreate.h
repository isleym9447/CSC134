//used chatgpt for this 

// charcreate.h
#ifndef CHARCREATE_H
#define CHARCREATE_H

#include <string>
#include <vector>
using namespace std;

// ===== GLOBAL VARIABLES =====
extern int haircolorChoice;
extern int eyecolorChoice;
extern int hairstylechoice;
extern int lifepathchoice;

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

#endif
