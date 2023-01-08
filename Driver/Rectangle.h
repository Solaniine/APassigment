#pragma once


#include "Shape.h"
#include "Movable.h"

class Rectangle : public Shape, public Movable {

private:

    double height;
    double width;

public:
    Rectangle();
    Rectangle(int xCoordinate, int yCoordinate, int height, int width);
 

    double calculateArea() override;
    double calculatePerimeter() override;
    void calculatePoints() override;

    void move(int newX, int newY) override;
    void scale(float scaleX, float scaleY) override;

    std::string toString() override;
};