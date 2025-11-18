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

    const double PI = 3.14159;
    int choice;

    //menu
    cout << "Geometry Calculator" << endl;
    cout << "1. Calculate the Area of a Circle" << endl;
    cout << "2. Calculate the Area of a Rectangle" << endl;
    cout << "3. Calculate the Area of a Triangle" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): " << endl;
    cin >> choice;

    //validate 
    if (choice < 1 || choice > 4) {
        cout << "Error: Choice must be between 1 and 4." << endl;
    }

    //calculations
    double radius, length, width, base, height, area;

    //menu choices
    switch (choice) {
        case 1:
            cout << "Enter the radius of the circle: " << endl;
            cin >> radius;

            if (radius < 0) {
                cout << "Error: Radius cannot be negative." << endl;
            } else {
                area = PI * radius * radius;
                cout << "The area of the circle is: " << area << endl;
            }
            break;
        case 2:
            cout << "Enter the length of the rectangle: " << endl;
            cin >> length;
            cout << "Enter the width of the rectangle: " << endl;
            cin >> width;   
            if (length < 0 || width < 0) {
                cout << "Error: Length and width cannot be negative." << endl;
            } else {
                area = length * width;
                cout << "The area of the rectangle is: " << area << endl;
            }
            break;
        case 3:
            cout << "Enter the base of the triangle: " << endl;
            cin >> base;
            cout << "Enter the height of the triangle: " << endl;
            cin >> height;  

            if (base < 0 || height < 0) {
                cout << "Error: Base and height cannot be negative." << endl;
            } else {
                area = 0.5 * base * height;
                cout << "The area of the triangle is: " << area << endl;
            }
            break;
        case 4:
            cout << "Quitting the program." << endl;
            break;
    }


}