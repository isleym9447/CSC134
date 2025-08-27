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

    string item1_name = "sword"; //replace with your item
    string item2_name = "staff";
    string item3_name = "mace";
    string item4_name = "bow and arrow";

    int num_item1 = 10;
    double cost_per = 250.75;
    int num_wanted;


    // give our sales pitch
    cout << "Greetings traveler!" << endl;
    cout << "Welcome to the Owlbear's Talon!" << endl;

    cout << "----------" << endl;

    cout << "We sell " << item1_name << "s " << "and " << item2_name << "s" << "!" << endl;
    cout << "We are only selling " << item1_name << "s" << " today on accout of a recent rogue theft." << endl;

    cout << "----------" << endl;

    cout << "We have " << num_item1 << " total in stock." << endl;
    cout << "Each " << item1_name << " is $" << cost_per << " coins" << endl;

    cout << "----------" << endl;
    cout << "----------" << endl;

    cout << "How many " << item1_name << "s do you wish to purchase?: " << endl;


    cin >> num_wanted;



    // do the processing
    double total_cost = num_wanted * cost_per;
    

    //output
    cout << "Your total for " << num_wanted << " " << item1_name << "(s) is $" << total_cost << " coins" << endl;









    //end program
    return 0; //no errors












}
