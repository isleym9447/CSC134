/*
CSC 134
Mattea Isley
 / /
 */
 
 //beginning with the magic words
 
 #include <iostream>
 #include "charcreate.h"
 using namespace std;


void newgame(){
    cout << ">>NEW GAME START<<" << endl;

    //character creation 
    charcreate();
    
}

void settings(){



}

void credits(){
   
   cout << "\n\n===== CREDITS =====\n\n";
   cout << "This project is a fan-made game inspired by the world of *Cyberpunk 2077* © CD PROJEKT RED" << endl;
   cout << "." << endl;
   cout << "All official characters, settings, and world-building elements are the property of CD PROJEKT RED." << endl;
   cout << "." << endl;
   cout << "Original characters, dialogue, story paths, and gameplay elements are created by me" << endl;
   cout << "." << endl;
   cout << "No copyright infringement intended — this is a non-commercial, educational project created with love for the source material." << endl;
   cout << "." << endl;
   cout << "Codebase: 100% written from scratch by a solo dev with synth-coffee and grit" << endl;
   cout << "." << endl;
   cout << "No corpos were harmed in the making of this game." << endl;
   cout << "." << endl;
   cout << "============================================================================================================================\n\n" << endl;

}

void quitgame(){
   cout << endl;
   cout << "<<>><<>><<>><<>><<>><<>><<" << endl;
   cout << "Thanks for playing chooms!" << endl;
   cout << "<<>><<>><<>><<>><<>><<>><<" << endl;
   cout << endl;

}



 
 void mainmenu(){
    int mmchoice;

    while (true) {

      
        cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<" << endl;
       
        cout << "\t1. New Game\n";
        cout << "\t\t2. Settings\n";
        cout << "\t\t\t3. Credits\n";
        cout << "\t\t\t\t4. Quit\n";
      
        cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<" << endl;

        cout << ">> Enter choice: ";
        cin >> mmchoice;

        if (mmchoice == 1) {
            newgame();
        }
        else if (mmchoice == 2) {
            settings();
        }
        else if (mmchoice == 3) {
            credits();
        }
        else if (mmchoice == 4) {
            quitgame();
            break; 
        }
        else {
            cout << "\nInvalid. Try again.\n\n";
        }
    }
}

int main() {
    mainmenu();
    return 0;
}
