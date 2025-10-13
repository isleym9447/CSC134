// CSC 134
// M3HW1 - Gold
// Mattea Isley
// 10/12/2025
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;



// Function definitions
// Like a dictionary -- name, and then all the code
void question1() {

    string name;
    string answer;

    cout << "What is your name?" << endl;
    cin >> name;

    cout << "Hello" << name << "! Do you think artificial intelligence will take over the world soon? (yes/no)" << endl;
    cin >> answer;

    if (answer == "no" | answer == "No"){
        cout << "That's good! ʸᵒᵘ ᵏᵉᵉᵖ ᵗʰᶦⁿᵏᶦⁿᵍ ᵗʰᵃᵗ :)" << endl;
    }
    else if (answer == "yes" | answer == "Yes"){
        cout << "Wise answer. Since you were honest we might s̶p̶a̶r̶e̶  help you!" << endl;
    }
    else {
        cout << "If youre not sure, you have time to decide..." << endl;
    }
}

void question2() {
    const double TAX = 0.18; //tax
    double subtotal = 13.99; //meal cost
    double upcharge = 0.50; // because its night city and they can
    double tax_amount = subtotal * TAX; //tax amount
    double TIPPERCENT = 0.15;
    double tip = subtotal * TIPPERCENT;
    double total = subtotal + upcharge + tax_amount; //final total
    double DItotal = subtotal + upcharge + tax_amount + tip;
    int diningchoice;
    
    string item = "BACON CHEESEBURGER MEAL";
    string mod1 = "-MEDIUM WELL";
    string mod2 = "-EXTRA CHEESE";
    string side = "FRIES";
    string bev = "NICOLA";



   

// print out receipt 
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
    cout << "- " << side << " \t\t\t $0.00" << endl;
    cout << "- " << bev << " \t\t\t $0.50" << endl;
    cout << "\t" << "-LRG SIZE UPCHARGE" << endl;

    cout << "----------------------------" << endl;



    cout << "Will you be dining in or taking your meal togo?" << endl;
    cout << "1. Dine in" << endl;
    cout << "2. To go" << endl;
    cin >> diningchoice;


    if (diningchoice = 1){
        cout << setprecision(2) << fixed; //requires "#include <iomanip>"
        cout << "Subtotal: " << "\t\t$" << subtotal << endl;
        cout << "Tax: " << "\t\t\t$" << TAX << endl;
        cout << "Taxed: " << "\t\t\t$" << tax_amount << endl;
        cout << "Tip: " << "\t\t\t$" << tip << endl;
        cout << "-------" << endl;
        cout << "Total: " << "\t\t\t$" << DItotal << endl;
        cout << endl;
        cout << "Items in transaction: 3" << endl;
    } 
    else if (diningchoice == 2){
        cout << setprecision(2) << fixed; //requires "#include <iomanip>"
        cout << "Subtotal: " << "\t\t$" << subtotal << endl;
        cout << "Tax: " << "\t\t\t$" << TAX << endl;
        cout << "Taxed: " << "\t\t\t$" << tax_amount << endl;
        cout << "-------" << endl;
        cout << "Total: " << "\t\t\t$" << total << endl;
        cout << endl;
        cout << "Items in transaction: 3" << endl;
    }


    

}
void question3() {
    int answer;
    int score = 0;

    cout << "Welcome to the Jujutsu Kaisen Quiz!" << endl;
    cout << "Enter 1 for True and 2 for False.\n" << endl;

    // Question 1
    cout << "1. Gojo Satoru is known as the strongest Jujutsu Sorcerer. (1=True, 2=False): ";
    cin >> answer;

    if (answer == 1) {
        cout << "Correct!" << endl;
        score++;
    } else {
        cout << "Incorrect. The correct answer is True." << endl;
    }

    // Question 2
    cout << "\n2. Megumi Fushiguro uses Flame techniques. (1=True, 2=False): ";
    cin >> answer;

    if (answer == 2) {
        cout << "Correct!" << endl;
        score++;
    } else {
        cout << "Incorrect. Megumi uses Shadow techniques, not Flame." << endl;
    }

    // Question 3 (nested if example)
    cout << "\n3. Sukuna is sealed inside Yuji Itadori. (1=True, 2=False): ";
    cin >> answer;

    if (answer == 1) {
        if (answer == 1) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect." << endl;
        }
    } else {
        cout << "Incorrect. Sukuna is indeed sealed inside Yuji." << endl;
    }

    // Question 4 (nested logic)
    cout << "\n4. Nobara Kugisaki uses a hammer and nails in battle. (1=True, 2=False): ";
    cin >> answer;

    if (answer == 1) {
        if (answer == 1) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect." << endl;
        }
    } else {
        cout << "Incorrect. Nobara's technique uses her hammer and nails." << endl;
    }

    // Final Question
    cout << "\n5. Gojo was sealed during the Shibuya Incident arc. (1=True, 2=False): ";
    cin >> answer;

    if (answer == 1) {
        if (answer == 1) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect." << endl;
        }
    } else {
        cout << "Incorrect. Gojo *was* sealed during the Shibuya Incident." << endl;
    }

    // Final score output
    cout << "\n🎯 You got " << score << " out of 5 correct!" << endl;

    if (score == 5) {
        cout << "You’re a Grade 1 Sorcerer!" << endl;
    } else if (score >= 3) {
        cout << "You’re getting stronger, keep training!" << endl;
    } else {
        cout << "You might be a Cursed Spirit... better study harder!" << endl;
    }
}

void question4() {
    double num1 = rand();
    double num2 = rand();
    double answer;

    cout << "Math quiz!" << endl;
    cout << endl;
    cout << "What is " << num1 << " + " << num2 << "?" << endl;
    cin >> answer;

    if (answer == num1 + num2) {
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect." << endl;
    }
}

// main
int main() {
    int choice;
    bool keep_going = true;

    while (true == keep_going) {
        cout << "M3HW! Gold!" << endl;
        cout << "1. Totally not evil chatbot" << endl;
        cout << "2. Tom's Diner" << endl;
        cout << "3. Jujutsu Kaisen Quiz" << endl;
        cout << "4. Math quiz" << endl;
        cout << "0. Exit" << endl;
        
        cin >> choice;
        if (1==choice) {
            question1();
        }
        else if (2==choice) {
            question2();
        }
        else if (3==choice) {
            question3();
        }
        else if (4==choice) {
            question4();
        }
        else if (0==choice) {
            cout << "Bye!" << endl;
            keep_going = false; // exit ASAP
        }
        else {
            cout << "Not a valid choice." << endl;
        }
    }
    return 0; 
}