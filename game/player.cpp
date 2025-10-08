#include "player.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constructor
player::player(string playername, string life)
    : name(playername), lifepath(life), body(0), reflex(0), tech(0),
      code(0), cool(0), eddies(0), streetcred(0), romancepoints(0) {}

// ===== GETTERS =====
string player::getname() const { return name; }
string player::getlifepath() const { return lifepath; }
string player::gethaircolor() const { return haircolor; }
string player::gethairstyle() const { return hairstyle; }
string player::geteyecolor() const { return eyecolor; }

string player::getvehicle() const { return vehicle; }

int player::getbody() const { return body; }
int player::getreflex() const { return reflex; }
int player::gettech() const { return tech; }
int player::getcode() const { return code; }
int player::getcool() const { return cool; }

int player::geteddies() const { return eddies; }
int player::getstreetcred() const { return streetcred; }
int player::getromancepoints() const { return romancepoints; }

vector<string> player::getinventory() const { return inventory; }

// ===== SETTERS =====
void player::setname(const string& newname) { name = newname; }
void player::setlifepath(const string& newlifepath) { lifepath = newlifepath; }
void player::sethaircolor(const string& newhaircolor) { haircolor = newhaircolor; }
void player::sethairstyle(const string& newhairstyle) { hairstyle = newhairstyle; }
void player::seteyecolor(const string& neweyecolor) { eyecolor = neweyecolor; }
void player::setvehicle(const string& newvehicle) { vehicle = newvehicle; }
void player::seteddies(int amount) { eddies = amount; }
void player::setstreetcred(int cred) { streetcred = cred; }

// ===== METHODS =====
void player::additem(const string& item) {
    inventory.push_back(item);
}


void player::showinventory() const {
    cout << "\n--- Inventory ---\n";
    for (const auto& item : inventory)
        cout << "- " << item << endl;
    cout << "-----------------\n";
}

void player::showstats() const {
    cout << "\n=== PLAYER STATS ===\n";
    cout << "Alias: " << name << endl;
    cout << "Life Path: " << lifepath << endl;
    cout << "Hair: " << haircolor << " " << hairstyle << endl;
    cout << "Eyes: " << eyecolor << endl;
    cout << "Street Cred: " << streetcred << endl;
    cout << "Eddies: " << eddies << endl;
    cout << "Vehicle: " << vehicle << endl;
    //cout << "Romance Points: " << romancepoints << endl;      //dont want seen by player 
    cout << "=====================\n";
}

void player::addromancepoints(int points) {
    romancepoints += points;
}
