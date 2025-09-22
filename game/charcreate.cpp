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
        case 2: return "Blonde";
        case 3: return "Brown";
        case 4: return "Pink";
        case 5: return "Purple";
        case 6: return "Green";
        default: return "Unknown";
    }
}

string hairstyle(int hairstylechoice){
    switch (hairstylechoice){
        case 1: return "Short";
        case 2: return "Long";
        case 3: return "Braids";
        case 4: return "Mohawk";
        case 5: return "Buzzed";
        default: return "Unknown";
    }
}


string eyecolor(int eyecolorchoice){
    switch (eyecolorchoice){
        case 1: return "Brown";
        case 2: return "Cyber Silver";
        case 3: return "Neon Green";
        case 4: return "Black w/ pink hearts";
        default: return "Unknown";
    }
}

string lifepath(int lifepathchoice){
    switch (lifepathchoice){
        case 1: return "Nomad";
        case 2: return "Streetkid";
        case 3: return "Corpo";
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
        default:
            streetcred = 0;
            eddies = 0;
            vehicle = "None";
            break;

    

    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // SUMMARY
    
    cout << ">>>Character Summary<<<" << endl;
    cout << "Hair: " << haircolor(haircolorchoice) << hairstyle(hairstylechoice) << endl;
    cout << "Eyes: " << eyecolor(eyecolorchoice) << endl;
    cout << "Life Path: " << lifepath(lifepathchoice) << endl;












}