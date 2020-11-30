#include "op.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

double Rand::evaluate() {
        return random;
}

std::string Rand::stringify() {
        return std::to_string(random);
}

Iterator* Rand::create_iterator(){
        Iterator* i = new NullIterator(this);
        return i;
}


Base* Rand::get_left(){
        return nullptr;
}

Base* Rand::get_right(){
        return nullptr;
}

void Rand::accept(CountVisitor* v){
	return v->visit_rand();
}

