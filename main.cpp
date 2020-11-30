#include "op.hpp"
#include "pow.hpp"
#include "arithmetic_operations.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <iostream>

using namespace std;

int main(){

	Op* six = new Op(6);
        Rand* random = new Rand();
        Add* a = new Add(six, random);

        Rand* random2 = new Rand();
        Op* oneHundred = new Op(100);
        Sub* s = new Sub(random2, oneHundred);

        Op* twentyOne = new Op(21);
	Rand* random3 = new Rand();
	Mult* m = new Mult(twentyOne, random3);

	Op* seventy = new Op(70);
	Rand* random4 = new Rand();
	Div* d = new Div(seventy, random4);

	Op* fiftyFour = new Op(54);
	Rand* random5 = new Rand();
	Pow* p = new Pow(fiftyFour, random5);

	Mult* m2 = new Mult(s, d);
	Pow* p2 = new Pow(a, m);
	Sub* s2 = new Sub(m2, p);
	
        Add* dummy = new Add(s2, p2);

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visit = new CountVisitor();
        it->first(); //initialize iterator

	cout << dummy->stringify() << endl;

        while(!it->is_done()){
                Base* current = it->current();
                current->accept(visit);
                it->next();
        }
	
	cout << "Op Count: " << visit->op_count() << endl;
	cout << "Pow Count: " << visit->pow_count() << endl;
	cout << "Rand Count: " << visit->rand_count() << endl;
	cout << "Add Count: " << visit->add_count() << endl;
	cout << "Sub Count: " << visit->sub_count() << endl;
	cout << "Mult Count: " << visit->mult_count() << endl;
	cout << "Div Count: " << visit->div_count() << endl;

	return 0;
}
