#include "arithmetic_operations.hpp"

#include "base.hpp"

#include <stdexcept>

#include "iterator.hpp"

double Div::evaluate(){
	if (right->evaluate() == 0.0){
		throw std::runtime_error("Divide by Zero Exception");
	}
	return (left->evaluate() / right->evaluate());
}

std::string Div::stringify(){
	return ("(" + left->stringify() + " / " + right->stringify() + ")");
}

Iterator* Div::create_iterator(){
        Iterator* i = new BinaryIterator(this);
	return i;
}

Base* Div::get_left(){
        return left;
}

Base* Div::get_right(){
        return right;
}

