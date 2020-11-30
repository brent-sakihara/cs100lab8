#ifndef __Arithmetic_Operations_HPP__
#define __Arithmetic_Operations_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Mult : public Base {
    public:
        Mult(Base* leftN, Base* rightN) : Base() {left = leftN; right = rightN; }
        virtual double evaluate();
        virtual std::string stringify();
	virtual Iterator* create_iterator();
	virtual Base* get_left();
	virtual Base* get_right();
	void accept(CountVisitor* v);

    private:
	Base* left;
	Base* right;

};


class Div : public Base {
    public:
        Div (Base* leftN, Base* rightN) : Base() {left = leftN; right = rightN; }
        virtual double evaluate();
        virtual std::string stringify();
	virtual Iterator* create_iterator();
        virtual Base* get_left();
        virtual Base* get_right();
	void accept(CountVisitor* v);
	
    private:
	Base* left;
	Base* right;
};


class Add : public Base {
    public:
	Add (Base* leftN, Base* rightN) : Base() {left = leftN, right = rightN; }
        virtual double evaluate();
        virtual std::string stringify();
	virtual Iterator* create_iterator();
        virtual Base* get_left();
        virtual Base* get_right();
	void accept(CountVisitor* v);

    private:
	Base* left;
	Base* right;
};


class Sub : public Base {
    public:
        Sub(Base* leftN, Base* rightN) : Base() {left = leftN, right = rightN; }
        virtual double evaluate();
        virtual std::string stringify();
	virtual Iterator* create_iterator();
        virtual Base* get_left();
        virtual Base* get_right();
	void accept(CountVisitor* v);
    
    private:
	Base* left;
	Base* right;
};


#endif

