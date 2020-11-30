#ifndef COUNT_VISITOR_TEST
#define COUNT_VISITOR_TEST

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "arithmetic_operations.hpp"
#include "visitor.hpp"

TEST(CountVisitorTest, AddTreeCountTest){
	Op* three = new Op(3);
	Op* four = new Op(4);
	Add* sum = new Add(three, four);
	Op* nine = new Op(9);
	Sub* diff = new Sub(sum, nine);

	Op* five = new Op(5);
	Add* dummy = new Add(diff, five);

	Iterator* it = new PreorderIterator(dummy);

	CountVisitor* visit = new CountVisitor();
	it->first(); //initialize iterator
	
	while(!it->is_done()){
		Base* current = it->current();
		current->accept(visit);
		it->next();
	}

	EXPECT_EQ(visit->op_count(), 4);
	EXPECT_EQ(visit->add_count(), 1);
}

TEST(CountVisitorTest, AddTreeCountTest2){
        Op* three = new Op(3);
        Op* four = new Op(4);
        Add* sum = new Add(three, four);
        Op* nine = new Op(9);
        Sub* diff = new Sub(sum, nine);
	Op* twenty = new Op(20);
	Add* sum2 = new Add(diff, twenty);

        Op* five = new Op(5);
        Add* dummy = new Add(sum2, five);

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visit = new CountVisitor();
        it->first(); //initialize iterator

        while(!it->is_done()){
                Base* current = it->current();
                current->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 5);
        EXPECT_EQ(visit->add_count(), 2);
}

TEST(CountVisitorTest, MultiplyTreeCountTest){
        Op* negOne = new Op(-1);
	Op* thirty = new Op(30);
	Mult* product = new Mult(negOne, thirty);
	Op* twenty = new Op(20);
	Mult* product2 = new Mult(product, twenty);
	Op* four = new Op(4);
	Op* five = new Op(5);
	Add* sum = new Add(four, five);
	Mult* product3 = new Mult(product2, sum);

        Op* six = new Op(6);
        Add* dummy = new Add(product3, six);

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visit = new CountVisitor();
        it->first(); //initialize iterator

        while(!it->is_done()){
                Base* current = it->current();
                current->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 6);
        EXPECT_EQ(visit->mult_count(), 3);
}

TEST(CountVisitorTest, MultiplyTreeCountTest2){
        Op* negOne = new Op(-1);
        Op* thirty = new Op(30);
        Mult* product = new Mult(negOne, thirty);
        Op* twenty = new Op(20);
        Mult* product2 = new Mult(product, twenty);
        Op* four = new Op(4);
        Op* five = new Op(5);
        Add* sum = new Add(four, five);
        Mult* product3 = new Mult(product2, sum);
	Op* negFive = new Op(-5);
	Mult* product4 = new Mult(product3, negFive);
	Op* eight = new Op(8);
	Pow* power = new Pow(product4, eight);
	Op* thirtyTwo = new Op(32);
	Mult* product5 = new Mult(power, thirtyTwo); 

        Op* six = new Op(6);
        Add* dummy = new Add(product5, six);

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visit = new CountVisitor();
        it->first(); //initialize iterator

        while(!it->is_done()){
                Base* current = it->current();
                current->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 9);
        EXPECT_EQ(visit->mult_count(), 5);
}

TEST(CountVisitorTest, PowTreeCountTest){
        Op* two = new Op(2);
	Rand* random = new Rand();
	Pow* power = new Pow(two, random);

	Rand* random2 = new Rand();
	Op* four = new Op(4);
	Sub* diff = new Sub(random2, four);

	Pow* power2 = new Pow(power, diff);
	Op* forty = new Op(40);

	Pow* power3 = new Pow(power2, forty);
	
        Op* six = new Op(6);
        Add* dummy = new Add(power3, six);

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visit = new CountVisitor();
        it->first(); //initialize iterator

        while(!it->is_done()){
                Base* current = it->current();
                current->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 4);
        EXPECT_EQ(visit->pow_count(),3);
}

TEST(CountVisitorTest, PowTreeCountTest2){
        Op* two = new Op(2);
        Rand* random = new Rand();
        Pow* power = new Pow(two, random);

        Rand* random2 = new Rand();
        Op* four = new Op(4);
        Sub* diff = new Sub(random2, four);

        Pow* power2 = new Pow(power, diff);
        Op* forty = new Op(40);

        Pow* power3 = new Pow(power2, forty);

	Op* zero = new Op(0);
	Pow* power4 = new Pow(power3, zero);

	Op* one = new Op(1);
	Op* eight = new Op(8);
	Mult* product = new Mult(one, eight);
	
	Pow* power5 = new Pow(power4, product);

	Op* fifty = new Op(50);
	Sub* diff2 = new Sub(power5, fifty);
	
	Op* eighteen = new Op(18);
	Pow* power6 = new Pow(diff2, eighteen);

        Op* six = new Op(6);
        Add* dummy = new Add(power6, six);

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visit = new CountVisitor();
        it->first(); //initialize iterator

        while(!it->is_done()){
                Base* current = it->current();
                current->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 9);
        EXPECT_EQ(visit->pow_count(),6);
}

#endif
