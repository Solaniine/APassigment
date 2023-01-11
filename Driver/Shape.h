#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "Point.h"
class Shape {
    /*
    'Fields'
    area            done
    isCircular      done
    leftTop         done
    perimeter       done
    points          done
    'Methods'
    calculateArea   done
    calculatePerimeter  done
    calculatePoints done
    toString        done?


    */
public:
    //defaults
	Shape();
	Shape(int xCoordinate, int yCoordinate, float length);
	Shape(int xCoordinate, int yCoordinate, float height, float width);
    //constant value of pi to allow for less memory use 
    const double pi = 3.14592;
    std::vector<Point> getPoints() { return points; };
    Point getLeftTopPoint() { return leftTop; };
    //isCircular is true and no return value needed
    void setIsCircular() { isCircular = true; };
    //setarea takes a newarea and will update the value of area and pass the newarea into it
    void setArea(double newArea) { this->area = newArea; };
    //setperimeter takes newperimeter and points to perimeter and update the value of the newperimeter
    void setPerimeter(double newPerimeter) { this->perimeter = newPerimeter; };
    //setlefttoppoint takes point class and allows for the lefttop and updates the value of the newtopleft and puts the value into lefttop
    void setLeftTopPoint(Point newTopLeftPoint) { this->leftTop = newTopLeftPoint; };
    //set point sets a value to the point from the class points which would be the values from usercommand and changes points to the newpoints value 
    void setPoints(const std::vector<Point>& newPoints) { this->points = newPoints; };
    //virutal allows for the values to be given too different classes through the different shapes
    virtual void calculatePoints() = 0;
    virtual std::string toString() = 0;
    virtual double calculateArea() = 0; virtual double calculatePerimeter() = 0;
   
private:
    double area{}; double perimeter{};
    //point inheritance
    Point leftTop; std::vector<Point> points;
    bool isCircular = false; //or gate for circle shape
};



