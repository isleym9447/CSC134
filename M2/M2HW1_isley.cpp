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
    

    double acc_num = rand() % 129843;


    cout << endl;
    cout << "The Counting House Banking System" << endl;
    cout << endl;

    cout << "Account Info" << endl;
    cout << "User Name: ";
    cin >> name;
    cout << "Balance: $";
    cin >> acc_balance;
    cout << "Deposit: $";
    cin >> deposit;
    cout << "Withdrawal: $";
    cin >> withdrawal;

    cout << endl;
    cout << "CONTACTING DATABASE..." << endl;
    cout << endl;

    double final_balance = (acc_balance + deposit) - withdrawal;

    cout << "The Counting House" << endl;
    cout << "==================" << endl;
    cout << "Account Holder: " << "\t\t" << name << endl;
    cout << endl;
    cout << "Account num:  " << "\t\t\t" << acc_num << endl;
    cout << endl;

    if (acc_balance || deposit || final_balance >= 0){
        cout << "Balance: " << "\t\t\t" << "$" << final_balance << endl;
        cout << endl; 
    }

    if (final_balance < 0){
        cout << "You do not have the available funds to continue with your request. Goodbye." << endl;
        cout << endl;
    }


}



void option2() { // Crate Expectations
    cout << endl;
    cout << "" << endl;

    const double COST_PER_CUBIC_FOOT = 0.30; //business cost per ft
    const double CHARGE_PER_CUBIC_FOOT = 0.52; //customer cost per ft
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

    //variables
    int people;
    




    cout << endl;
    cout << "~~BUCK-A-SLICE~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~MENU~~~~~~~" << endl;
    cout << endl;
    cout << "~~~~~~~~~PIZZA~~~~~~~~~" << endl;
    cout << "SMALL PIE (4 SLICES)\t $8.99" << endl;
    cout << "MEDIUM PIE (6 SLICES)\t $10.99" << endl;
    cout << "LARGE PIE (8 SLICES)\t $15.99" << endl;
    cout << "HUGE PIE (120 SLICES)\t $56.99" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << "~~~~~~SIDES + BEVS~~~~~" << endl;
    cout << "BREADSTICKS\t $7.99" << endl;
    cout << "CHEESESTICKS\t $8.99" << endl;
    cout << "~~" << endl;
    cout << "NICOLA\t $2.99" << endl;
    cout << "TIANCHA\t $2.99" << endl;
    cout << "CHROMANTICORE\t $4.99" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    

    cout << "How many friends ya inviting?";
    cin >> people;

// if people == 1 and pizzas >1, cout "no judgement"
// if people == >5, cout "Ya might want to add some breadsticks"







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

    int choice;

   
    cout << endl;
    cout << "=======Gold Menu=======" << endl;
    cout << "=======================" << endl;
    cout << "1: Bank Account Balance" << endl;
    cout << "2: Crate Expectations" << endl;
    cout << "3: Pizza Party" << endl;
    cout << "4: School Cheer" << endl;
    cout << "5: Exit" << endl;
    cout << "=======================" << endl;
    cout << "Please make a selection: ";
    cin >> choice;




    if (choice == 1) {
        option1();
    }
    
    else if (choice == 2) {
        option2();
    }
    
    else if (choice == 3) {
        option3();
    }

    else if (choice == 4) {
        option4();
    }

    else if (choice == 5) {
        option5();
    }
    
    else {
        cout << "Invalid. Try again." << endl;
    }



















//processing






//output
    return 0; //no errors












}
