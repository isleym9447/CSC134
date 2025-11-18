//CSC 134
//Mattea Isley


 
//INPUT: 
//PROCESSING: 
//OUTPUT: 
//return 0 (no error)
//SPECIAL FX:





//beginning with the magic words
#include <iostream>
using namespace std;

int main(){

    int speed, hours;

    //ask for inpiut

    cout << "Enter the speed of the vehicle (in mph): " << endl;
    cin >> speed;
    
    //validate
    if (speed < 0) {
        cout << "Error: Speed cannot be negative." << endl;
    }   

    cout << "Enter the number of hours traveled: " << endl;
    cin >> hours;

    //validtae
    if (hours < 1) {
        cout << "Error: Hours traveled must be at least 1." << endl;
    }

    //output 
    cout << "Hour\tDistance Traveled" << endl;
    cout << "------------------------" << endl;

    for (int i = 1; i <= hours; ++i) {
        int distance = speed * i;
        cout << i << "\t" << distance << " miles" << endl;
    }

}