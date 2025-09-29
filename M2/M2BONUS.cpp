/*
CSC 134
Mattea Isley
 9/15/2025


INPUT: 
PROCESSING: 
OUTPUT: 
return 0 (no error)
SPECIAL FX:
*/




//beginning with the magic words

#include <iostream>
using namespace std;
#include <cmath>




int main()
{

    cout << "Option 1" << endl;

    //1. Given a rectangle with height 8 and width 10, 
    // calculate and print the area. (This one is most similar to 
    // "Apple Orchard", except these are both of type int. 
    // The formula "Area equals length times width" will be useful.)

    int height = 8;
    int width = 10;
    int area = height * width;

    cout << "The area of a rectangle with " << height << " and " << width << " is " << area << endl;





    cout << "Option 2" << endl;

    //2. Assume a product is sold for $99.99, and sales tax is 8%. 
    // Display the product price, the amount of sales tax, and then the final cost including 
    // sales tax. (For handling monetary values, and percentages, you will want to use the double type. 
    // "Percent" is "per cent", meaning a 8% sales tax in numerical terms is 0.08 )

    double price = 99.99;
    double taxrate = 0.08;
    double taxamount = price * taxrate;
    double cost = price + taxamount;

    cout << "Product Price: $" << price << endl;
    cout << "Sales tax: $" << taxrate << endl;
    cout << "Final cost: $" << cost << endl;



    cout << "Option 3" << endl;
    // 3. Assume a pizza is 12 inches in diameter. Using the standard formula, calculate and display 
    // the area of that pizza. (You'll need to determine what common geometrical shape best fits a pizza, 
    // then look up the formula for area for that shape.)

    double diameter = 12;
    double radius = diameter / 2;
    double pizzaarea = M_PI * (radius * radius); 
    cout << "A " << diameter << " inch pizza has an area of " << pizzaarea << endl;




    cout << "Option 4" << endl;

    // 4. If the pizza from question 3 is cut into 8 pieces, what is the area of each piece?
    int slices = 8;
    double areaperslice = pizzaarea / slices;
    cout << "If the " << diameter << " inch pizza is cut into " << slices << " slices, each slice has an area of " << areaperslice << endl;

//output
    return 0; //no errors



}
