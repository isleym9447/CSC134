#ifndef CHARCREATE_H
#define CHARCREATE_H

#include <string>
#include "player.h"

// ===== HELPER FUNCTIONS =====
std::string haircolor(int haircolorchoice);
std::string hairstyle(int hairstylechoice);
std::string eyecolor(int eyecolorchoice);
std::string lifepath(int lifepathchoice);

// ===== CHARACTER CREATOR =====
player charcreate();

#endif // CHARCREATE_H
