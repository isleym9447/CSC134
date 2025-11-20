//CSC 134
//Mattea Isley
// - -





//beginning with the magic words

#include <iostream>
using namespace std;

int main()
{

//variables
    int choice;
    int num;

    do 
    {
        cout << "Times table menu!" << endl;
        cout << "1: Print a times table\n";
        cout << "2: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            do
            {
                cout << "Enter a number between 1 and 12: ";
                cin >> num;

                if (num < 1 || num > 12)
                {
                    cout << "Invalid input. Please try again." << endl;
                }
            } while (num < 1 || num > 12);  

            cout << "Times table for " << num << ":\n";
            int i = 1;
            while (i <= 12)
            {
                cout << num << " x " << i << " = " << num * i << endl;
                i++;
            }
        
        }
        else if (choice != 2)
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 2);
    cout << "Exiting program. Goodbye!" << endl;
}





 
    
    
    
    
