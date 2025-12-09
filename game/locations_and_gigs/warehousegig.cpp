#include "warehousegig.h"
#include "hackingminigame.h"
#include "player.h"
#include <thread>
#include <chrono>
using namespace std;

// ======================================
// HUD
// ======================================
void displayhud(const player& currentPlayer) {
    cout << "═════════════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << " HP [██████████░░] "
         << currentPlayer.getbody()
         << "  Street Cred: " << currentPlayer.getstreetcred()
         << "  Eddies: €$" << currentPlayer.geteddies()
         << "  Vehicle: " << currentPlayer.getvehicle() << " " << endl;
    cout << "═════════════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << endl;
}

// ======================================
// STEALTH PATH
// ======================================
void stealthpath(player& currentPlayer) {
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
            case 3: {
                cout << "Reaching up to the vent plate, it comes off with a sharp *crack*. Carefully, you set it\n";
                cout << "on the ground against the wall. With a small hop you enter the vent and crawl through,\n";
                cout << "scraping your arm on the metal.\n";

                int hp = currentPlayer.getbody();
                hp -= 5;
                if (hp < 0) hp = 0;
                currentPlayer.setbody(hp);

                cout << ">> Health reduced to " << hp << "%\n\n";
                break;
            }
            default:
                cout << "Invalid input.\n\n";
        }

        if (stealthchoice >= 1 && stealthchoice <= 3) {
            cout << "Inside, you find the glowing shard beneath a workbench.\n";
            currentPlayer.additem("Data shard: [confidential warehouse records]");
            cout << ">> Item added: Data shard [confidential warehouse records]\n\n";
            break;
        }

    } while (stealthchoice != 4);
}

// ======================================
// GUNS BLAZING
// ======================================
void gunsblazing(player& currentPlayer) {
    if (currentPlayer.getlifepath() == "Streetkid") {
        cout << "You grip your pistol and kick the door in.\n";
        cout << "Gunfire explodes through the night — chaos, smoke, blood.\n";
        cout << "You take a few hits but make it through.\n\n";

        int hp = currentPlayer.getbody();
        hp -= 25;
        if (hp < 0) hp = 0;
        currentPlayer.setbody(hp);

        int cred = currentPlayer.getstreetcred();
        cred += 2;
        currentPlayer.setstreetcred(cred);

        cout << ">> Health reduced to " << hp << "%\n";
        cout << ">> Street cred increased to " << cred << "\n\n";

        currentPlayer.additem("Data shard: [confidential warehouse records]");
        cout << ">> Item added: Data shard [confidential warehouse records]\n\n";
    } else {
        cout << "You don’t have a weapon for this. Stealth it is, choom.\n\n";
        stealthpath(currentPlayer);
    }
}

// ======================================
// TRAVEL MENU
// ======================================
void travelmenu(player& currentPlayer) {
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
            case 2: {
                int eddies = currentPlayer.geteddies();
                if (eddies >= 200) {
                    eddies -= 200;
                    currentPlayer.seteddies(eddies);

                    cout << "A Delamain cab stops at the curb in front of you, door swinging open.\n";
                    cout << ">> Eddies -200 (now €$" << eddies << ")\n\n";
                    return;
                } else {
                    cout << "Delamain declines your request — insufficient funds.\n\n";
                    break;
                }
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
// WAREHOUSE GIG
// ======================================
void warehousegig(player& currentPlayer) {
    int approachchoice;

    displayhud(currentPlayer);
    travelmenu(currentPlayer);

    displayhud(currentPlayer);
    cout << endl;
    cout << "Santo Domingo. The air here hums with heat and static — like the whole district’s ready to blow.\n";
    cout << "You reach the coordinates, boots crunching over shattered glass and sun-bleached asphalt.\n";
    cout << "The warehouse squats at the end of a dead service road, its steel siding stained with oil and rust.\n\n";

    cout << "An old sign flickers overhead, half the neon burned out, leaving only a sickly gold 'VA' buzzing in the dark.\n";
    cout << "A chain-link fence runs the perimeter, topped with makeshift coils of barbed wire and prayer tags fluttering in the dry wind.\n\n";

    cout << "Cameras mounted to the corners sweep the yard in lazy arcs — cheap optics, but still deadly if they catch you.\n";
    cout << "Each lens whirs as it pivots, servo motors grinding, searching for something — or someone — that doesn’t belong.\n\n";

    cout << "Two Valentinos hold post near the loading bay — chrome glinting beneath their gold jewelry, jackets unzipped to show inked saints\n";
    cout << "and half-finished devotionals. One leans against a crate, flipping a butterfly knife open and shut. The other smokes, eyes hidden\n";
    cout << "behind mirrored optics. Their laughter cuts through the hum of a nearby power transformer.\n\n";

    cout << "You duck behind a pile of scrap metal as a delivery drone descends, its thrusters kicking up dust and heat. It drops off a crate,\n";
    cout << "then vanishes into the sky, leaving the smell of ozone in its wake.\n\n";

    cout << "The warehouse lights flicker, shadows crawling across the yard. Somewhere inside, a generator coughs to life.\n";
    cout << "It’s loud, bright, and crawling with Valentinos — but the data you’re after is in there.\n\n";

    cout << "No alarms. No witnesses. Get in, grab the shard, and ghost out before anyone notices.\n\n";

    do {
        cout << "1. Go in guns blazing\n";
        cout << "2. Sneak in quietly\n";
        cout << "3. Check inventory\n";
        cout << ">> ";
        cin >> approachchoice;
        cout << endl;

        switch (approachchoice) {
            case 1:
                gunsblazing(currentPlayer);
                break;
            case 2:
                stealthpath(currentPlayer);
                break;
            case 3:
                cout << "Your current inventory:\n";
                currentPlayer.showinventory();
                cout << endl;
                break;
            default:
                cout << "Invalid input.\n";
        }

    } while (approachchoice < 1 || approachchoice > 2);

    cout << "\nYou exfiltrate and ping the fixer.\n";
    cout << "Fixer: “Good work, choom. Shard’s clean. Sending your eddies now.”\n\n";

    int eddies = currentPlayer.geteddies();
    eddies += 500;
    currentPlayer.seteddies(eddies);

    cout << ">> Eddies +500 (total: " << eddies << ")\n";
    cout << ">> Data shard removed from inventory (the client takes it off your hands).\n\n";

    cin.ignore();
    cin.get();
}
