#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class player {

private:
    // core identity
    string name;
    string lifepath;

    // appearance
    string hairstyle;
    string haircolor;
    string eyecolor;

    // stats
    int body;
    int reflex;
    int tech;
    int code;
    int cool;

    // resources
    int eddies;
    int streetcred;
    string vehicle;
    vector<string> inventory;

    // relationships/morality
    int romancepoints;

public:
    // constructor
    player(string playername = "unknown", string life = "drifter");

    // getters
    string getname() const;
    string getlifepath() const;
    string gethaircolor() const;
    string gethairstyle() const;
    string geteyecolor() const;
    string getvehicle() const;

    int getbody() const;
    int getreflex() const;
    int gettech() const;
    int getcode() const;
    int getcool() const;

    int geteddies() const;
    int getstreetcred() const;
    int getromancepoints() const;

    vector<string> getinventory() const;

    // setters
    void setname(const string& newname);
    void setlifepath(const string& newlifepath);
    void sethaircolor(const string& newhaircolor);
    void sethairstyle(const string& newhairstyle);
    void seteyecolor(const string& neweyecolor);
    void setvehicle(const string& newvehicle);
    void seteddies(int amount);
    void setstreetcred(int cred);

    // methods
    void additem(const string& item);
    void showinventory() const;
    void showstats() const;
    void addromancepoints(int points);
};

#endif
