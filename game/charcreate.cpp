#include <iostream>
#include <string>
#include <vector>
using namespace std;

// GLOBAL VARIABLES F0R GAME

//character
int haircolorchoice;
int hairstylechoice;
int eyecolorchoice;
int lifepathchoice;

// stats and inventory
int streetcred;
int eddies;
vector<string> inventory;
string vehicle;

//influence
bool corpoinfluence = false; //flag for corpo life path

//////////////////////////////////////////////////////////
//helpers
string haircolor(int haircolorchoice){
    switch (haircolorchoice){
        case 1: return "Black";
        case 1: return "Black";
        case 1: return "Black";
        case 1: return "Black";
        case 1: return "Black";
    }
}








///////////////////////////////////////////////////////////////

void charcreate(){
    int choice;

    cout << "CHARACTER CREATOR INITIATED" << endl;

    //hair color
    cout << "Choose your hair color" << endl;
    cout << "1. Black" << endl;
    cout << "2. Blonde" << endl;
    cout << "3. Brown" << endl;
    cout << "4. Pink" << endl;
    cout << "5. Purple" << endl;
    cout << "6. Green" << endl;

    cout << "Enter choice" << endl;
    cin >> haircolorchoice;

    //hair style
    cout << "Choose your hair style" << endl;
    cout << "1. Short" << endl;
    cout << "2. Long" << endl;
    cout << "3. Braids" << endl;
    cout << "4. Mohawk" << endl;
    cout << "5. Buzzed" << endl;

    cout << "Enter choice" << endl;
    cin >> hairstylechoice;

    //eye color
    cout << "Choose your eye color" << endl;
    cout << "1. Brown" << endl;
    cout << "2. Cyber silver" << endl;
    cout << "3. Neon green" << endl;
    cout << "4. Black w/ pink hearts" << endl;

    cout << "Enter choice" << endl;
    cin >> eyecolorchoice;
    
    //life path
    cout << "Choose your life path" << endl;
    cout << "1. Nomad" << endl;
    cout << "2. Streetkid" << endl;
    cout << "3. Corpo" << endl;
    
                                                                 //add descriptions??
    cout << "Enter choice" << endl;
    cin >> lifepathchoice;

    //inventory
    inventory.clear();
    inventory.push_back("Airhypo");
    inventory.push_back("Apartment keycard");
    corpoinfluence = false; //reset

    //lifepath specific inventory and stats
    switch(lifepathchoice){
        case 1: //nomad
            streetcred = 0;
            eddies = 100;
            vehicle = "Quadra Type-66 Avenger";
            break;
        case 2: //streetkid
            streetcred = 10;
            eddies = 1000;
            vehicle = "None";
            inventory.push_back("M-10AF Lexington Pistol");
            break;
        case 3: //corpo
            streetcred = 0;
            eddies = 5000;
            vehicle = "None";
            inventory.push_back("Arasaka Office Keycard");
            corpoinfluence = true;
            break;
    

    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // SUMMARY
    













}