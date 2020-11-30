#include "arithmetic_operations.hpp"
#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

double Sub::evaluate(){
	return left->evaluate() - right->evaluate();
}

std::string Sub::stringify(){
	return "(" + left->stringify() + " - " + right->stringify() + ")"; 
}

Iterator* Sub::create_iterator(){
        Iterator* i = new BinaryIterator(this);
        return i;
}

Base* Sub::get_left(){
        return left;
}

Base* Sub::get_right(){
        return right;
}

void Sub::accept(CountVisitor* v){
	v->visit_sub();
}


