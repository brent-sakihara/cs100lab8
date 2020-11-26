#include "arithmetic_operations.hpp"
#include "base.hpp"
#include "iterator.hpp"

double Add::evaluate(){
	return left->evaluate() + right->evaluate();
}

std::string Add::stringify(){
	return "(" + left->stringify() + " + " + right->stringify() + ")";
}

Iterator* Add::create_iterator(){
	Iterator* i = new BinaryIterator(this);
	return i;
}

Base* Add::get_left(){
	return left;
}

Base* Add::get_right(){
	return right;
}
