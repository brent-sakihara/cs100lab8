#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <stdlib.h>
#include "visitor.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() {
	num = value;
	}
        double evaluate();
        std::string stringify();
	virtual Iterator* create_iterator();
        virtual Base* get_left() override;
        virtual Base* get_right() override;
	void accept(CountVisitor* v);
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
	void accept(CountVisitor* v);
     private:
        double random = 0;
};


#endif //__OP_HPP__
