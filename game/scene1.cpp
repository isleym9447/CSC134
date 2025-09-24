
//beginning with the magic words
 
#include <iostream>
#include "charcreate.h"
using namespace std;



void mirror(){
    cout << "You enter the bathroom and look into the dimly lit mirror. Your " << eyecolorchoice << " eyes stare back at you." << endl; 
    cout << "The light above you flickers, shining on your " << haircolorchoice << hairstylechoice << " typical Night City electricity." << endl;
}

void baginventory(){
    cout << "You open your bag" << endl;
}

void eatsomething(){
    cout << "You walk into the kitchen" << endl;
}

void checkemail(){
    cout << "You sit down at your computer" << endl;
}

void backtobed(){
    cout << "You shut your eyes again and drift back to sleep" << endl;
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////


void scene1(){

    int scene1choice;

    cout << "The sounds of bustling Night City wake you up from your sleep. With a yawn, your eyes fully open to meet a" << endl;
    cout << " yellowing stain on the celing above the bed. You remind yourself to clean that later and to always make sure" << endl;
    cout << " to open your NiCola orange in the kitchen and *not* in the bed.";
    cout << endl;
    cout << "Deciding its probably best to start your day you sit up and..." << endl;






    while (true) {

      
        cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<" << endl;
       
        cout << "1. Look in the mirror\n";
        cout << "2. Check inventory\n";
        cout << "3. Eat something\n";
        cout << "4. Check Email\n";
        cout << "5. Go back to bed\n";
      
        cout << "<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<" << endl;

        cout << ">> Enter choice: ";
        cin >> scene1choice;

        if (scene1choice == 1) {
            mirror();
        }
        else if (scene1choice == 2) {
            baginventory();
        }
        else if (scene1choice == 3) {
            eatsomething();
        }
        else if (scene1choice == 4) {
            checkemail();
            break; 
        }
        else if (scene1choice == 5) {
            backtobed();
            break; 
        }
        else {
            cout << "\nInvalid. Try again.\n\n";
        }
    }



}





   












