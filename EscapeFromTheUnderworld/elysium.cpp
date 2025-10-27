#include "elysium.h"
#include "elysium_events.h"
#include "ending.h"
#include <iostream>
using namespace std;

bool elysiumChapter(Player& p){
    cout << "\n🟩 FIELDS OF ELYSIUM\n";
    cout << "Soft grasses and golden light—yet trials remain.\n";

    if(!elysiumRandomEvent(p)) return false;
    p.roomsCleared++;
    return !checkEnding(p);
}
