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

double double_a_number(double); //num times 2


int main()
{

    double my_num;
    int another_num;

    say_hello();
    cout << "Please enter a number (with or without decimal place)." << endl;

    cin >> my_num;

    // my_num = my_num * 2;
    my_num = double_a_number(my_num);
    cout << "Double the number is: " << my_num << endl;





//output
    return 0; //no errors
    
    
    
}



void say_hello() {
    //says hi
    cout << "Welcome to the best program ever!" << endl;
}

int get_answer() {
    //provides answer
}


double double_a_number(double the_num) {
    //num times 2
    double answer = the_num * 2;
    return answer;
}
