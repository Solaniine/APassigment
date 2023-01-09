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

	Shape();
	Shape(int xCoordinate, int yCoordinate, float length);
	Shape(int xCoordinate, int yCoordinate, float height, float width);
    const double pi = 3.14592;

    std::vector<Point> getPoints() { return points; };
    Point getLeftTopPoint() { return leftTop; };


    void setIsCircular() { isCircular = true; };
    void setArea(double newArea) { this->area = newArea; };
    void setPerimeter(double newPerimeter) { this->perimeter = newPerimeter; };
    void setLeftTopPoint(Point newTopLeftPoint) { this->leftTop = newTopLeftPoint; };
    void setPoints(const std::vector<Point>& newPoints) { this->points = newPoints; };

    virtual void calculatePoints() = 0;
    virtual std::string toString() = 0;
    virtual double calculateArea() = 0; virtual double calculatePerimeter() = 0;
   
private:
    double area{}; double perimeter{};
    //point inheritance
    Point leftTop; std::vector<Point> points;
    bool isCircular = false; //or gate for circle shape
};



