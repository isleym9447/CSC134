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
#include <iomanip>
using namespace std;

int main()
{
   
//variables
    const double TAX = 0.18; //tax
    double subtotal = 13.99; //meal cost
    double upcharge = 0.50; // because its night city and they can
    double tax_amount = subtotal * TAX; //tax amount
    double total = subtotal + upcharge + tax_amount; //final total
    string item = "BACON CHEESEBURGER MEAL";
    string mod1 = "-MEDIUM WELL";
    string mod2 = "-EXTRA CHEESE";
    string side = "FRIES";



   


    cout << "===============================" << endl;
    cout << "|      ---Tom's Diner---      |" << endl;
    cout << "===============================" << endl;
    cout << "----- Watson, Night City ------" << endl;
    cout << endl;
    cout << "DATE: 9/20/2077     TIME: 22:47" << endl;
    cout << endl;
    cout << "CASHIER:  REG-MAIN 1" << endl;
    cout << endl;
    cout << "Items:" << endl;
    cout << "- " << item << "\t" << "$13.99" << endl;
    cout << "\t" << mod1 << endl;
    cout << "\t" << mod2 << endl;
    cout << "- " << side << " \t\t\t $0.50" << endl;
    cout << "\t" << "-UPCHARGE" << endl;

    cout << "----------------------------" << endl;




    cout << setprecision(2) << fixed; //requires "#include <iomanip>"
    cout << "Subtotal: " << "\t\t$" << subtotal << endl;
    cout << "Tax: " << "\t\t\t$" << TAX << endl;
    cout << "Taxed: " << "\t\t\t$" << tax_amount << endl;
    cout << "-------" << endl;
    cout << "Total: " << "\t\t\t$" << total << endl;
    cout << endl;
    cout << "Items in transaction: 1" << endl;










//output
    return 0; //no errors












}

