#include "player.h"

// Default constructor
player::player()
    : name(""),
      lifepath("Unknown"),
      haircolor(""),
      hairstyle(""),
      eyecolor(""),
      vehicle("None"),
      body(100),
      eddies(0),
      streetcred(0),
      inventory()
{
}

// Constructor with name + lifepath
player::player(const std::string& n, const std::string& lp)
    : name(n),
      lifepath(lp),
      haircolor(""),
      hairstyle(""),
      eyecolor(""),
      vehicle("None"),
      body(100),
      eddies(0),
      streetcred(0),
      inventory()
{
}

// --- Getters ---

const std::string& player::getname() const {
    return name;
}

const std::string& player::getlifepath() const {
    return lifepath;
}

const std::string& player::gethaircolor() const {
    return haircolor;
}

const std::string& player::gethairstyle() const {
    return hairstyle;
}

const std::string& player::geteyecolor() const {
    return eyecolor;
}

const std::string& player::getvehicle() const {
    return vehicle;
}

int player::getbody() const {
    return body;
}

int player::geteddies() const {
    return eddies;
}

int player::getstreetcred() const {
    return streetcred;
}

const std::vector<std::string>& player::getinventory() const {
    return inventory;
}

// --- Setters ---

void player::setname(const std::string& n) {
    name = n;
}

void player::setlifepath(const std::string& lp) {
    lifepath = lp;
}

void player::sethaircolor(const std::string& hc) {
    haircolor = hc;
}

void player::sethairstyle(const std::string& hs) {
    hairstyle = hs;
}

void player::seteyecolor(const std::string& ec) {
    eyecolor = ec;
}

void player::setvehicle(const std::string& v) {
    vehicle = v;
}

void player::setbody(int b) {
    body = b;
}

void player::seteddies(int e) {
    eddies = e;
}

void player::setstreetcred(int sc) {
    streetcred = sc;
}

// Inventory ops
void player::additem(const std::string& item) {
    inventory.push_back(item);
}
