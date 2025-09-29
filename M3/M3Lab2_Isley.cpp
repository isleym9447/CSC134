/*
CSC 134
Mattea Isley
9/29/25
 
INPUT: 
PROCESSING: 
OUTPUT: 
return 0 (no error)
SPECIAL FX:


*************************************
letter grader and combat sim


 */


//beginning with the magic words

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;




// functions
void lettergrader() {
    double numgrade;
    string lettergrade;



    const double A_GRADE = 90;
    const double B_GRADE = 80;
    const double C_GRADE = 70;
    const double D_GRADE = 60;
    const double F_GRADE = 50;



    // ask for input
    cout << "Enter a numerical grade: (0-100)" << endl;
    cin >> numgrade;

    if (numgrade > 100) {
        lettergrade = "A++";
    }

    else if (numgrade >= A_GRADE) {
        lettergrade = "A";
    }
        

    else if (numgrade >= B_GRADE){
        lettergrade = "B";
    }
        

    else if (numgrade >= C_GRADE){
        lettergrade = "C";
    }
        

    else if (numgrade >= D_GRADE){
        lettergrade = "D";
    }
        
    
    else if (numgrade >= F_GRADE){
        lettergrade = "F";
    }

    
        




    



    // A: 90 - 100
    // B: 80 - 89
    // C: 70 - 79
    // D: 60 - 69
    // F: 0 - 59
/*
    if (letter grade <= 100 || >= 90)
        lettergrade = "A"

    else if (letter grade <= 89 || >= 80)
        lettergrade = "B"

    else if (letter grade <= 79 || >= 70)
        lettergrade = "C"

    else if (letter grade <= 69 || >= 60)
        lettergrade = "D"
    
    else if (letter grade <= 59 || >= 0)
        lettergrade = "F"

    else {
            cout << "\nInvalid. Try again.\n\n";
        } 

*/


    cout << "A number grade of " << numgrade << " is a(n) " << lettergrade;
    cout << endl;

    if (numgrade > 100) {
        cout << "** Fantastic job! **" << endl;
    }

    else if (numgrade >= A_GRADE) {
        cout << "** Great job! **" << endl;

    }
        

    else if (numgrade >= B_GRADE){
        cout << "** Keep it up! **" << endl;
    }
        

    else if (numgrade >= C_GRADE){
        cout << "** Lock in!! **" << endl;
    }
        

    else if (numgrade >= D_GRADE){
        cout << "** Might want to see your instructor. **" << endl;
    }
        
    
    else if (numgrade >= F_GRADE){
        cout << "** You are failing. See your instructor. **" << endl;
    }



}

    
void combat(){

    // attack roll + stat bonus >= ac? = hit, else miss
                                                        // ...unless youre shadowheart and MISS even with a 99% crit rate...

    int attackroll, attackbonus, enemyac;

    cout << "You are fighting a goblin." << endl;
    cout << endl;
    cout << "Enter your roll: " << endl;

    cin >> attackroll;

    cout << "Enter your attack bonus: " << endl;

    cin >> attackbonus;

    cout << "What is the goblin's AC?: " << endl;
    cout << endl;
    cin >> enemyac;



    // roll to hit

    attackroll = roll();

    cout << "Roll: " << attackroll << " + " << attackbonus << " = " << attackroll + attackbonus << endl;

    if (attackroll + attackbonus >= enemyac) {
        cout << "Hit!" << endl;

    }

    else {
        cout << "Miss!" << endl;

    }

    // try again?
    cout << "Again!? (y/n)";

    string again;
    cin >> again;

    if (again == "y"){
        //call fuction again!
        combat();
    }







    
}


    


int roll() {
    const int SIDES = 20;
    int myroll;
    myroll = (rand() % SIDES) + 1;
    return myroll;
}






int main(){

    //lettergrader();

    combat();

    






//output
    return 0; //no errors
    
    
    
    
    
    
    
    
    
    
    
    
    }
