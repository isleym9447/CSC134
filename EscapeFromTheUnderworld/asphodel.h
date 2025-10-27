#pragma once
#include "intro.h"

// Runs the Asphodel “chapter”: story + one random event
// Returns false if the chapter ended the run (e.g., death), true to continue
bool asphodelChapter(Player& p);