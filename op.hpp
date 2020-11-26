#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <stdlib.h>

class Op : public Base {
    public:
        Op(double value) : Base() {
	num = value;
	}
        double evaluate();
        std::string stringify();
	virtual Iterator* create_iterator();
        virtual Base* get_left();
        virtual Base* get_right();
     private:
	double num = 0;
};

class Rand : public Base {
     public:
        Rand() : Base() {
        random = rand() % 100;
        }
        double evaluate();
        std::string stringify();
	virtual Iterator* create_iterator();
        virtual Base* get_left();
        virtual Base* get_right();
     private:
        double random = 0;
};


#endif //__OP_HPP__
