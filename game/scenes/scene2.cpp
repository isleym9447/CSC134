//beginning with the magic words

#include <iostream>
#include <thread>
#include <chrono>
#include "player.h"
#include "scenes/scene2.h"
using namespace std;

// access the same global player as scene1
extern player currentPlayer;

// ----------------------------------------------------------

void acceptcall() {
    cout << "Connecting";
    for (int i = 0; i < 3; i++) {          // fixed loop
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    cout << "\n\n";

    cout << "Ayeee " << currentPlayer.getname()
         << ", interested in a gig? I know you are.\n"
         << "Got one for you — juicy one at that.\n\n"
         << "Client needs their data shard back. Valentinos stole it and are keepin' it "
         << "too safe and too sound in a garage in Santo Domingo.\n"
         << "Client wants the shard back and doesn’t care about the chooms protectin’ it.\n"
         << "However, that don’t mean you should let your iron go empty — "
         << "use some discretion if you can, choom… for me.\n\n";

    this_thread::sleep_for(chrono::milliseconds(800));

    cout << "*NEW MESSAGE RECEIVED*\n\n";
    cout << "Gig type: Asset Recovery\n";
    cout << "Client: Christopher Maldonado\n";
    cout << "Location: Garcia Auto Repair, Santo Domingo\n\n";
    cout << "Retrieve the stolen data shard from wherever the Valentinos squirreled it away.\n";
    cout << "Client not concerned with collateral damage.\n\n";
    cout << "Good luck, " << currentPlayer.getname() << ".\n";
}

// ----------------------------------------------------------

void declinecall() {
    cout << "\nYou decline the call.\n";
    cout << "No job = no eddies.\n";
}

// ----------------------------------------------------------

void scene2() {
    int answercall;
    bool accepted_call = false;

    cout << "\nYou step out into the hazy glow of Night City’s morning.\n";
    cout << "Your holo implant flickers — an incoming call from your fixer.\n\n";

    cout << "[INCOMING CALL]\n";
    cout << "[1] Accept\n";
    cout << "[2] Decline\n> ";
    cin >> answercall;

    if (answercall == 1) {
        accepted_call = true;
        acceptcall();
    } else if (answercall == 2) {
        accepted_call = false;
        declinecall();
    } else {
        cout << "\nInvalid choice. Try again next time.\n";
    }
}
