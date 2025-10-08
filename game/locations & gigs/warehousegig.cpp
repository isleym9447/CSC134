#include "warehousegig.h"
#include "hackingminigame.h"   // include the separate mini-game header
#include <thread>
#include <chrono>

// ======================================
// hud
// ======================================
void displayhud() {
    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║ HP [██████████░░] " << health << "%"
         << "║ Street Cred: " << streetcred
         << " | Eddies: €$" << eddies
         << " | Weapon: " << weapon << " ║" << endl;
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
                cout << "The security cameras above disengage with a soft hum and become nonoperational. Youre in the clear.\n";
                cout  
                break;
            case 2:
                cout << "You toss a nearby can; Guards investigate the source of the sound giving your chance to sneak by. Go go go.\n\n";
                break;
            case 3:
                cout << "Reacching up to the vent plate, it come off off with a sharp *crack*. Carefully, you set it\n"; 
                cout << "on the ground against the wall. With a small hop you enter the vent and crawl through\n"; 
                cout << "scraping your arm on the metal.\n";
                health -= 5;
                cout << ">> Health  reduced to " << health << "%\n\n";
                break;
            default:
                cout << "invalid input.\n\n";
        }

        if (stealthchoice >= 1 && stealthchoice <= 3) {
            cout << "Inside, you find the glowing shard beneath a workbench.\n";
            inventory.push_back("data shard: [confidential warehouse records]");
            cout << ">> item added: data shard [confidential warehouse records]\n\n";
            break;
        }

    } while (stealthchoice != 4);
}

// ======================================
// gunsblazing
// ======================================
void gunsblazing() {
    if (lifepath == "streetkid") {
        cout << "you grip your " << weapon << " and kick the door in.\n";
        cout << "gunfire explodes through the night — chaos, smoke, blood.\n";
        cout << "you take a few hits but make it through.\n\n";
        health -= 25;
        streetcred += 2;
        cout << ">> health reduced to " << health << "%\n";
        cout << ">> street cred increased to " << streetcred << "\n\n";
        inventory.push_back("data shard: [confidential warehouse records]");
        cout << ">> item added: data shard [confidential warehouse records]\n\n";
    } else {
        cout << "you don’t have a weapon for this. stealth it is, choom.\n\n";
        stealthpath();
    }
}

// ======================================
// travelmenu
// ======================================
void travelmenu() {
    int travelchoice;

    do {
        cout << "choose your travel method:\n";
        cout << "1. metro (free)\n";
        cout << "2. call a delamain cab (€$200)\n";
        cout << "3. walk (cheap but risky)\n";
        cout << "4. drive yourself (nomad only)\n";
        cout << "0. abort mission\n";
        cout << ">> ";
        cin >> travelchoice;
        cout << endl;

        switch (travelchoice) {
            case 1:
                cout << "you swipe into the metro. the train hums through flickering tunnels.\n\n";
                return;
            case 2:
                if (eddies >= 200) {
                    eddies -= 200;
                    cout << "a delamain av swoops down, doors hissing open.\n";
                    cout << ">> eddies -200 (now €$" << eddies << ")\n\n";
                    return;
                } else {
                    cout << "delamain declines your request — insufficient funds.\n\n";
                    break;
                }
            case 3:
                cout << "you walk the cracked streets toward santo domingo.\n";
                cout << "the neon fades to rust, the air thick with smog.\n\n";
                return;
            case 4:
                if (lifepath == "nomad") {
                    cout << "you hop into your ride, engine growling under neon light.\n";
                    cout << "the freeway hums as you roll toward the warehouse.\n\n";
                    return;
                } else {
                    cout << "you don’t own a car, choom.\n\n";
                    break;
                }
            case 0:
                cout << "mission aborted. the fixer won’t be happy.\n";
                exit(0);
            default:
                cout << "invalid input.\n\n";
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
        cout << "0. Abort mission\n";
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
                cout << "your current inventory:\n";
                for (size_t i = 0; i < inventory.size(); ++i) {
                    cout << "- " << inventory[i] << endl;
                }
                cout << endl;
                break;
            case 0:
                cout << "mission aborted.\n";
                return;
            default:
                cout << "invalid input.\n";
        }

    } while (approachchoice < 1 || approachchoice > 2);

    cout << "\nYou exfiltrate and ping the fixer.\n";
    cout << "Fixer: “Good work, choom. Shard’s clean. Sending your eddies now.”\n\n";
    eddies += 500;
    cout << ">> Eddies +500 (total: " << eddies << ")\n";
    cout << ">>Data shard removed from inventory\n\n";
    

    cin.ignore();
    cin.get();
}
