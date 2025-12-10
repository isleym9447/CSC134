#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class player {
public:
    player();
    player(const std::string& name, const std::string& lifepath);

    // --- Getters ---
    const std::string& getname() const;
    const std::string& getlifepath() const;
    const std::string& gethaircolor() const;
    const std::string& gethairstyle() const;
    const std::string& geteyecolor() const;
    const std::string& getvehicle() const;
    int getbody() const;
    int geteddies() const;
    int getstreetcred() const;
    const std::vector<std::string>& getinventory() const;

    // --- Setters ---
    void setname(const std::string& n);
    void setlifepath(const std::string& lp);
    void sethaircolor(const std::string& hc);
    void sethairstyle(const std::string& hs);
    void seteyecolor(const std::string& ec);
    void setvehicle(const std::string& v);
    void setbody(int b);
    void seteddies(int e);
    void setstreetcred(int sc);

    // Inventory operations
    void additem(const std::string& item);

private:
    std::string name;
    std::string lifepath;
    std::string haircolor;
    std::string hairstyle;
    std::string eyecolor;
    std::string vehicle;

    int body;
    int eddies;
    int streetcred;

    std::vector<std::string> inventory;
};

#endif // PLAYER_H
