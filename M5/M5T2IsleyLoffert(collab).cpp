/*
CSC 134
M5T2
Lydia Loffert & Mattea Isley
10/22/2015
*/


/*
This program will involve us using some simple functions, both void and value-returning, to solve this problem:

List the numbers from 1 to 10 along with the squares of those numbers. (Note this is similar to our times table problem from last module.)

Specifications:

a main() function

a square() function that takes an int, and returns the square of that int (value returning)

a printAnswerLine() function that prints one line of the answer (void)
*/








//beginning with the magic words

#include <iostream>
using namespace std;





void printanswerline(double num, double sqr){
    // prints line of numbers

    /* hard coding no bueno
    cout << "1\n";
    cout << "2\n";
    cout << "3\n";
    cout << "4\n";
    cout << "5\n";
    cout << "6\n";
    cout << "7\n";
    cout << "8\n";
    cout << "9\n";
    cout << "10\n";
    */

    for (int i = 1; i <= 10; i++) {
        int sq = square(i);
        printanswerline(i, sq);
    }





}


double square(double num){
    // squares the number 
    return num * num;





}




int main()
{
 //calculations and printing 

    cout << "Numbers: " << endl;
    printanswerline(num, sqr);

    cout << "Squares: " << endl;






//output
    return 0; //no errors
    
    
    
}