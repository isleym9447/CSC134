#include <bits/stdc++.h>
using namespace std;

// ---------- Utility RNG ----------
struct RNG {
    mt19937 rng{ (uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count() };
    int i(int lo, int hi) { uniform_int_distribution<int> d(lo,hi); return d(rng); }
    bool chance(int pct) { return i(1,100) <= pct; }
} R;

// ---------- Dice ----------
int rollDie(int sides) { return R.i(1, sides); }
int roll2d6() { return rollDie(6) + rollDie(6); }

// ---------- Enums ----------
enum class Alignment { Merciful, Neutral, Vengeful };
enum class EventType { Combat, Treasure, Deity, Oracle, Rest };

// ---------- Data Models ----------
struct God {
    string name;
    string passive;          // description
    int rollBonus = 0;       // passive to all checks
    int maxHPBonus = 0;      // passive HP
    int soulBonus = 0;       // passive Soul
    string itemName;         // one-use
    string itemDesc;
    // item effect: simple +4 to any ONE roll when used
};

struct Player {
    string name;
    God god;
    int hp, maxHP;
    int soul, maxSoul;
    int boonStacks = 0;      // from Oracle successes (+1 per correct)
    bool itemAvailable = true;
    Alignment align = Alignment::Neutral;
    int roomsCleared = 0;
};

string alignStr(Alignment a){
    if(a==Alignment::Merciful) return "Merciful";
    if(a==Alignment::Vengeful) return "Vengeful";
    return "Neutral";
}

// ---------- Gods Dictionary ----------
God randomGod() {
    vector<God> g = {
        {"Athena","Strategic Insight (+1 to all rolls).", +1, 0, 0, "Aegis Glint","Once: +4 to one roll."},
        {"Ares","Bloodlust (+2 HP max).", 0, +2, 0, "War Cry","Once: +4 to one roll."},
        {"Hermes","Fleetfoot (+1 to all rolls).", +1, 0, 0, "Winged Sandal","Once: +4 to one roll."},
        {"Poseidon","Tide-Blessed (+1 Soul, +1 max Soul).", 0, 0, +1, "Trident Echo","Once: +4 to one roll."},
        {"Hades","Underworld Favor (+2 Soul max).", 0, 0, +2, "Stygian Coin","Once: +4 to one roll."},
        {"Artemis","Hunter’s Focus (+1 to all rolls).", +1, 0, 0, "Moon Arrow","Once: +4 to one roll."},
        {"Zeus","Thunder’s Boon (+2 HP max).", 0, +2, 0, "Bolt Fragment","Once: +4 to one roll."}
    };
    return g[R.i(0, (int)g.size()-1)];
}

// ---------- UI Helpers ----------
void bar(const string& label, int v, int vmax){
    cout << label << " [";
    int width = 12, fill = max(0, min(width, (v*width)/max(1,vmax)));
    for(int i=0;i<fill;i++) cout << '#';
    for(int i=fill;i<width;i++) cout << '-';
    cout << "] " << v << "/" << vmax << "\n";
}

void showHUD(const Player& p){
    cout << "\n================= STYX PASSAGE =================\n";
    cout << "Demigod: " << p.name << " | Parent: " << p.god.name
         << " | Align: " << alignStr(p.align) << " | Rooms: " << p.roomsCleared << "\n";
    bar("HP  ", p.hp, p.maxHP);
    bar("SOUL", p.soul, p.maxSoul);
    cout << "Passive: " << p.god.passive
         << " | Oracle Boons: +" << p.boonStacks << " roll\n";
    cout << "God Item: " << p.god.itemName << (p.itemAvailable? " (ready)":" (used)") << "\n";
    cout << "================================================\n";
}

// ---------- Endings ----------
bool checkEnding(const Player& p){
    if(p.hp <= 0) {
        cout << "\n💀 You collapsed in Asphodel. Your shade drifts… *Trapped in the Underworld.*\n";
        return true;
    }
    if(p.soul <= 0) {
        cout << "\n🕯️ Your soul-light gutters out. *Trapped in Tartarus.*\n";
        return true;
    }
    if(p.roomsCleared >= 8) {
        if(p.align == Alignment::Merciful && p.soul >= p.maxSoul/2)
            cout << "\n🌿 Gentle winds from Elysium greet you. *Ascend to Elysium (Merciful Rebirth).* \n";
        else if(p.align == Alignment::Vengeful)
            cout << "\n🔥 You claw your way up, leaving scorched footprints. *Reborn—Vengeful.*\n";
        else
            cout << "\n🌫️ The mists part. *Reborn—Neutral Wanderer.*\n";
        return true;
    }
    return false;
}

// ---------- Dice Check ----------
int askUseItem(Player& p){
    if(!p.itemAvailable) return 0;
    cout << "Use your god item \"" << p.god.itemName << "\" for +4 to this roll? (y/n): ";
    string s; getline(cin, s);
    if(!s.empty() && (s[0]=='y' || s[0]=='Y')) {
        p.itemAvailable = false;
        cout << ">> " << p.god.itemName << " flashes! (+4)\n";
        return 4;
    }
    return 0;
}

int skillCheck(Player& p, const string& label, int target){
    cout << "\n-- Check: " << label << " (Target " << target << ") --\n";
    int base = roll2d6();
    int bonus = p.god.rollBonus + p.boonStacks;
    int item = askUseItem(p);
    int total = base + bonus + item;
    cout << "You roll 2d6: " << base << " + bonuses(" << bonus << ") + item(" << item << ") = " << total << "\n";
    return total >= target ? 1 : 0;
}

// ---------- Oracle of Delphi ----------
int oraclePuzzleNumber(){ return R.i(3, 9); }

// cryptic prophecy lines
string prophecyLine(int code){
    switch(code % 5){
        case 0: return "“Between twin serpents, choose the quieter fang.”";
        case 1: return "“Three times turned, the moon reveals the path.”";
        case 2: return "“Count not what shines, but what remains unseen.”";
        case 3: return "“When rivers meet, the shallower carries truth.”";
        default:return "“The hunter’s eye blinks once for mercy, twice for fate.”";
    }
}

// Simple number/logic puzzle: sum-of-digits parity & sequence guess
bool oracleEvent(Player& p){
    cout << "\n🔮 The fumes rise in Delphi’s chamber. The Oracle speaks:\n";
    int omen = oraclePuzzleNumber();
    cout << prophecyLine(omen) << "\n";
    // Build a small pattern: Start with omen, sequence of length 4 where next = (prev * 2) % 10
    vector<int> seq(4); seq[0] = omen;
    for(int i=1;i<4;i++) seq[i] = (seq[i-1]*2)%10;
    cout << "An omen appears: ";
    for(int i=0;i<3;i++) cout << seq[i] << " ";
    cout << "?\n";
    cout << "What number completes the pattern? ";
    string in; getline(cin, in);
    int guess = (in.empty()? -1 : stoi(in));
    int correct = seq[3];

    // Hints
    if(guess!=correct){
        cout << "Hint: Each step doubles the last and wraps at 10.\n";
        cout << "Try again: ";
        getline(cin, in); guess = (in.empty()? -1 : stoi(in));
    }
    if(guess==correct){
        cout << "✅ The Oracle nods. Your insight sharpens. (+1 roll boon)\n";
        p.boonStacks += 1;
        p.soul = min(p.maxSoul, p.soul + 1);
        return true;
    } else {
        cout << "❌ The vapors cloud your mind. (Soul -1)\n";
        p.soul -= 1;
        return false;
    }
}

// ---------- Events ----------
void combatEvent(Player& p){
    cout << "\n👹 A shade of Tartarus emerges!\n";
    // Simple two checks: INIT then STRIKE
    bool init = skillCheck(p, "Initiative (avoid ambush)", 8);
    if(!init){
        cout << "You were clipped in the first exchange. (HP -2)\n";
        p.hp -= 2;
    }
    bool strike = skillCheck(p, "Strike the shade", 7);
    if(strike){
        cout << "You disperse the shade!\n";
        // alignment nudge: choosing mercy VS finish
        cout << "Spare the cowering remnant? (m)ercy / (v)engeance: ";
        string s; getline(cin,s);
        if(!s.empty() && (s[0]=='m'||s[0]=='M')){
            cout << "Mercy given. (+1 Soul)\n"; p.soul = min(p.maxSoul, p.soul+1);
            if(p.align==Alignment::Vengeful) p.align=Alignment::Neutral; else p.align=Alignment::Merciful;
        } else {
            cout << "You end it. (HP +1)\n"; p.hp = min(p.maxHP, p.hp+1);
            if(p.align==Alignment::Merciful) p.align=Alignment::Neutral; else p.align=Alignment::Vengeful;
        }
    }else{
        cout << "It overpowers you before fading. (HP -3, Soul -1)\n";
        p.hp -= 3; p.soul -= 1;
    }
}

void treasureEvent(Player& p){
    cout << "\n💎 You find an offering at a roadside shrine.\n";
    bool safe = skillCheck(p, "Discern trap", 7);
    if(safe){
        cout << "A blessing radiates. (HP +2, Soul +1)\n";
        p.hp = min(p.maxHP, p.hp+2);
        p.soul = min(p.maxSoul, p.soul+1);
    } else {
        cout << "A whispering curse lingers. (Next roll -1)\n";
        // apply as a temporary debuff by reducing boonStacks, but not below -1 marker
        p.boonStacks = max(p.boonStacks-1, 0);
        p.hp -= 1;
    }
}

void deityEvent(Player& p){
    cout << "\n👁️ A god notices your journey. ";
    if(R.chance(60)){
        cout << "Favor smiles upon you. (+1 Soul, +1 boon)\n";
        p.soul = min(p.maxSoul, p.soul+1);
        p.boonStacks += 1;
    } else {
        cout << "A test of pride. Make a Devotion check.\n";
        bool pass = skillCheck(p, "Devotion", 8);
        if(pass){ cout << "Accepted.\n"; p.boonStacks += 1; }
        else { cout << "Scorched by hubris. (HP -2)\n"; p.hp -= 2; }
    }
}

void restEvent(Player& p){
    cout << "\n🛶 You drift along a calm bend of the Styx. You may **Rest**.\n";
    bool pass = skillCheck(p, "Keep watch while resting", 6);
    if(pass){ cout << "You rest safely. (HP +2)\n"; p.hp = min(p.maxHP, p.hp+2); }
    else { cout << "Ambushed mid-slumber! (HP -1, but you still regain +1)\n"; p.hp = min(p.maxHP, p.hp); }
}

bool runEvent(Player& p){
    EventType e;
    int r = R.i(1,100);
    if(r<=30) e = EventType::Combat;
    else if(r<=50) e = EventType::Treasure;
    else if(r<=65) e = EventType::Deity;
    else if(r<=80) e = EventType::Oracle;
    else e = EventType::Rest;

    switch(e){
        case EventType::Combat:  combatEvent(p);  break;
        case EventType::Treasure:treasureEvent(p);break;
        case EventType::Deity:   deityEvent(p);   break;
        case EventType::Oracle:  oracleEvent(p);  break;
        case EventType::Rest:    restEvent(p);    break;
    }
    p.roomsCleared++;
    return !checkEnding(p);
}

// ---------- Intro + Setup ----------
void asciiIntro(){
    cout <<
R"( 
   ____  _          _        ____           _                 _ 
  / ___|| |__   ___| |_     |  _ \ ___  ___| | ___  _   _  __| |
  \___ \| '_ \ / _ \ __|____| |_) / _ \/ __| |/ _ \| | | |/ _` |
   ___) | | | |  __/ ||_____|  _ <  __/\__ \ | (_) | |_| | (_| |
  |____/|_| |_|\___|\__|    |_| \_\___||___/_|\___/ \__,_|\__,_|
    )" << "\n";
    cout << "     Flames lick the banks of the Styx. Skulls watch in silence.\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    asciiIntro();

    Player p;
    cout << "Your name, demigod? ";
    getline(cin, p.name);
    p.god = randomGod();

    // Base stats
    p.maxHP = 8; p.hp = p.maxHP;
    p.maxSoul = 6; p.soul = p.maxSoul;

    // Apply god passives
    p.maxHP += p.god.maxHPBonus; p.hp = p.maxHP;
    p.maxSoul += p.god.soulBonus; p.soul = p.maxSoul;

    cout << "\nA whisper from the dark: \"" << p.god.name << " claims you.\" "
         << "(" << p.god.passive << ")\n";
    cout << "You carry a one-use gift: " << p.god.itemName << " — " << p.god.itemDesc << "\n";

    // Main loop
    while(true){
        showHUD(p);
        cout << "\nChoose a path: (1) Asphodel (2) Elysium (3) Tartarus (q to quit): ";
        string c; getline(cin,c);
        if(!c.empty() && (c[0]=='q'||c[0]=='Q')) { cout << "You drift… the journey pauses.\n"; break; }
        cout << "\nYou tread the path...\n";
        if(!runEvent(p)) break; // ended
        if(p.hp<=0 || p.soul<=0) break;
    }

    cout << "\n-- THE END --\n";
    return 0;
}