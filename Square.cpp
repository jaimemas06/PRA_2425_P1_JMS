#include <ostream>

#include "Square.h"

bool Square::check(Point2D* vertices){
	double a = Point2D::distance(vertices[0],vertices[1]);
	double b = Point2D::distance(vertices[2],vertices[3]);
	double c = Point2D::distance(vertices[1],vertices[2]);
	double d = Point2D::distance(vertices[0],vertices[3]);
	
	return a==b || c==d;
	
};

Square::Square(){
	vs = new Point2D[4]{
		Point2D(-1, 1), Point2D(1, 1), Point2D(1-1), Point2D(-1,-1)
		};
};

Square::Square(std::string color, Point2D* vertices){
	if((check(vertices))==0){
		throw std::invalid_argument("cuadrado no válido");
	};

	vs = new Point2D[4]{
		vertices[0], vertices[1], vertices[2], vertices[3]};
	set_color(color);
};
	

void Square::set_vertices(Point2D* vertices){
	if((check(vertices))==0){
                throw std::invalid_argument("cuadrado no válido");
        };

	for(int i=0; i<4; i++){
		vs[i] = vertices[i];
	};
};

std::ostream& operator<<(std::ostream &out, const Square &square){

	out << "color =" << square.color << "; v0 =" << square[0] << "; v1 =" << square[1] << "; v2 =" << square[2] << "; v3 =" << square[3];

	return out;
};
void Square::print(){
	std::cout<<*this;
}
