#pragma once

#include <cmath>
#include "Shape.h"
#include "Movable.h"

class Square : public Shape, public Movable {

private:
    double edge;

public:

   
    Square();   
    Square(int xCoordinate, int yCoordinate, int edge);
    double calculateArea() override;
    double calculatePerimeter() override;
    void calculatePoints() override;
    void move(int newX, int newY) override;
    void scale(float scaleX, float scaleY) override;

    std::string toString() override;
};
