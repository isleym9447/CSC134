#include "tartarus.h"
#include "tartarus_events.h"
#include "ending.h"
#include <iostream>
using namespace std;

bool tartarusChapter(Player& p){
    cout << "\n🟥 TARTARUS DEPTHS\n";
    cout << "Iron chains clatter; cold wind carries whispers of oaths broken.\n";

    if(!tartarusRandomEvent(p)) return false;
    p.roomsCleared++;
    return !checkEnding(p);
}