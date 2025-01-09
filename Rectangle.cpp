#include <ostream>
#include "Rectangle.h"
#include <iostream>
bool Rectangle::check(Point2D* vertices){
	
	double d1 = Point2D::distance(vertices[0], vertices[1]);
	double d2 = Point2D::distance(vertices[2], vertices[3]);
	double d3 = Point2D::distance(vertices[1], vertices[2]);
	double d4 = Point2D::distance(vertices[0], vertices[3]);

	return d1==d2 && d3==d4;
}

Rectangle::Rectangle(){
	 vs = new Point2D[N_VERTICES]{
		 Point2D(-1, 0.5),
		 Point2D(1, 0.5),
		 Point2D(1, -0.5),
		 Point2D(-1, -0.5)
	 };
}

Rectangle::Rectangle(std::string, Point2D* vertices){

	vertices = new Point2D[N_VERTICES]{
		vertices[0],vertices[1], vertices[2], vertices[3]
	};

	set_color(color);

	if(check(vertices)==0){
		throw std::invalid_argument("no forman un rectangulo");
	}
}

Rectangle::Rectangle(const Rectangle &r){
	vs = new Point2D[N_VERTICES]{
		r.vs[0], r.vs[1], r.vs[2], r.vs[3]};
	set_color(r.get_color());
}

Rectangle::~Rectangle(){
	delete [] vs;
}

Point2D Rectangle::get_vertex(int ind) const{

	if(0>ind || ind>N_VERTICES-1){
		throw std::out_of_range("índice no es válido");
	}

	return vs[ind];
}

Point2D Rectangle::operator[](int ind) const{
	return get_vertex(ind);
}

Rectangle& Rectangle::operator=(const Rectangle &r){
	Rectangle copia(r);
	 *this=copia;
	 return *this;
}

std::ostream& operator <<(std::ostream &out, const Rectangle &r){
std::cout<<"hola";
	out <<"color: " << r.color << "; v[0] = " << r[0] << "; v[1] = " << r[1] <<"; v[2] = " << r[2] <<";v[3] = " << r[3];
	return out;
}

double Rectangle::area() const{
	double lA = Point2D::distance(vs[0],vs[1]);
	double lB = Point2D::distance(vs[1], vs[2]);

	return lA*lB;
}

double Rectangle::perimeter() const{
	
	return Point2D::distance(vs[0],vs[1])*2+Point2D::distance(vs[1],vs[2])*2;

	/*double lA = Point2D::distance(vs[0],vs[1]);
        double lB = Point2D::distance(vs[2], vs[3]);
	double lC = Point2D::distance(vs[1],vs[2]);
        double lD = Point2D::distance(vs[0], vs[3]);

	return lA+lB+lC+lD;*/
}

void Rectangle::translate(double incX, double incY){
	for(int i=0; i<N_VERTICES; i++){
		vs[i].x+=incX;
		vs[i].y+=incY;
	}
}

void Rectangle::print(){
	std::cout << *this;
}

void Rectangle::set_vertices(Point2D* vertices){
	 if(check(vertices)==0){

                throw std::invalid_argument("no forman un rectangulo");
        }

	for(int i=0; i<4; i++){
		vs[i]=vertices[i];
	}
}


