#include "oracle.h"
#include <iostream>
using namespace std;

static int oraclePuzzleNumber(){ return R.i(3, 9); }

static string prophecyLine(int code){
    switch(code % 5){
        case 0: return "“Between twin serpents, choose the quieter fang.”";
        case 1: return "“Three times turned, the moon reveals the path.”";
        case 2: return "“Count not what shines, but what remains unseen.”";
        case 3: return "“When rivers meet, the shallower carries truth.”";
        default:return "“The hunter’s eye blinks once for mercy, twice for fate.”";
    }
}

bool oracleEvent(Player& p){
    cout << "\n🔮 The fumes rise in Delphi’s chamber. The Oracle speaks:\n";
    int omen = oraclePuzzleNumber();
    cout << prophecyLine(omen) << "\n";

    // Pattern: next = (prev * 2) % 10 for length 4
    vector<int> seq(4); seq[0] = omen;
    for(int i=1;i<4;i++) seq[i] = (seq[i-1]*2)%10;

    cout << "An omen appears: " << seq[0] << " " << seq[1] << " " << seq[2] << " ?\n";
    cout << "What number completes the pattern? ";
    string in; getline(cin, in);
    int guess = (in.empty()? -1 : stoi(in));
    int correct = seq[3];

    if(guess!=correct){
        cout << "Hint: Each step doubles the last and wraps at 10.\n";
        cout << "Try again: ";
        getline(cin, in); guess = (in.empty()? -1 : stoi(in));
    }
    if(guess==correct){
        cout << "✅ The Oracle nods. Your insight sharpens. (+1 roll boon, +1 Soul)\n";
        p.boonStacks += 1;
        p.soul = min(p.maxSoul, p.soul + 1);
        return true;
    } else {
        cout << "❌ The vapors cloud your mind. (Soul -1)\n";
        p.soul -= 1;
        return false;
    }
}