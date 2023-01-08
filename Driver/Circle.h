#include <cmath>
#include "Shape.h"
#include "Movable.h"


class Circle : public Shape, public Movable {

private:

    short radius;

public:

    Circle();Circle(int xCoordinate, int yCoordinate, float radius);
    double calculateArea() override;
    double calculatePerimeter() override;
    void calculatePoints() override;

    std::string toString() override;
    void move(int newX, int newY) override; void scale(float scaleX, float scaleY) override;


};

