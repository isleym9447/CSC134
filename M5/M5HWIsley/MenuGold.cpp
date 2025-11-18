//CSC 134
//Mattea Isley


 
//INPUT: 
//PROCESSING: 
//OUTPUT: 
//return 0 (no error)
//SPECIAL FX:





//beginning with the magic words
#include <iostream>
using namespace std;



    void question1();
    void question2();
    void question3();
    void question4();
    void question5();

int main() 
{
    int choice;

    do {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Question 1 - (describe it here)\n";
        cout << "2. Question 2 - (Roman Numerals)\n";
        cout << "3. Question 3 - (your Q3 description)\n";
        cout << "4. Question 4 - Geometry Calculator\n";
        cout << "5. Question 5 - Distance Traveled\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (!cin) {  // basic protection if user types a letter
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number from 1 to 6.\n";
            continue;
        }

        switch (choice) {
            case 1:
                question1();
                break;
            case 2:
                question2();
                break;
            case 3:
                question3();
                break;
            case 4:
                question4();
                break;
            case 5:
                question5();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "The valid choices are 1 through 6.\n";
                cout << "Please select one of those options.\n";
        }

    } while (choice != 6);


}