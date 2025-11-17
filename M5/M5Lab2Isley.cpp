// M5LAB2
// Header goes here

#include <iostream>
using namespace std;


// functions here.
double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double length, double width, double area);

int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}


double getLength()
{
   double len;
   cout << "Enter the rectangle's length: ";
   cin >> len;
   return len;
}


double getWidth()
{
   double w;
   cout << "Enter the rectangle's width: ";
   cin >> w;
   return w;
}


double getArea(double length, double width)
{
   return length * width;
}


void displayData(double length, double width, double area)
{
   cout << "\n================================" << endl;
   cout << "   Rectangle Measurements" << endl;
   cout << "================================" << endl;
   cout << "Length: " << length << " units" << endl;
   cout << "Width:  " << width << " units" << endl;
   cout << "Area:   " << area << " square units" << endl;
   cout << "================================\n" << endl;
}