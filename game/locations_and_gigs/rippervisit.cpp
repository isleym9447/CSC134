#include <iostream>
#include <string>
#include "charcreate.h"   // eddies, lifepathchoice, etc.
using namespace std;

// GLOBAL FLAG to check if Kiroshi has been installed
bool kiroshi_installed = false;

// ==============================
// Ripperdoc Visit Main Function
// ==============================
void rippervisit() {
    int ripperchoice;
    int actionchoice;

    cout << "\nYour head’s still ringing from the warehouse gig. Wounds patched, but something’s off.\n";
    cout << "Your optics fuzz every few seconds — colors lagging behind motion.\n";
    cout << "Might be time to see a ripperdoc.\n\n";

    cout << "You *could* get a drink, crash at home, or kill time around Watson…\n";
    cout << "But your HUD keeps glitching.\n";
    cout << "Maybe you should visit a ripper.\n\n";

    cout << "Ripperdocs available:\n";
    cout << "1. Viktor Vektor — discount installs, warm and gruff.\n";
    cout << "2. Kaia Gregory — clinical, efficient, full price.\n";
    cout << "3. Leave — for now.\n";
    cout << "\nEnter your choice: ";
    cin >> ripperchoice;
    cout << endl;

    switch (ripperchoice) {

        // ==========================================
        // Viktor Vektor
        // ==========================================
        case 1: {
            cout << "You step into Viktor’s clinic — smells like metal polish and nostalgia.\n";
            cout << "Viktor looks up from his workbench, pushes his glasses up.\n";
            cout << "Viktor: “Hey, kid. You look like shit. Sit down, lemme take a look.”\n\n";

            cout << "1. Check-up\n";
            cout << "2. Install Kiroshi Optics\n";
            cout << "3. Install other cyberware\n";
            cout << "4. Leave\n";
            cout << "\nChoose: ";
            cin >> actionchoice;
            cout << endl;

            if (actionchoice == 1) {
                cout << "Viktor checks your vitals and patches a few scrapes.\n";
                cout << "Viktor: “You’re lucky. Couple more hits and you’d be on a slab.”\n";
                cout << "\n>> HEALTH: Fully restored\n";
            }
            else if (actionchoice == 2) {
                cout << "You settle into the chair. Cold chrome meets skin.\n";
                cout << "Viktor hums along to the radio while his tools spark faintly.\n";
                cout << "\nViktor: “Hold still. I’ll give you the friend discount, alright?”\n";
                cout << "\n>> CYBERWARE: Kiroshi Optics [Model V2] installed\n";
                cout << ">> EDDIES: -300\n";
                kiroshi_installed = true;
            }
            else if (actionchoice == 3) {
                cout << "Viktor scrolls his inventory.\n";
                cout << "Viktor: “Got Gorilla Arms, Dermal plating, maybe a Sandevistan… but let’s focus those optics first.”\n";
            }
            else if (actionchoice == 4) {
                cout << "Viktor waves as you stand.\n";
                cout << "Viktor: “Try not to get shot again before breakfast.”\n";
            }
            else cout << "Viktor: “You high on painkillers or what? Try again.”\n";
            break;
        }

        // ==========================================
        // Kaia Gregory (OC)
        // ==========================================
        case 2: {
            cout << "You enter Kaia’s clinic — chrome, sterile light, scent of disinfectant.\n";
            cout << "Kaia barely glances up from her screen.\n";
            cout << "Kaia: “Name and purpose of visit?”\n\n";

            cout << "1. Check-up\n";
            cout << "2. Install Kiroshi Optics\n";
            cout << "3. Install other cyberware\n";
            cout << "4. Leave\n";
            cout << "\nChoose: ";
            cin >> actionchoice;
            cout << endl;

            if (actionchoice == 1) {
                cout << "Kaia runs a scanner along your arm. The display flickers green.\n";
                cout << "Kaia: “Vitals within normal range. I recommend ocular recalibration soon.”\n";
                cout << "\n>> HEALTH: Fully restored\n";
            }
            else if (actionchoice == 2) {
                cout << "You lie back in the chrome chair. Kaia’s motions are precise, detached.\n";
                cout << "Kaia: “Hold still. This will sting.”\n";
                cout << "\n>> CYBERWARE: Kiroshi Optics [Model V2] installed\n";
                cout << ">> EDDIES: -500\n";
                kiroshi_installed = true;
            }
            else if (actionchoice == 3) {
                cout << "Kaia flips through a digital catalog.\n";
                cout << "Kaia: “Full limb replacements, dermal mesh, neural dampeners. Prices are non-negotiable.”\n";
            }
            else if (actionchoice == 4) {
                cout << "Kaia: “Then I suggest you leave my workspace clear.”\n";
            }
            else cout << "Kaia sighs. “If you can’t decide, come back when you’ve got the cash, choom.”\n";
            break;
        }

        // ==========================================
        // Leave / default
        // ==========================================
        case 3:
            cout << "You decide to wait it out. The flicker in your optics grows worse, but you ignore it.\n";
            break;

        default:
            cout << "You stare at your map, unsure which ripper to trust.\n";
            break;
    }
}