// beginning with the magic words
#include <iostream>
#include <string>
#include "player.h"
#include "charcreate.h"
#include "scenes/scene1.h"
using namespace std;

// access your player
extern player currentPlayer;

// ====================================================================
// LOOK IN MIRROR
void mirror() {

    cout << "\n\n";
    cout << "You enter the bathroom and look into the dimly lit mirror. Your "
         << currentPlayer.geteyecolor()
         << " eyes stare back at you." << endl;
    cout << "The light above you flickers, shining on your "
         << currentPlayer.gethaircolor() << " "
         << currentPlayer.gethairstyle()
         << ". Typical Night City electricity." << endl;
    cout << "\n\n";
}

// ====================================================================
// CHECK INVENTORY
void baginventory() {
    cout << "\n\n";
    cout << "Walking to your kitchen counter where you unload your pockets," << endl;
    cout << "beside an old crumpled burrito wrapper is: \n" << endl;
    cout << "\n\n";
    currentPlayer.showinventory();
}

// ====================================================================
// EAT SOMETHING
void eatsomething() {
    static bool appleeaten = false;
    static bool chromanticoreeaten = false;
    static bool burgereaten = false;

    int foodchoice;

    cout << "\n\n";
    cout << "You walk into the kitchen and open your fridge." << endl;

    while (true) {
        if (appleeaten && chromanticoreeaten && burgereaten) {
            cout << "\n\n";
            cout << "The fridge is empty. Time for a grocery run." << endl;
            cout << "\n\n";
            break;
        }

        cout << endl;
        cout << "What's inside:" << endl;
        if (!appleeaten) cout << "1. Apple" << endl;
        if (!chromanticoreeaten) cout << "2. Half-empty ChroManticore" << endl;
        if (!burgereaten) cout << "3. Last night’s hamburger" << endl;
        cout << "4. Close fridge" << endl;
        cout << endl << "What do you reach for?" << endl;
        cin >> foodchoice;

        if (foodchoice == 1) {
            if (!appleeaten) {
                cout << "The apple is sweet. As sweet as a synthetic, genetically modified fruit in 2077 can be." << endl;
                appleeaten = true;
            } else {
                cout << "The apple’s already eaten. Nothing left but the core. You can eat that I guess, if you want..." << endl;
            }
        }
        else if (foodchoice == 2) {
            if (!chromanticoreeaten) {
                cout << "Yep. Flat ChroManticore. It probably was better when it was still carbonated." << endl;
                chromanticoreeaten = true;
            } else {
                cout << "The ChroManticore can is empty." << endl;
            }
        }
        else if (foodchoice == 3) {
            if (!burgereaten) {
                cout << "Cold, wilted lettuce, stiff synthbeef patty. Still hits the spot." << endl;
                burgereaten = true;
            } else {
                cout << "You must be desperate if you’re willing to eat a hamburger wrapper." << endl;
            }
        }
        else if (foodchoice == 4) {
            cout << "You close the fridge door." << endl;
            break;
        }
        else {
            cout << "\nInvalid. Try again.\n\n";
        }
    }
}

// ====================================================================
// CHECK EMAIL
void checkemail() {
    static bool email1read = false;
    static bool email2read = false;
    static bool email3read = false;

    int emailchoice;

    cout << endl;
    cout << "You sit down at your computer and click open your email." << endl;
    cout << endl;

    while (true) {
        int unread = 0;
        if (!email1read) unread++;
        if (!email2read) unread++;
        if (!email3read) unread++;

        cout << endl;
        cout << "┎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐" << endl;
        cout << "│       You have [" << unread << "] new emails          │" << endl;
        cout << "└━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┚" << endl;
        cout << endl;

        if (!email1read) {
            cout << "1" << endl;
            cout << "┎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐" << endl;
            cout << "│**SANDEVISTAN FOR CHEAP** **NO SCAM**   │" << endl;
            cout << "│-DOWNTOWN WATSON RIPPERDOC HAS CHEAP... │" << endl;
            cout << "└━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┚" << endl;
        }
        if (!email2read) {
            cout << "2" << endl;
            cout << "┎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐" << endl;
            cout << "│**NEW MESSAGE FROM FIXER**              │" << endl;
            cout << "│ -Client needs a quiet hand in Japantown│" << endl;
            cout << "└━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┚" << endl;
        }
        if (!email3read) {
            cout << "3" << endl;
            cout << "┎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐" << endl;
            cout << "│**[AD] New Drinks @ Lizzie’s**          │" << endl;
            cout << "│ -Half off braindances this weekend     │" << endl;
            cout << "└━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┚" << endl;
        }

        cout << endl << "Open email? (1–3)" << endl;
        cout << "Press 4 to close email inbox" << endl;
        cin >> emailchoice;

        if (emailchoice == 1 && !email1read) {
            cout << endl;
            cout << "┎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐" << endl;
            cout << "│From: WATSONGIRL7855                    │" << endl;
            cout << "│Subject: **SANDEVISTAN FOR CHEAP**      │" << endl;
            cout << "│---------------------------------------│" << endl;
            cout << "│Hey choom, heard you were lookin’ for a │" << endl;
            cout << "│Sandevistan. I got a guy in Watson, no  │" << endl;
            cout << "│scams, just eddies upfront.             │" << endl;
            cout << "└━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┚" << endl;
            email1read = true;
        }
        else if (emailchoice == 2 && !email2read) {
            cout << endl;
            cout << "┎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐" << endl;
            cout << "│From: [REDACTED]                        │" << endl;
            cout << "│Subject: **Job in Japantown**           │" << endl;
            cout << "│---------------------------------------│" << endl;
            cout << "│Client wants a quiet hand. Discretion   │" << endl;
            cout << "│is key. Meet at the pachinko parlor,    │" << endl;
            cout << "│bring your own iron. Payment on site.   │" << endl;
            cout << "└━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┚" << endl;
            email2read = true;
        }
        else if (emailchoice == 3 && !email3read) {
            cout << endl;
            cout << "┎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐" << endl;
            cout << "│From: LIZZIES_PROMO                     │" << endl;
            cout << "│Subject: **Half Off Braindances**       │" << endl;
            cout << "│---------------------------------------│" << endl;
            cout << "│This weekend only! All braindances half │" << endl;
            cout << "│off with purchase of 2 drinks. Don’t    │" << endl;
            cout << "│miss the party, choom.                  │" << endl;
            cout << "└━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┚" << endl;
            email3read = true;
        }
        else if (emailchoice == 4) {
            cout << "You close your email inbox." << endl;
            break;
        }
        else {
            cout << "\nInvalid or already read. Try again.\n\n";
        }
    }
}

// ====================================================================
// BACK TO BED
void backtobed() {
    cout << endl << endl;
    cout << "You return to bed and shut your eyes again. Slowly, you drift back to sleep..." << endl;
    cout << "Wake the fuck up, Samurai..." << endl;

}

// ====================================================================
// LEAVE APARTMENT
void leaveapartment() {
    cout << endl << endl;
    cout << "You open the door to your apartment. The sounds (and smells) of Night City fill your senses." << endl;
    cout << endl;
    
}

// ====================================================================
// SCENE 1 MENU LOOP
void scene1() {
    int scene1choice;

    cout << "The sound of your alarm wakes you up from your sleep. With a yawn, your eyes fully open to meet a " << endl;
    cout << "yellowing stain on the ceiling above the bed. You remind yourself to clean that later and to always make sure " << endl;
    cout << "to open your NiCola orange in the kitchen and *not* in the bed." << endl;
    cout << endl;
    cout << "Deciding it’s probably best to start your day, you stand up and..." << endl;
    cout << endl;

    while (true) {
        cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<" << endl;
        cout << "1. Look in the mirror\n";
        cout << "2. Check inventory\n";
        cout << "3. Eat something\n";
        cout << "4. Check Email\n";
        cout << "5. Leave apartment\n";
        cout << "6. Go back to bed\n";
        cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<" << endl;
        cout << ">> Enter choice: ";
        cin >> scene1choice;

        switch (scene1choice) {
            case 1: mirror(); break;
            case 2: baginventory(); break;
            case 3: eatsomething(); break;
            case 4: checkemail(); break;
            case 5: leaveapartment(); return;
            case 6: backtobed(); break;
            default: cout << "\nInvalid. Try again.\n"; break;
        }
    }
}
