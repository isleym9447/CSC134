/*
CSC 134
Mattea Isley
 9/28/25
*/


//imported from canvas



#include <iostream>
// for random
#include <cmath>    
#include <ctime>
using namespace std;

int main() {
    const int SIDES = 6;
    //int seed = 19;
    int seed = time(0);
    // seed the random number generator
    srand(seed);
    
    int die1 = (rand() % SIDES) +  1;
    int die2 = (rand() % SIDES) +  1;
    int sum = die1 + die2;

    cout << "You rolled " << die1 << " + " << die2 << " = " << sum << endl;
    
    if (sum == 7 || sum == 11) {
        cout << "WINNER!!" << endl;
    
    } 
    else if (sum == 2 || sum == 3 || sum == 12) {
        cout << "LOSER!!" << endl;

    }

}
