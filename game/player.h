#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class player {

private:
    // core identity
    std::string name;
    std::string lifepath;

    // appearance
    std::string hairstyle;
    std::string haircolor;
    std::string eyecolor;

    // stats
    int body;
    int reflex;
    int tech;
    int code;
    int cool;

    // resources
    int eddies;
    int streetcred;
    std::string vehicle;
    std::vector<std::string> inventory;

    // relationships/morality
    int romancepoints;

public:
    // constructor
    player(const std::string& playername = "unknown",
           const std::string& life = "drifter");

    // getters
    std::string getname() const;
    std::string getlifepath() const;
    std::string gethaircolor() const;
    std::string gethairstyle() const;
    std::string geteyecolor() const;
    std::string getvehicle() const;

    int getbody() const;
    int getreflex() const;
    int gettech() const;
    int getcode() const;
    int getcool() const;

    int geteddies() const;
    int getstreetcred() const;
    int getromancepoints() const;

    std::vector<std::string> getinventory() const;

    // setters
    void setname(const std::string& newname);
    void setlifepath(const std::string& newlifepath);
    void sethaircolor(const std::string& newhaircolor);
    void sethairstyle(const std::string& newhairstyle);
    void seteyecolor(const std::string& neweyecolor);
    void setvehicle(const std::string& newvehicle);
    void seteddies(int amount);
    void setstreetcred(int cred);

    // stat setters
    void setbody(int value);
    void setreflex(int value);
    void settech(int value);
    void setcode(int value);
    void setcool(int value);

    // methods
    void additem(const std::string& item);
    void showinventory() const;
    void showstats() const;
    void addromancepoints(int points);
};

#endif // PLAYER_H
