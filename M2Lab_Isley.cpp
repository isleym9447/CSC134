/*
CSC 134
Mattea Isley
M2Lab1 - Crates of Wrath
9/8/2025


INPUT: 
PROCESSING: 
OUTPUT: 
return 0 (no error)
SPECIAL FX:
*/



//beginning with the magic words

#include <iostream>
using namespace std;

int main()
{

//variables
    const double COST_PER_CUBIC_FOOT = 0.23; //business cost per ft
    const double CHARGE_PER_CUBIC_FOOT = 0.5; //customer cost per ft
    double length, width, height; //size of crate
    double volume;
    double cost_to_make, charge_to_customer; //pricing 
    double profit; //money made



   
//input 
    cout << "************************" << endl;
    cout << "** Crate Expectations **" << endl;
    cout << "*** Crates & Boxes ***" << endl;
    cout << "************************" << endl;
    cout << endl;

    cout << "Wecome to the online order system." << endl;
    cout << endl;

    cout << "Enter the dimensions of your create to get your quote!" << endl;

    cout << "Enter length in ft: " << endl;
    cin >> length;

    cout << "Enter width in ft: " << endl;
    cin >> width;

    cout << "Enter height in ft: " << endl;
    cin >> height;

    cout << endl;
    cout << "Calculating..." << endl;

//processing

    volume = length * width * height;
    cost_to_make = volume * COST_PER_CUBIC_FOOT;
    charge_to_customer = volume * CHARGE_PER_CUBIC_FOOT;
    profit = charge_to_customer - cost_to_make;




//output
    cout << endl;
    cout << "Your crate dimensions are: " << length << " x " << width << " x " << height << endl;
    cout << "Your crate is " << volume << " cubic feet." << endl;
    cout << endl;
    cout << "Price: $" << charge_to_customer << endl;

    cout << endl;
    cout << "*****************************************" << endl;
    cout << "** FOR BUSINESS **" << endl;
    cout << "Cost to build: $" << cost_to_make << endl;
    cout << "Profit: $ " << profit << endl;








    return 0; //no errors












}
