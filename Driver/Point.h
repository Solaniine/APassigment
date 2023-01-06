#pragma once

class Point
{
private:
    double x;
    double y;

public:
    // Default constructor
    Point() : x(0), y(0){}
    // Constructor with x and y coordinates
    Point(double x, double y);

    //gets X value
    double getX() const;
    //sets X value
    void setX(double x);
    //gets Y value
    double getY() const;
    //sets Y value
    void setY(double y);
};