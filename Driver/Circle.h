#include <cmath>
#include "Shape.h"
#include "Movable.h"
#include "Point.h"

class Circle : public Shape, public Movable {

private:

    //radius
    short r;

public:
    //default
    Circle();
    //constructor 
    Circle(int xCoordinate, int yCoordinate, float radius);
    //allows inheritance in all child classes all the member data 
    std::string toString() override;
    void move(int newX, int newY) override; void scale(float scaleX, float scaleY) override;
    double calculateArea() override;
    double calculatePerimeter() override;
    void calculatePoints() override;

};

