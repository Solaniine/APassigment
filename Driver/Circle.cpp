#include "Circle.h"
#include <string>

Circle::Circle() : Shape()
{
    setIsCircular();
    r= 0;
}
Circle::Circle(int xCoordinate, int yCoordinate, float radius) : Shape(xCoordinate, yCoordinate, radius)
{
    setIsCircular();
    this->r = radius;
}
//calcualtes the placement of the new shape created 
void Circle::move(int newX, int newY) {
    Point newLeftTopPoint(newX, newY);
    setLeftTopPoint(newLeftTopPoint);
    calculatePoints();
}
//allows scaling to happen with the shape 
void Circle::scale(float scaleX, float scaleY) {
    r *= scaleX;
    calculatePoints();
}
//area calc
double Circle::calculateArea() {
    return pi * pow(r, 2);
}
//perimeter calc
double Circle::calculatePerimeter() {
    return  pi * r * 2;
}
//creates a vector ans holds the right and left values inside 
void Circle::calculatePoints() {
    //vector for the new points to calculate the diameter 
    std::vector<Point> newPoints;
    Point leftTopPoint = getLeftTopPoint();
    Point rightBottomPoint = Point(int(leftTopPoint.getX() + (2 * r)), 
    int(leftTopPoint.getY() + (2 * r)));
    newPoints.push_back(leftTopPoint);
    newPoints.push_back(rightBottomPoint);
    setPoints(newPoints);
}
//tostring allows all values to be made into strings with inheritance 
std::string Circle::toString() {

    std::string prompt = "Circle[r=" + std::to_string(r) 
    + "]\nPoints[(" + std::to_string(getPoints().at(0).getX())
    + "," + std::to_string(getPoints().at(0).getY()) + ")(" 
    + std::to_string(getPoints().at(1).getX())
    + "," + std::to_string(getPoints().at(1).getY()) + ")]\n Area=" 
    + std::to_string(calculateArea()) + " Perimeter="
    + std::to_string(calculatePerimeter());
    return prompt;
}


