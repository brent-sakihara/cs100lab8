
#include "arithmetic_operations.hpp"
#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

double Mult::evaluate() {
	return left->evaluate() * right->evaluate();
}

std::string Mult::stringify() {
	return "(" + left->stringify() + " * " + right->stringify() + ")";
}

Iterator* Mult::create_iterator(){
        Iterator* i = new BinaryIterator(this);
	return i;
}


Base* Mult::get_left(){
        return left;
}

Base* Mult::get_right(){
        return right;
}

void Mult::accept(CountVisitor* v){
	v->visit_mult();
}

