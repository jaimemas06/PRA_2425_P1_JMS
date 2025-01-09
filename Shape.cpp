#include "Shape.h"

Shape::Shape(){
        color = "red";
};

Shape::Shape(std::string color){
        if(color!= "red" || color !="blue" || color!="green")
                throw std::invalid_argument("colo no válido");
        this->color = color;
};

std::string Shape::get_color() const{
        return color;
};

void Shape:: set_color(std::string c){
        if(c=="red"|| c=="blue" || c=="green"){
                color = c;
        } else{
        throw std::invalid_argument("color no válido");}
};


