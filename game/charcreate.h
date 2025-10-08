#ifndef CHARCREATE_H
#define CHARCREATE_H

#include <string>
#include <vector>
#include "player.h"
using namespace std;

// ===== HELPER FUNCTIONS =====
string haircolor(int haircolorchoice);
string hairstyle(int hairstylechoice);
string eyecolor(int eyecolorchoice);
string lifepath(int lifepathchoice);

// ===== CHARACTER CREATOR =====
player charcreate();

#endif
