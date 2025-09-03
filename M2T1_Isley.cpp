/*


CSC 134
Mattea Isley
9/3/2025

M1Lab 
Goal: program to calculate sales improved

INPUT: run the program
PROCESSING: calculations and evals
OUTPUT: return 0 (no error)
SPECIAL FX: 


*/




//beginning with the magic words

#include <iostream>
using namespace std;
int main()
{


//establish and assign variables
    string item1_name = "Sword"; //replace with your item
    string item2_name = "Staff";
    string item3_name = "Mace";
    string item4_name = "Bow and Arrow";

    int num_item1 = 10;
    double cost_per = 250.75;
    int num_wanted;
    double faerun_tax = 0.07;
    char addon_choice;
    double stone = 638;

//talk to the user (give our sales pitch)
    cout << "Greetings traveler!" << endl;
    cout << "Welcome to the Owlbear's Talon!" << endl;

    cout << "----------" << endl;

    cout << "Current inventory:" << endl; 
    cout << item1_name << "s " << endl; 
    cout << item2_name << "s " << endl; 
    cout << item3_name << "s " << endl; 
    cout << item4_name << "s " << endl; 
    cout << "---" << endl;
    cout << "We are only selling " << item1_name << "s" << " today on accout of a recent rogue theft." << endl;

    cout << "----------" << endl;

    cout << "We have " << num_item1 << " " << item1_name  << "s" << " left in stock." << endl;
    cout << "Each " << item1_name << " is $" << cost_per << " coins" << endl;


    cout << "----------" << endl;
    

    cout << "How many " << item1_name << "s do you wish to purchase?: " << endl;


//input
    //how many the user wants to purchase
    cin >> num_wanted;

    //will later create an if else branch asking for add ons depending on what weapon they select. oil for axes, extra string for bows etc.
    // if addon is yes then add price to total and name of addon to cart
    cout << "Would you like to include a grinding stone in your cart for only $638 coins?" << endl;
    cout << "Y for yes" << endl;
    cout << "N for no" << endl;

    cin >> addon_choice;



//processing
    //calculating the cost for the input

    double subtotal = num_wanted * cost_per;

    if (addon_choice == 'Y' || 'y') {
        subtotal += stone;
    } else if (addon_choice == 'N' || 'n') {
        // do nothing
    } else {
        cout << "Invalid entry" << endl;
    }

    double tax_total = subtotal * faerun_tax;
    double total_cost = subtotal + tax_total;

    
    
    
//output
    cout << "----------" << endl;
    if (addon_choice == 'Y' || 'y') {
        cout << "Subtotal: " << item1_name << " x " << num_wanted << " + " << "Grinding stone x 1" << " = $" << subtotal << endl;
    } else if (addon_choice == 'N' || 'n') {
        cout << "Subtotal: " << item1_name << " x " << num_wanted << " = $" << subtotal << endl;
    } else {
        cout << "Invalid entry" << endl;
    }


    cout << "Faerun tax: " << faerun_tax << endl;
    cout << "Tax amount: " << tax_total << endl;
    cout << " - " << endl;
    cout << "Your total for " << num_wanted << " " << item1_name << "(s) is $" << total_cost << " coins" << endl;
    









    //end program
    return 0; //no errors












}
