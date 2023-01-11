
#include "Rectangle.h"
#include <string>

Rectangle::Rectangle() : Shape()
{
    height = 0;
    width = 0;
}

Rectangle::Rectangle(int xCoordinate, int yCoordinate, int height, int width) : Shape(xCoordinate, yCoordinate, height, width)
{
    this->width = width;
    this->height = height;
}
//calc area 
double Rectangle::calculateArea() {
    return width * height;
}
//calc perimeter  
double Rectangle::calculatePerimeter() {
    return (width * 2) + (height * 2);
}
//points gets calculated inside the rectangle and altered with the usercommand inside main 
void Rectangle::calculatePoints() {
    //instance of the vector newpoints 
    std::vector<Point> newPoints;
    //point calculations 
    Point leftTopPoint = getLeftTopPoint();
    Point rightTopPoint = Point(int(leftTopPoint.getX() + width), leftTopPoint.getY());
    Point rightBottomPoint = Point(int(leftTopPoint.getX() + width), int(leftTopPoint.getY() + height));
    Point leftBottomPoint = Point(leftTopPoint.getX(), int(leftTopPoint.getY() + height));
    //allows for the user to input 4 values to calculate the points of the new shape created. 
    newPoints.push_back(leftTopPoint);
    newPoints.push_back(rightTopPoint);
    newPoints.push_back(rightBottomPoint);
    newPoints.push_back(leftBottomPoint);

    setPoints(newPoints);
}

void Rectangle::move(int newX, int newY) {
    Point newTopLeftPoint(newX, newY);
    setLeftTopPoint(newTopLeftPoint);
    calculatePoints();
}

void Rectangle::scale(float scaleX, float scaleY) {
    width *= scaleX;
    height *= scaleY;
    calculatePoints();
}
//tostring allows all values to be made into strings with inheritance 

std::string Rectangle::toString() {
    std::string prompt = "Rectangle[h=" + std::to_string(height) + ",w=" + std::to_string(width) + "]\nPoints[("
    + std::to_string(getPoints().at(0).getX()) + "," 
    + std::to_string(getPoints().at(0).getY()) + ")(" + std::to_string(getPoints().at(1).getX()) + "," + std::to_string(getPoints().at(1).getY()) + ")(" + std::to_string(getPoints().at(2).getX())
    + "," + std::to_string(getPoints().at(2).getY()) 
    + ")(" + std::to_string(getPoints().at(3).getX()) + "," + std::to_string(getPoints().at(3).getY())
    + ")]\n Area=" + std::to_string(calculateArea()) + " Perimeter="
    + std::to_string(calculatePerimeter());
    return prompt;
}