#include <ostream>
#include <cmath>
#include "Circle.h"
#define  pi 3.141492

Circle::Circle(){
	center=Point2D(0,0);
	radius=1.0;
};

Circle::Circle(std::string color, Point2D center, double radius){
	this->color = color;
	this->center = center;
	this->radius = radius;	
};

Point2D Circle:: get_center() const{
	return center;
};

void Circle:: set_center(Point2D p){
	center = p;
};

double Circle::get_radius() const{
	return radius;
};

void Circle::set_radius(double r){
	radius = r;
};

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "(" << c.color << ";" << c.center << ";" << c.radius << ")";
	return out;
};

double Circle::area() const{
	
	return pow(radius,2)*pi;
};

double Circle::perimeter() const{

	return 2*pi*radius;
};

void Circle:: translate(double incX, double incY){

	center.x += incX;
	center.y += incY;
};

void Circle:: print(){

	std::cout << *this ; 
};	
	
	



