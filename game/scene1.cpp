
//beginning with the magic words
 
#include <iostream>
#include "charcreate.h"
using namespace std;


void scene1(){

    int scene1choice;

    cout << "You wake up..." << endl;






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





   












