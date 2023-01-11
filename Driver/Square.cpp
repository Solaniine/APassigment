#include "Square.h"
#include <string>

using namespace std;
//default 
Square::Square() : Shape()
{
    edge = 0;
}
//default 
Square::Square(int xCoordinate, int yCoordinate, int edge) : Shape(xCoordinate, yCoordinate, edge)
{
    this->edge = edge;
}
//calc area 
double Square::calculateArea() {
    return pow(edge, 2);
}
//calcs perimeter
double Square::calculatePerimeter() {
    return edge * 4;
}
//allows for the user to input 4 values to calculate the points of the new shape created. 
void Square::calculatePoints() {
    std::vector<Point> newPoints;
    Point leftTopPoint = getLeftTopPoint();
    Point rightTopPoint = Point(int(leftTopPoint.getX() + edge), leftTopPoint.getY());
    Point rightBottomPoint = Point(int(leftTopPoint.getX() + edge), int(leftTopPoint.getY() + edge));
    Point leftBottomPoint = Point(leftTopPoint.getX(), int(leftTopPoint.getY() + edge));

    newPoints.push_back(leftTopPoint);
    newPoints.push_back(rightTopPoint);
    newPoints.push_back(rightBottomPoint);
    newPoints.push_back(leftBottomPoint);

    setPoints(newPoints);
}

void Square::move(int newX, int newY) {
    Point newTopLeftPoint(newX, newY);
    setLeftTopPoint(newTopLeftPoint);
    calculatePoints();
}

void Square::scale(float scaleX, float scaleY) {
    edge *= scaleX;
    calculatePoints();
}
//tostring allows all values to be made into strings with inheritance 


std::string Square::toString() {
    std::string prompt = "Square[e=" + std::to_string(edge) 
    + "]\nPoints[(" + std::to_string(getPoints().at(0).getX())
    + "," + std::to_string(getPoints().at(0).getY()) 
    + ")(" + std::to_string(getPoints().at(1).getX()) 
    + "," + std::to_string(getPoints().at(1).getY()) + ")(" 
    + std::to_string(getPoints().at(2).getX()) + ","
    + std::to_string(getPoints().at(2).getY()) + ")("
    + std::to_string(getPoints().at(3).getX()) + ","
    + std::to_string(getPoints().at(3).getY()) + ")]\n Area=" + std::to_string(calculateArea()) + " Perimeter="
    + std::to_string(calculatePerimeter());
    return prompt;
}