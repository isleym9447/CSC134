//beginning with the magic words
 
#include <iostream>
#include "charcreate.h"
#include <thread>
#include <chrono>
using namespace std;





void scene2(){

    int answercall;


    cout << "Walk outside so on and so fourth" << endl;
    cout << endl;

    cout << "[INCOMING CALL]" << endl;
    cout << endl;
    cout << "[1] Accept" << endl;
    cout << "[2] Decline" << endl;
    cout << endl;
    cin >> answercall;

    if (answercall == 1){
        acceptcall()
    }
    else if (answercall == 2){
        declinecall()
    }
    else {
            cout << "\nInvalid. Try again.\n\n";
        }




}



void acceptcall(){

    cout << "Connecting";
    for (int i=0; 1<3; i++) {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(400));
    }

    cout << "Ayeee " << playername << "interested in a gig? Im sure you are "






}






void declinecall(){
    cout << "No job = no eddies" << endl;
}











