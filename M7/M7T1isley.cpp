#include <iostream>
using namespace std;

// Use Restaurant class to store user ratings
class Restaurant {
  private:
    string name;    // the name
    double rating;  // 0 to 5 stars

  public:
    // constructor
    Restaurant(string n, double r) {
        name = n;
        rating = r;
    }
  
    // getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {
        rating = r;
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }

    // print a formatted entry
    void printInfo() {
        cout << "Name: " << name << " ";
        cout << "(" << rating << "/5 stars)" << endl;
    }
};

int main() {
    cout << "M7T1 - Restaurant Reviews (Cyberpunk Edition)" << endl;

    // Three Cyberpunk 2077 restaurants
    Restaurant breakfast_place = Restaurant("Tom's Diner", 4.2);
    Restaurant lunch_place = Restaurant("El Coyote Cojo", 4.8);
    Restaurant dinner_place = Restaurant("Embers – Japantown", 5.0);
    Restaurant dessert_place("Lizzie's BD Bar – 'Sweet SimSense' Kiosk", 1.3);

    cout << "\nReview info\n" << endl;

    cout << "Breakfast:" << endl;
    breakfast_place.printInfo();
    cout << "Review:" << endl;
    cout << "A cozy spot with a retro vibe. The pancakes are out of this world!" << endl;

    cout << "\nLunch:" << endl;
    lunch_place.printInfo();
    cout << "Review:" << endl;
    cout << "Authentic Mexican flavors that pack a punch. Don't miss the tacos!" << endl;

    cout << "\nDinner:" << endl;
    dinner_place.printInfo();
    cout << "Review:" << endl;
    cout << "A fusion of traditional and futuristic cuisine. The cybernetic enhancements make everything taste better!" << endl;

    cout << "\nDessert:" << endl;
    dessert_place.printInfo(); 
    cout << "Review:" << endl;
    cout << "The cheesecake tastes like grafted soy-paste and the “chocolate” is 30% chocolate, 70% questionable polymer." << endl;

    return 0;
}
