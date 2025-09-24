
//beginning with the magic words
 
#include <iostream>
#include "charcreate.h"
using namespace std;



void mirror(){
    cout << "You enter the bathroom and look into the dimly lit mirror. Your " << eyecolor(eyecolorchoice) << " eyes stare back at you." << endl; 
    cout << "The light above you flickers, shining on your " << haircolor(haircolorchoice) << hairstyle(hairstylechoice) << " typical Night City electricity." << endl;
}

void baginventory(){
    cout << endl;
    cout << endl;
    cout << "Walking to your kitchen counter where you unload your pockets, crumbled " << endl;
    cout << "beside an old burrito wrapper is: \n" << endl;
    // list inventory (will change based on lifepath selection)
    for (const auto& str : inventory) {
        cout << str << endl;
    }
}

void eatsomething(){

    int foodchoice;



    cout << endl;
    cout << endl;
    cout << "You walk into the kitchen and open your fridge. Apple, half empty Chromanticore, " << endl;
    cout << "and hamburger from last night." << endl;
    cout << endl;
    cout << "What do you reach for?" << endl;
    cout << endl;
    cout << "1. Apple" << endl;
    cout << "2. Half empty ChroManticore" << endl;
    cout << "3. Last night's hamburger" << endl;
    cin >> foodchoice;

        if (foodchoice == 1) {
            cout << "The apple is sweet. As sweet as a synthetic, genetically modified fruit can be." << endl;
        }
        else if (foodchoice == 2) {
            cout << "You drink the flat ChroManticore. It probably was better when it was carbonated." << endl;
        }
        else if (foodchoice == 3) {
            cout << "Cold, wilted lettuce, stiff synthbeef patty. Still slaps." << endl;
        }
        else {
            cout << "\nInvalid. Try again.\n\n";
        }


}

void checkemail(){
    cout << endl;
    cout << endl;
    cout << "You sit down at your computer" << endl;
}

void backtobed(){
    cout << endl;
    cout << endl;
    cout << "You shut your eyes again and drift back to sleep" << endl;
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////


void scene1(){

    int scene1choice;

    cout << "The sounds of bustling Night City wake you up from your sleep. With a yawn, your eyes fully open to meet a " << endl;
    cout << "yellowing stain on the celing above the bed. You remind yourself to clean that later and to always make sure " << endl;
    cout << "to open your NiCola orange in the kitchen and *not* in the bed.";
    cout << endl;
    cout << "Deciding its probably best to start your day you stand up and..." << endl;
    cout << endl;






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





   












