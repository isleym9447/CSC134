//beginning with the magic words
 

#include <iostream>
#include "charcreate.h"
#include <thread>
#include <chrono>
using namespace std;









void acceptcall(){

    cout << "Connecting";
    for (int i=0; 1<3; i++) {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(400));
    }

    cout << "Ayeee " << playername << "interested in a gig? I know you are. Got one for you. Juicy one at that.";
    cout << "client needs their shard back. Valentinos stole it and are keepin' too safe and too sound in a";
    cout << "garage in Santo Domingo. Client wants the shard back and doesnt care about the chooms protectin' it.";
    cout << "However, that dont mean you should let your iron go empty- use some descretion if you can choom- for me.";
    cout << "Gig info attached." << endl;

    cout << "*NEW MESSAGE**" << endl;
    cout << endl;
    cout << "Gig type: Asset recovery" << endl;
    cout << "Client: Christopher Maldonado";
    cout << "Location: Garcia Auto Repair, Santo Domingo" << endl;
    cout << "Get the data shard back from the wherever the Valentinos squirreled it away. Client not concerned with bloodshed amout";
    cout << "Good luck " << playername << "." << endl;






}






void declinecall(){
    cout << "No job = no eddies" << endl;
}




void scene2(){

    int answercall;
    bool accepted_call;


    cout << "Walk outside so on and so fourth" << endl;
    cout << endl;

    cout << "[INCOMING CALL]" << endl;
    cout << endl;
    cout << "[1] Accept" << endl;
    cout << "[2] Decline" << endl;
    cout << endl;
    cin >> answercall;

    if (answercall == 1){
        accepted_call = true;
        acceptcall();
    }
    else if (answercall == 2){
        accepted_call = false;
        declinecall();
    }
    else {
            cout << "\nInvalid. Try again.\n\n";
    }




}






