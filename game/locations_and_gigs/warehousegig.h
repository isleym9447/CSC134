#ifndef WAREHOUSEGIG_H
#define WAREHOUSEGIG_H

#include <iostream>
#include <string>
#include "player.h"

// warehouse gig sections
void warehousegig(player& currentPlayer);        // main entry
void travelmenu(player& currentPlayer);          // travel phase
void gunsblazing(player& currentPlayer);         // combat path
void stealthpath(player& currentPlayer);         // stealth path
void displayhud(const player& currentPlayer);    // HUD banner

#endif
