#include "Circle.h"
#include <string>

Circle::Circle() : Shape()
{
    setIsCircular();
    radius = 0;
}

Circle::Circle(int xCoordinate, int yCoordinate, float radius) : Shape(xCoordinate, yCoordinate, radius)
{
    setIsCircular();
    this->radius = radius;
}


double Circle::calculateArea() {
    return pi * pow(radius, 2);
}

double Circle::calculatePerimeter() {
    return  pi * radius * 2;
}

void Circle::calculatePoints() {
    std::vector<Point> newPoints;
    Point leftTopPoint = getLeftTopPoint();
    Point rightBottomPoint = Point(int(leftTopPoint.getX() + (2 * radius)), 
    int(leftTopPoint.getY() + (2 * radius)));

    newPoints.push_back(leftTopPoint);
    newPoints.push_back(rightBottomPoint);

    setPoints(newPoints);
}

void Circle::move(int newX, int newY) {
    Point newLeftTopPoint(newX, newY);
    setLeftTopPoint(newLeftTopPoint);
    calculatePoints();
}

void Circle::scale(float scaleX, float scaleY) {
    radius *= scaleX;
    calculatePoints();
}

std::string Circle::toString() {
    std::string prompt = "Circle[r=" + std::to_string(radius) 
    + "]\nPoints[(" + std::to_string(getPoints().at(0).getX())
    + "," + std::to_string(getPoints().at(0).getY()) + ")(" + std::to_string(getPoints().at(1).getX())
    + "," + std::to_string(getPoints().at(1).getY()) + ")]\n Area=" + std::to_string(calculateArea()) + " Perimeter=" + std::to_string(calculatePerimeter());
    return prompt;
}


