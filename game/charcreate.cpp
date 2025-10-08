#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "charcreate.h"
using namespace std;

// helper functions
string haircolor(int haircolorchoice) {
    switch (haircolorchoice) {
        case 1: return "Black";
        case 2: return "Blonde";
        case 3: return "Brown";
        case 4: return "Pink";
        case 5: return "Purple";
        case 6: return "Green";
        default: return "Unknown";
    }
}

string hairstyle(int hairstylechoice) {
    switch (hairstylechoice) {
        case 1: return "Short";
        case 2: return "Long";
        case 3: return "Braids";
        case 4: return "Mohawk";
        case 5: return "Buzzed";
        default: return "Unknown";
    }
}

string eyecolor(int eyecolorchoice) {
    switch (eyecolorchoice) {
        case 1: return "Brown";
        case 2: return "Cyber Silver";
        case 3: return "Neon Green";
        case 4: return "Black w/ pink hearts";
        default: return "Unknown";
    }
}

string lifepath(int lifepathchoice) {
    switch (lifepathchoice) {
        case 1: return "Nomad";
        case 2: return "Streetkid";
        case 3: return "Corpo";
        default: return "Unknown";
    }
}

// character creator
player charcreate() {
    string playername;
    int haircolorchoice, hairstylechoice, eyecolorchoice, lifepathchoice;
    vector<string> inventory;
    string vehicle;
    bool corpoinfluence = false;
    int streetcred = 0;
    int eddies = 0;

    cout << "\nCHARACTER CREATOR INITIATED\n";
    cout << "What is your alias? ";
    cin >> playername;

    // hair color
    do {
        cout << "\nChoose your hair color\n";
        cout << "1. Black\n2. Blonde\n3. Brown\n4. Pink\n5. Purple\n6. Green\n";
        cout << "Enter choice: ";
        cin >> haircolorchoice;
    } while (haircolorchoice < 1 || haircolorchoice > 6);

    // hairstyle
    do {
        cout << "\nChoose your hair style\n";
        cout << "1. Short\n2. Long\n3. Braids\n4. Mohawk\n5. Buzzed\n";
        cout << "Enter choice: ";
        cin >> hairstylechoice;
    } while (hairstylechoice < 1 || hairstylechoice > 5);

    // eye color
    do {
        cout << "\nChoose your eye color\n";
        cout << "1. Brown\n2. Cyber Silver\n3. Neon Green\n4. Black w/ pink hearts\n";
        cout << "Enter choice: ";
        cin >> eyecolorchoice;
    } while (eyecolorchoice < 1 || eyecolorchoice > 4);

    // life path
    do {
        cout << "\n================ LIFE PATH SELECTION ================\n\n";
        cout << "1. Nomad\n";
        cout << "\tRoaming the Badlands. Looting scrapyards. Raiding fuel depots.\n";
        cout << "\tLife on the road wasn't easy. But growing up in a nomad clan\n";
        cout << "\thas its perks: honesty, integrity, and a love of freedom.\n\n";

        cout << "2. Streetkid\n";
        cout << "\tThey say if you wanna understand the streets, you gotta live 'em.\n";
        cout << "\tGangs. Fixers. Dolls. Small-time pushers—you were raised by them all.\n\n";

        cout << "3. Corpo\n";
        cout << "\tFew leave the corporate world with their lives—fewer still with\n";
        cout << "\ttheir souls intact. You've been there: bent the rules, exploited\n";
        cout << "\tsecrets, and weaponized information.\n\n";

        cout << "======================================================\n";
        cout << "Enter choice: ";
        cin >> lifepathchoice;
    } while (lifepathchoice < 1 || lifepathchoice > 3);

    // lifepath setup
    inventory.clear();
    inventory.push_back("Airhypo");
    inventory.push_back("Apartment keycard");
    corpoinfluence = false;

    switch (lifepathchoice) {
        case 1: // Nomad
            streetcred = 0;
            eddies = 100;
            inventory.push_back("Car Keys");
            vehicle = "Quadra Type-66 Avenger";
            break;
        case 2: // Streetkid
            streetcred = 10;
            eddies = 1000;
            inventory.push_back("M-10AF Lexington Pistol");
            vehicle = "None";
            break;
        case 3: // Corpo
            streetcred = 0;
            eddies = 5000;
            inventory.push_back("Arasaka Office Keycard");
            vehicle = "None";
            corpoinfluence = true;
            break;
    }

    // build player object
    player newPlayer(playername, lifepath(lifepathchoice));
    newPlayer.seteddies(eddies);
    newPlayer.setstreetcred(streetcred);
    newPlayer.sethaircolor(haircolor(haircolorchoice));
    newPlayer.sethairstyle(hairstyle(hairstylechoice));
    newPlayer.seteyecolor(eyecolor(eyecolorchoice));
    newPlayer.setvehicle(vehicle);

    for (const auto& item : inventory)
        newPlayer.additem(item);

    // summary
    cout << "\n>>> CHARACTER SUMMARY <<<\n";
    newPlayer.showstats();
    newPlayer.showinventory();

    return newPlayer;
}
