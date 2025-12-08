#include "player.h"
#include <iostream>

player::player(const std::string& playername, const std::string& life)
    : name(playername),
      lifepath(life),
      hairstyle(""),
      haircolor(""),
      eyecolor(""),
      body(0),
      reflex(0),
      tech(0),
      code(0),
      cool(0),
      eddies(0),
      streetcred(0),
      romancepoints(0) {}

// ===== GETTERS =====
std::string player::getname() const       { return name; }
std::string player::getlifepath() const   { return lifepath; }
std::string player::gethaircolor() const  { return haircolor; }
std::string player::gethairstyle() const  { return hairstyle; }
std::string player::geteyecolor() const   { return eyecolor; }
std::string player::getvehicle() const    { return vehicle; }

int player::getbody() const    { return body; }
int player::getreflex() const  { return reflex; }
int player::gettech() const    { return tech; }
int player::getcode() const    { return code; }
int player::getcool() const    { return cool; }

int player::geteddies() const      { return eddies; }
int player::getstreetcred() const  { return streetcred; }
int player::getromancepoints() const { return romancepoints; }

std::vector<std::string> player::getinventory() const {
    return inventory;
}

// ===== SETTERS =====
void player::setname(const std::string& newname)           { name = newname; }
void player::setlifepath(const std::string& newlifepath)   { lifepath = newlifepath; }
void player::sethaircolor(const std::string& newhaircolor) { haircolor = newhaircolor; }
void player::sethairstyle(const std::string& newhairstyle) { hairstyle = newhairstyle; }
void player::seteyecolor(const std::string& neweyecolor)   { eyecolor = neweyecolor; }
void player::setvehicle(const std::string& newvehicle)     { vehicle = newvehicle; }
void player::seteddies(int amount)                         { eddies = amount; }
void player::setstreetcred(int cred)                       { streetcred = cred; }

// stat setters
void player::setbody(int value)   { body   = value; }
void player::setreflex(int value) { reflex = value; }
void player::settech(int value)   { tech   = value; }
void player::setcode(int value)   { code   = value; }
void player::setcool(int value)   { cool   = value; }

// ===== METHODS =====
void player::additem(const std::string& item) {
    inventory.push_back(item);
}

void player::showinventory() const {
    std::cout << "\n--- Inventory ---\n";
    for (const auto& item : inventory) {
        std::cout << "- " << item << '\n';
    }
    std::cout << "-----------------\n";
}

void player::showstats() const {
    std::cout << "\n=== PLAYER STATS ===\n";
    std::cout << "Alias: " << name << '\n';
    std::cout << "Life Path: " << lifepath << '\n';
    std::cout << "Hair: " << haircolor << " " << hairstyle << '\n';
    std::cout << "Eyes: " << eyecolor << '\n';
    std::cout << "Street Cred: " << streetcred << '\n';
    std::cout << "Eddies: " << eddies << '\n';
    std::cout << "Vehicle: " << vehicle << '\n';
    std::cout << "=====================\n";
}

void player::addromancepoints(int points) {
    romancepoints += points;
}
