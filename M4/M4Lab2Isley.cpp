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



    //varis

    //print horizontally (hard coded)////////////////////////////////
    int length = 10;
    int height = 10;
    string tile = "🍪"; // emoji or character



    for (int i=0; i<length; i++) {
        cout << tile;
        

    }

    cout << endl;



    // while loop/////////////////////////////////////////////////////////
    int count = 0;
    while (count < length){
        cout << tile;
        count ++; 

    }
    cout << endl;

    ////for loop/////////////////////////////////////////////////////////////
    for (int i = 0; i < height; i++){
        cout << tile << endl;
    }

    //draw rectangle//////////////////////////////////////////////////////////
    cout << endl << endl;
    cout << "Draw a rectangle" << endl;
    cout << "length?" << endl;
    cin >> length;
    cout << "height?" << endl;
    cin >> height;
    cout << "rectangle " << length << " x " << height << endl;
    //outer loop handles height
    //inner loop handles length

    for (int i=0; i < height; i++){
        //print the line
        for (int j=0; j < length; j++){
            cout << tile;
        }
        cout << endl;
    }



    for (int j=0; j < 3; j++){
        cout << tile;
        
    }
    cout << endl;




    int n = 6;


    for (int i=n/2; i <= n; i+=2){
       
        for (int j=1; j < n - i; j+=2)
            cout << tile << "  ";
        for (int j=1; j <= i; j++)
            cout << " ";
        for (int j=1; j <= n -i; j++)
            cout << " ";
        for (int j=1; j <= i; j++)
            cout << tile;
        cout << "\n";

    for (int i = n; i >= 1; i--) {
        for (int j = i; j < n; j++)
            cout << " ";
        for (int j = 1; j <= (i*2) - 1; j++)
            cout << tile;
        cout << "\n";




    }
        
    }
    cout << endl;





    
   


    











//output
    return 0; //no errors
    
    
    
    
    
    
    
}
