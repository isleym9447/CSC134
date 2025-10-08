//beginning with the magic words

#include <iostream>
#include <string>
#include "player.h"
#include "charcreate.h"
#include "scenes/scene1.h"   // adjust path if needed
using namespace std;

// ===== Forward declarations (optional for readability) =====
// (You already have them in scene1.h, so not strictly needed)

// We'll assume you have a global player object available:
extern player currentPlayer;   // declared elsewhere, like in mainmenu.cpp


// ======================== Scene Functions ========================

void mirror() {
    cout << "You enter the bathroom and look into the dimly lit mirror. "
         << "Your " << currentPlayer.geteyecolor() << " eyes stare back at you." << endl;
    cout << "The light above you flickers, shining on your "
         << currentPlayer.gethaircolor() << " " << currentPlayer.gethairstyle()
         << ". Typical Night City electricity." << endl;
}


void baginventory() {
    cout << endl << endl;
    cout << "Walking to your kitchen counter where you unload your pockets, " << endl;
    cout << "beside an old crumpled burrito wrapper is: \n" << endl;
    currentPlayer.showinventory();
}


void eatsomething() {
    static bool appleeaten = false;
    static bool chromanticoreeaten = false;
    static bool burgereaten = false;
    int foodchoice;

    cout << endl << endl;
    cout << "You walk into the kitchen and open your fridge." << endl;

    while (true) {
        if (appleeaten && chromanticoreeaten && burgereaten) {
            cout << "The fridge is empty. Time for a grocery run." << endl;
            break;
        }

        cout << endl;
        cout << "What's inside:" << endl;
        if (!appleeaten) cout << "1. Apple" << endl;
        if (!chromanticoreeaten) cout << "2. Half-empty ChroManticore" << endl;
        if (!burgereaten) cout << "3. Last night's hamburger" << endl;
        cout << "4. Close fridge" << endl;
        cout << "\nWhat do you reach for? ";
        cin >> foodchoice;

        if (foodchoice == 1 && !appleeaten) {
            cout << "The apple is sweet. As sweet as a synthetic, genetically modified fruit in 2077 can be." << endl;
            appleeaten = true;
        } 
        else if (foodchoice == 2 && !chromanticoreeaten) {
            cout << "Yep. Flat ChroManticore. It probably was better when it was still carbonated." << endl;
            chromanticoreeaten = true;
        } 
        else if (foodchoice == 3 && !burgereaten) {
            cout << "Cold, wilted lettuce, stiff synthbeef patty. Still hits the spot." << endl;
            burgereaten = true;
        } 
        else if (foodchoice == 4) {
            cout << "You close the fridge door." << endl;
            break;
        } 
        else {
            cout << "\nInvalid. Try again.\n";
        }
    }
}


void checkemail() {
    static bool email1read = false;
    static bool email2read = false;
    static bool email3read = false;
    int emailchoice;

    cout << "\nYou sit down at your computer and click open your email.\n";

    while (true) {
        int unread = 0;
        if (!email1read) unread++;
        if (!email2read) unread++;
        if (!email3read) unread++;

        cout << "\n┎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐" << endl;
        cout << "│       You have [" << unread << "] new emails          │" << endl;
        cout << "└━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┚" << endl;

        if (!email1read)
            cout << "1. **SANDEVISTAN FOR CHEAP** **NO SCAM**\n";
        if (!email2read)
            cout << "2. **NEW MESSAGE FROM FIXER**\n";
        if (!email3read)
            cout << "3. **[AD] New Drinks @ Lizzie’s**\n";
        cout << "4. Close email inbox\n> ";
        cin >> emailchoice;

        if (emailchoice == 1 && !email1read) {
            cout << "\n[From: WATSONGIRL7855]\nHey choom, heard you were lookin’ for a Sandevistan..."
                 << " I got a guy in Watson. No scams, just eddies upfront.\n";
            email1read = true;
        } 
        else if (emailchoice == 2 && !email2read) {
            cout << "\n[From: Unknown Fixer]\nClient wants a quiet hand. Discretion is key. Meet at the pachinko parlor. "
                 << "Payment on site.\n";
            email2read = true;
        } 
        else if (emailchoice == 3 && !email3read) {
            cout << "\n[LIZZIES_PROMO]\nHalf Off Braindances this weekend! Bring a friend and a few eddies.\n";
            email3read = true;
        } 
        else if (emailchoice == 4) {
            cout << "You close your email inbox.\n";
            break;
        } 
        else {
            cout << "\nInvalid or already read. Try again.\n";
        }
    }
}


void backtobed() {
    cout << "\nYou return to bed and shut your eyes again. Slowly, you drift back to sleep...\n";
    cout << "Wake the fuck up, Samurai.\n";
}


void leaveapartment() {
    cout << "\nYou open the door to your apartment. The sounds (and smells) of Night City fill your senses.\n";
}


// ======================== Scene Entry ========================

void scene1() {
    int scene1choice;

    cout << "The sound of your alarm wakes you up from your sleep. With a yawn, your eyes meet a yellowing stain "
         << "on the ceiling above the bed.\nYou remind yourself to clean that later and to always open your NiCola "
         << "in the kitchen and *not* in the bed.\n\n";
    cout << "Deciding it's probably best to start your day, you stand up and...\n\n";

    while (true) {
        cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<\n";
        cout << "1. Look in the mirror\n";
        cout << "2. Check inventory\n";
        cout << "3. Eat something\n";
        cout << "4. Check Email\n";
        cout << "5. Leave apartment\n";
        cout << "6. Go back to bed\n";
        cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<\n";
        cout << ">> Enter choice: ";
        cin >> scene1choice;

        switch (scene1choice) {
            case 1: mirror(); break;
            case 2: baginventory(); break;
            case 3: eatsomething(); break;
            case 4: checkemail(); break;
            case 5: leaveapartment(); return;
            case 6: backtobed(); return;
            default: cout << "\nInvalid. Try again.\n"; break;
        }
    }
}
