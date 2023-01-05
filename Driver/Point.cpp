#include "point.h"
//default
Point::Point() : x(0), y(0) 
{
}
//construct for the points x and y object
Point::Point(double x, double y) : x(x), y(y)
{
}


double Point::getX() const 
{
	return x;
}
void Point::setX(double x)
{
	this->x = x;
}

double Point::getY() const 
{ 
	return y;
}
void Point::setY(double y) 
{ 
	this->y = y;
}
