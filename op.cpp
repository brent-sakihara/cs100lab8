#include "op.hpp"
#include "iterator.hpp"

double Op::evaluate() {
	return num;
}

std::string Op::stringify() {
	return std::to_string(num);
}

Iterator* Op::create_iterator(){
        Iterator* i = new NullIterator(this);
        return i;
}

Base* Op::get_left(){
        return nullptr;
}

Base* Op::get_right(){
        return nullptr;
}

