#include "Asphodel.h"
#include "asphodel_events.h"
#include "ending.h"
#include <iostream>
using namespace std;

bool asphodelChapter(Player& p){
    cout << "\n🟧 ASH-FIELDS OF ASPHODEL\n";
    cout << "Ash drifts like snow; pale stems sway without flowers.\n";

    if(!asphodelRandomEvent(p)) return false; // event may end the run
    p.roomsCleared++;
    return !checkEnding(p);
}