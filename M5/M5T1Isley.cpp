/*

M5T1 - Basic Functions
CSC 134
Mattea Isley
10/22/25

 
INPUT: 
PROCESSING: 
OUTPUT: 
return 0 (no error)
SPECIAL FX:
*/


//beginning with the magic words

#include <iostream>
using namespace std;




/////////////////////////////////// function declarations
void say_hello(); //says hi

int get_answer(); //provides answer

double double_a_number(); //num times 2


int main()
{

    double my_num;
    int another_num;

    cout << "Welcome to the best program ever!" << endl;
    cout << "Please enter a number (with or without decimal place)." << endl;

    cin >> my_num;
    
    my_num = my_num * 2;
    cout << "Double the number is: " << my_num << endl;





//output
    return 0; //no errors
    
    
    
}

