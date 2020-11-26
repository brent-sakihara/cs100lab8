#include "pow.hpp"
#include <math.h>
#include "iterator.hpp"

double Pow::evaluate() {
	return pow(op->evaluate(), op2->evaluate());
} 

std::string Pow::stringify() {
	std::string result = "(" + op->stringify() + " ** " + op2->stringify() + ")";
	return result;
}

Iterator* Pow::create_iterator(){
        Iterator* i = new BinaryIterator(this);
        return i;
}

Base* Pow::get_left(){
        return op;
}

Base* Pow::get_right(){
        return op2;
}

