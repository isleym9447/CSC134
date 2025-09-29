/*
CSC 134
Mattea Isley
9/29/25
 
INPUT: 
PROCESSING: 
OUTPUT: 
return 0 (no error)
SPECIAL FX:


 */


//beginning with the magic words

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;




// functions
void lettergrader();

    double numgrade;
    string lettergrade;



    const double A_GRADE = 90;
    const double B_GRADE = 80;
    const double C_GRADE = 70;
    const double D_GRADE = 60;
    const double F_GRADE = 50;

    if (letter grade >= A_GRADE)
        lettergrade = "A"

    else if (letter grade >= B_GRADE)
        lettergrade = "B"

    else if (letter grade >= C_GRADE)
        lettergrade = "C"

    else if (letter grade >= D_GRADE)
        lettergrade = "D"
    
    else if (letter grade >= F_GRADE)
        lettergrade = "F"

    else {
            cout << "\nInvalid. Try again.\n\n";
        } 



    cout << "Enter a numerical grade: (0-100)" << endl;
    cin >> numgrade;



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


    cout << "A number grade of " << numgrade << "is a(n)" << lettergrade;
    cout << endl << endl;

void combat();





int main(){

    lettergrader();

    //combat();






//output
    return 0; //no errors
    
    
    
    
    
    
    
    
    
    
    
    
    }
