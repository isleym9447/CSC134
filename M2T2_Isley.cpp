/*
CSC 134
Mattea Isley
 / /


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
    const double TAX = 0.08; //tax
    double subtotal = 5.99; //meal cost
    double tax_amount = subtotal * TAX; //tax amount
    double total = subtotal + tax_amount; //final total

   


    cout << "=================" << endl;
    cout << "===Tom's Diner===" << endl;
    cout << "=================" << endl;
    cout << endl;
    cout << "Items in transaction: 1" << endl;
    cout << "Items:" << endl;
    cout << "SANDWHICH MEAL (TURKEY) $5.99" << endl;
    cout << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax: " << TAX << endl;
    cout << "Taxed: " << tax_amount << endl;
    cout << "Total: $" << total << endl;










//output
    return 0; //no errors












}

