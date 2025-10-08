#include "warehousegig.h"
#include "hackingminigame.h"
#include "player.h"
#include "charcreate.h"
#include <thread>
#include <chrono>
using namespace std;

extern player currentPlayer;


// ======================================
// hud
// ======================================
void displayhud() {
    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║ HP [██████████░░] "
         << currentPlayer.getbody()
         << " | Street Cred: " << currentPlayer.getstreetcred()
         << " | Eddies: €$" << currentPlayer.geteddies()
         << " | Weapon: " << currentPlayer.getvehicle() << " ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
}

// ======================================
// stealthpath
// ======================================
void stealthpath() {
    int stealthchoice;

    cout << "You melt into the shadows around the warehouse perimeter.\n\n";

    do {
        cout << "Stealth options:\n";
        cout << "1. Hack the security cameras\n";
        cout << "2. Distract the guards\n";
        cout << "3. Crawl through the vents\n";
        cout << ">> ";
        cin >> stealthchoice;
        cout << endl;

        switch (stealthchoice) {
            case 1:
                hackingminigame();  // call the separate mini-game function
                cout << "The security cameras above disengage with a soft hum and become nonoperational. You’re in the clear.\n";
                break;
            case 2:
                cout << "You toss a nearby can; guards investigate the sound, giving you a chance to slip by.\n\n";
                break;
            case 3:
                cout << "Reaching up to the vent plate, it comes off with a sharp *crack*. Carefully, you set it\n"; 
                cout << "on the ground against the wall. With a small hop you enter the vent and crawl through,\n"; 
                cout << "scraping your arm on the metal.\n";
                health -= 5;
                cout << ">> Health reduced to " << health << "%\n\n";
                break;
            default:
                cout << "Invalid input.\n\n";
        }

        if (stealthchoice >= 1 && stealthchoice <= 3) {
            cout << "Inside, you find the glowing shard beneath a workbench.\n";
            inventory.push_back("Data shard: [confidential warehouse records]");
            cout << ">> Item added: Data shard [confidential warehouse records]\n\n";
            break;
        }

    } while (stealthchoice != 4);
}

// ======================================
// gunsblazing
// ======================================
void gunsblazing() {
    if (currentPlayer.getlifepath() == "Streetkid") {
        cout << "You grip your " << weapon << " and kick the door in.\n";
        cout << "Gunfire explodes through the night — chaos, smoke, blood.\n";
        cout << "You take a few hits but make it through.\n\n";
        health -= 25;
        streetcred += 2;
        cout << ">> Health reduced to " << health << "%\n";
        cout << ">> Street cred increased to " << streetcred << "\n\n";
        inventory.push_back("Data shard: [confidential warehouse records]");
        cout << ">> Item added: Data shard [confidential warehouse records]\n\n";
    } else {
        cout << "You don’t have a weapon for this. Stealth it is, choom.\n\n";
        stealthpath();
    }
}

// ======================================
// travelmenu
// ======================================
void travelmenu() {
    int travelchoice;

    do {
        cout << "Choose your travel method:\n";
        cout << "1. Metro\n";
        cout << "2. Call a Delamain cab\n";
        cout << "3. Walk\n";
        cout << "4. Drive yourself\n";
        cout << "0. Abort mission\n";
        cout << ">> ";
        cin >> travelchoice;
        cout << endl;

        switch (travelchoice) {
            case 1:
                cout << "You swipe into the metro. The train hums through flickering tunnels.\n\n";
                return;
            case 2:
                if (eddies >= 200) {
                    eddies -= 200;
                    cout << "A Delamain cab stops at the curb in front of you, door swinging open.\n";
                    cout << ">> Eddies -200 (now €$" << eddies << ")\n\n";
                    return;
                } else {
                    cout << "Delamain declines your request — insufficient funds.\n\n";
                    break;
                }
            case 3:
                cout << "You walk the cracked streets toward Santo Domingo.\n";
                cout << "The neon fades to rust, the air thick with smog.\n\n";
                return;
            case 4:
                if (currentPlayer.getlifepath() == "Nomad") {
                    cout << "You hop into your ride, engine growling under neon light.\n";
                    cout << "The freeway hums as you roll toward the warehouse.\n\n";
                    return;
                } else {
                    cout << "You don’t own a car, choom.\n\n";
                    break;
                }
            case 0:
                cout << "Mission aborted. The fixer won’t be happy.\n";
                exit(0);
            default:
                cout << "Invalid input.\n\n";
        }
    } while (true);
}

// ======================================
// warehousegig
// ======================================
void warehousegig() {
    int approachchoice;

    displayhud();
    travelmenu();

    displayhud();
    cout << "Neon light bleeds across cracked pavement as you arrive at the warehouse.\n";
    cout << "Security cameras sweep the lot, guards pacing behind fences.\n";
    
    do {
        cout << "1. Go in guns blazing\n";
        cout << "2. Sneak in quietly\n";
        cout << "3. Check inventory\n";
        cout << ">> ";
        cin >> approachchoice;
        cout << endl;

        switch (approachchoice) {
            case 1:
                gunsblazing();
                break;
            case 2:
                stealthpath();
                break;
            case 3:
                cout << "Your current inventory:\n";
                for (size_t i = 0; i < inventory.size(); ++i) {
                    cout << "- " << inventory[i] << endl;
                }
                cout << endl;
                break;
            default:
                cout << "Invalid input.\n";
        }

    } while (approachchoice < 1 || approachchoice > 2);

    cout << "\nYou exfiltrate and ping the fixer.\n";
    cout << "Fixer: “Good work, choom. Shard’s clean. Sending your eddies now.”\n\n";
    eddies += 500;
    cout << ">> Eddies +500 (total: " << eddies << ")\n";
    cout << ">> Data shard removed from inventory\n\n";

    cin.ignore();
    cin.get();
}
