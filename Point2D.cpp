#include <iostream>
#include "Point2D.h"

Point2D::Point2D(double x, double y){
		this-> x = x;
		this-> y = y;
};
double Point2D::distance(const Point2D &a, const Point2D &b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
};

bool operator==(const Point2D &a, const Point2D &b){
	if(a.x==b.x || a.y==b.y)
       	return true;

	else return false;
};

bool operator!=(const Point2D &a, const Point2D &b){
	if(a.x!=b.x|| a.y!=b.y)
	return true;
	
	else return false;
};

std::ostream&operator<<(std::ostream &out, const Point2D &p){
	out << "(" << p.x << ";" << p.y << ")";
	return out;	
};

