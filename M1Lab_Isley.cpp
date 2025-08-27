/*


CSC 134
Mattea Isley
8/27/2025

M1Lab 
Goal: program to calculate sales

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

    cout << "We have " << num_item1 << " left in stock." << endl;
    cout << "Each " << item1_name << " is $" << cost_per << " coins" << endl;


    cout << "----------" << endl;
    

    cout << "How many " << item1_name << "s do you wish to purchase?: " << endl;


//input
    //how many the user wants to purchase
    cin >> num_wanted;



//processing
    double total_cost = num_wanted * cost_per;
    
    
//output
    cout << "----------" << endl;
    cout << "Your total for " << num_wanted << " " << item1_name << "(s) is $" << total_cost << " coins" << endl;
    









    //end program
    return 0; //no errors












}
