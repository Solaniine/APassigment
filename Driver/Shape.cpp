#include "Shape.h"

Shape::Shape() : leftTop(0, 0)
{
    perimeter = 0;
    area = 0;
}
std::string Shape::toString() {
    return std::string();
}

//method overloading 
std::ostream& operator <<(std::ostream& os, Shape* shape)
{
    os << shape->toString();
    return os;
}
Shape::Shape(int xCoordinate, int yCoordinate, float height, float width)
{
    leftTop = Point(xCoordinate, yCoordinate);
}

Shape::Shape(int xCoordinate, int yCoordinate, float length)
{
    leftTop = Point(xCoordinate, yCoordinate);
}

