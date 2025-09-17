/*
CSC 134
Mattea Isley
9/17/2025
M3T1

INPUT: 
PROCESSING: 
OUTPUT: 
return 0 (no error)
SPECIAL FX:
*/




//beginning with the magic words

#include <iostream>
using namespace std;

int main() {

    // Variables
    double len1, wid1, len2, wid2; 
    double area1, area2;

    // Ask user for the length and width
    cout << "What's the length of the first rectangle? ";
    cin >> len1;
    cout << "What's the width of the first rectangle? ";
    cin >> wid1;
    cout << "What's the length of the second rectangle? ";
    cin >> len2;
    cout << "What's the width of the second rectangle? ";
    cin >> wid2;

    // Find the area

    area1 = len1 * wid1;
    area2 = len2 * wid2;

    // Print the area

    return 0;
}
