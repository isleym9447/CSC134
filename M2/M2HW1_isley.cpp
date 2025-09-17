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
#include <iomanip>




void option1() { // Bank Account Balance

// variables
string name;
double acc_balance;
double deposit;
double withdrawal;
double final_balance;

double acc_num;






cout << endl;
cout << "The Counting House Banking System" << endl;
cout << endl;

cout << "Account Info" << endl;
cout << "User Name: " << endl;
cin >> name;
cout << "Balance: " << endl;
cin >> acc_balance;
cout << "Deposit: " << endl;
cin >> deposit;
cout << "Withdrawal: " << endl;
cin >> withdrawal;

cout << "CONTACTING DATABASE..." << endl;
cout << endl;

cout << "The Counting House" << endl;
cout << "Account Holder: " << "\t\t" << name << endl;
cout << endl;
cout << "Account num:  " << "\t\t" << acc_num << endl;
cout << endl;
cout << "Balance: " << "\t\t" << final_balance << endl;







/*
double cost = 8.0;


cout << setprecision(2) << fixed; //requires "#include <iomanip>"
cout << "The cost is: $" << cost << endl;
*/



}



void option2() { // Crate Expectations
cout << endl;
cout << "" << endl;

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







}


void option3() { // Pizza Party
cout << endl;
cout << "" << endl;


}



void option4() { // School Cheer
cout << endl;
cout << "" << endl;


}


void option5() { //exit
cout << "Thank you for using. Goodbye." << endl;
}



int main() //main menu
{

cout << "Gold" << endl;
cout << endl;
cout << "Please make a selection" << endl;
cout << "=======================" << endl;
cout << "1: Bank Account Balance" << endl;
cout << "2: Crate Expectations" << endl;
cout << "3: Pizza Party" << endl;
cout << "4: School Cheer" << endl;
cout << "5: Exit" << endl;


   option1();
   option2();
   option3();
   option4();
   option5();



















//processing






//output
    return 0; //no errors












}
