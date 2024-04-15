#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;
    static int totalObjects;

public:

    Circle() {
        radius = 1.0;
        totalObjects++;
    }


    Circle(double r) {
        radius = r;
        totalObjects++;
    }


    Circle(const Circle &other) {
        radius = other.radius;
        totalObjects++;
    }


    ~Circle() {
        totalObjects--;
        cout << "Circle object deleted. Total active circle objects: " << totalObjects << endl;
    }


    void calculateAndDisplayArea() const {
        double area = M_PI * radius * radius;
        cout << "Area of the circle with radius " << radius << ": " << area << endl;
    }


    static int getTotalObjects() {
        return totalObjects;
    }
};


int Circle::totalObjects = 0;

int main() {

    Circle circle1;
    Circle circle2(3.5);
    Circle circle3(circle1);


    circle1.calculateAndDisplayArea();
    circle2.calculateAndDisplayArea();
    circle3.calculateAndDisplayArea();


    cout << "Total active circle objects: " << Circle::getTotalObjects() << endl;


    {
        Circle circle4(circle2);
        circle4.calculateAndDisplayArea();
        cout << "Total active circle objects: " << Circle::getTotalObjects() << endl;
    }


    cout << "Total active circle objects: " << Circle::getTotalObjects() << endl;

    return 0;
}
