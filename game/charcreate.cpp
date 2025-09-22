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

    cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>" << endl;
    cout << "CHARACTER CREATOR INITIATED" << endl;

    
    //hair color
    do {
        cout << "<<>><<>><<>><<>><<>><<>>\n" << endl;
        cout << "Choose your hair color" << endl;
        cout << "1. Black" << endl;
        cout << "2. Blonde" << endl;
        cout << "3. Brown" << endl;
        cout << "4. Pink" << endl;
        cout << "5. Purple" << endl;
        cout << "6. Green" << endl;

        cout << "Enter choice" << endl;
        cin >> haircolorchoice;

        if (haircolorchoice < 1 || haircolorchoice > 6) {
            cout << endl;
            cout << "!!!!!!!!!!!!!!" << endl;
            cout << ">ERROR<" << endl;
            cout << "INVALID ENTRY. TRY AGAIN." << endl;
            cout << endl;
        }
    } while (haircolorchoice < 1 || haircolorchoice > 6);



    //hair style
    do {
        cout << "<<>><<>><<>><<>><<>><<>>\n" << endl;
        cout << "Choose your hair style" << endl;
        cout << "1. Short" << endl;
        cout << "2. Long" << endl;
        cout << "3. Braids" << endl;
        cout << "4. Mohawk" << endl;
        cout << "5. Buzzed" << endl;

        cout << "Enter choice" << endl;
        cin >> hairstylechoice;

         if (eyecolorchoice < 1 || eyecolorchoice > 4) {
            cout << endl;
            cout << "!!!!!!!!!!!!!!" << endl;
            cout << ">ERROR<" << endl;
            cout << "INVALID ENTRY. TRY AGAIN." << endl;
            cout << endl;
        }

    } while (hairstylechoice < 1 || hairstylechoice > 5);



    //eye color
    do {
        cout << "<<>><<>><<>><<>><<>><<>>\n" << endl;
        cout << "Choose your eye color" << endl;
        cout << "1. Brown" << endl;
        cout << "2. Cyber silver" << endl;
        cout << "3. Neon green" << endl;
        cout << "4. Black w/ pink hearts" << endl;

        cout << "Enter choice" << endl;
        cin >> eyecolorchoice;

        if (eyecolorchoice < 1 || eyecolorchoice > 4) {
            cout << endl;
            cout << "!!!!!!!!!!!!!!" << endl;
            cout << ">ERROR<" << endl;
            cout << "INVALID ENTRY. TRY AGAIN." << endl;
            cout << endl;
        }

    } while (eyecolorchoice < 1 || eyecolorchoice > 4);



    
    //life path

    do {
        cout << "<<>><<>><<>><<>><<>><<>>\n" << endl;
        cout << "Choose your life path\n\n" << endl;

        cout << "1. Nomad =============\n";
        cout << "\tRoaming the Badlands. Looting scrapyards. Raiding fuel depots.\n";
        cout << "\tLife on the road wasn't easy. But growing up in a nomad clan\n";
        cout << "\thas its perks: honesty, integrity, and a love of freedom—\n";
        cout << "\tqualities that few in Night City possess, and no amount of\n";
        cout << "\tmoney can buy.\n\n";

        cout << "2. Streetkid =============\n";
        cout << "\tThey say if you wanna understand the streets, you gotta live 'em.\n";
        cout << "\tGangs. Fixers. Dolls. Small-time pushers—you were raised by them all.\n";
        cout << "\tDown here, the law of the jungle dictates the weak serve the strong—\n";
        cout << "\tthe only law in Night City you have yet to break.\n\n";

        cout << "3. Corpo =============\n";
        cout << "\tFew leave the corporate world with their lives—fewer still with\n";
        cout << "\ttheir souls intact. You've been there: bent the rules, exploited\n";
        cout << "\tsecrets, and weaponized information. There's no such thing as a\n";
        cout << "\tfair game, only winners and losers.\n\n";

        cout << "Enter choice" << endl;
        cin >> lifepathchoice;

        //inventory
        inventory.clear();
        inventory.push_back("Airhypo");
        inventory.push_back("Apartment keycard");
        corpoinfluence = false; //reset

         if (lifepathchoice < 1 || lifepathchoice > 3) {
            cout << endl;
            cout << "!!!!!!!!!!!!!!" << endl;
            cout << ">ERROR<" << endl;
            cout << "INVALID ENTRY. TRY AGAIN." << endl;
            cout << endl;
        }

    } while (lifepathchoice < 1 || lifepathchoice > 3);
    

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
    cout << endl;
    cout << "<<>><<>><<>><<>><<>><<>>\n" << endl;
    cout << ">>>Character Summary<<<" << endl;
    cout << "Hair: " << haircolor(haircolorchoice) << " " << hairstyle(hairstylechoice) << endl;
    cout << "Eyes: " << eyecolor(eyecolorchoice) << endl;
    cout << "Life Path: " << lifepath(lifepathchoice) << endl;
    cout << "<<>><<>><<>><<>><<>><<>>\n" << endl;












}