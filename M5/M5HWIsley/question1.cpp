//CSC 134
//Mattea Isley


 
//INPUT: 
//PROCESSING: 
//OUTPUT: 
//return 0 (no error)
//SPECIAL FX:





//beginning with the magic words


#include <iostream>
#include <iomanip>  
#include <string>   
using namespace std;

int main() {

    string month1, month2, month3;
    double rain1, rain2, rain3;
    double average;

    cout << "*******************" << endl;
    cout << "Rainfall Calculator" << endl;
    cout << "*******************" << endl;    
    cout << "Enter month 1: ";
    cin >> month1;
    cout << "Enter rainfall (in inches) for " << month1 << ": ";
    cin >> rain1;
    cout << "*******************" << endl;
    cout << "Enter month 2: ";
    cin >> month2;
    cout << "Enter rainfall (in inches) for " << month2 << ": ";
    cin >> rain2;
    cout << "*******************" << endl;
    cout << "Enter month 3: ";
    cin >> month3;
    cout << "Enter rainfall (in inches) for " << month3 << ": ";
    cin >> rain3;
    cout << "*******************" << endl;  

    //calculate 
    average = (rain1 + rain2 + rain3) / 3;
    cout << fixed << setprecision(2);
    cout << "The average monthly rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " << average << " inches." << endl;
    




}
