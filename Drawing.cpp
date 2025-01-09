#include <iostream>

#include "Shape.h"
#include "Drawing.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

#include "ListArray.h"

Drawing::Drawing(){
	shapes = new ListArray<Shape*>;
}

Drawing::~Drawing(){
	delete shapes;
}

void Drawing::add_front(Shape* shape){
	shapes->append(shape);
}

void Drawing::add_back(Shape* shape){
        shapes->prepend(shape);
}

void Drawing:: print_all(){
	for(int i=0; i < shapes->size();i++){
		shapes->get(i)->print();
		std::cout << std::endl;
	}

}

double Drawing::get_area_all_circles(){
	double area_totales = 0.0;
	for(int i=0; i < shapes->size(); i++){
		Circle* p=dynamic_cast<Circle*>(shapes->get(i));
		if(p){
		       	area_totales+=shapes->get(i)->area();
		}
	}
	return area_totales;
};

void Drawing::move_squares(double incX, double incY){
	for(int i=0; i < shapes->size(); i++){
		Square* s = dynamic_cast<Square*>(shapes->get(i));
		if(s){
			shapes->get(i)->translate(incX,incY);
		}
	}
};
