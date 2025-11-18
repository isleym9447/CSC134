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

int main() {

    double width, length, height;

    cout << "Enter the width of the block: " << endl;
    cin >> width;

    cout << "Enter the length of the block: " << endl;
    cin >> length;

    cout << "Enter the height of the block: " << endl;
    cin >> height;

    //validate input
    if (width <= 0 || length <= 0 || height <= 0) {
        cout << "Error: All dimensions must be greater than zero." << endl;

    }

    //calculate
    double volume = width * length * height;

    //display
    cout << "The volume of the block is: " << volume << endl;



}
