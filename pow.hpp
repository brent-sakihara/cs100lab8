#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"

class Pow : public Base {
     public:
	Pow(Base* b1, Base* b2) : Base() {
	op = b1;
	op2 = b2;
	}
	double evaluate();
	std::string stringify();
	virtual Iterator* create_iterator();
        virtual Base* get_left();
        virtual Base* get_right();
     private:
	Base* op;
	Base* op2;
};

#endif	
