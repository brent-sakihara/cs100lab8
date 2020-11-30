#ifndef COUNT_VISITOR__TEST
#define COUNT_VISITOR_TEST

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "arithmetic_operations.hpp"
#include "visitor.hpp"

TEST(IteratorTest, Subtest){
	Base* num = new Op(3);
	Base* num2 = new Op(1);
	Sub* s = new Sub(num, num2);
	Base* num3 = new Op(4);
	Base* dummy = new Add(s, num3);
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* v = new CountVisitor();
	
	it->first();
	while(!it->is_done()) {
		Base* c = it->current();
		c->accept(v);
		it->next();
	}
	
	EXPECT_EQ(v->op_count(), 3);
	EXPECT_EQ(v->sub_count(), 1);
	EXPECT_EQ(v->add_count(), 0);
}

TEST(IteratorTest, Divtest){
        Base* num = new Op(9);
        Base* num2 = new Op(4);
        Div* d = new Div(num, num2);
        Base* num3 = new Op(1);
        Base* m = new Mult(d, num3);
	Base* dummy = new Add(m, num);
        Iterator* it = new PreorderIterator(dummy);
        CountVisitor* v = new CountVisitor();

        it->first();
        while(!it->is_done()) {
                Base* c = it->current();
                c->accept(v);
                it->next();
        }

        EXPECT_EQ(v->op_count(), 4);
        EXPECT_EQ(v->div_count(), 1);
        EXPECT_EQ(v->mult_count(), 1);
	EXPECT_EQ(v->add_count(), 0);
}

TEST(IteratorTest, DivRandtest){
        Base* num = new Op(9);
        Base* num2 = new Rand();
        Div* d = new Div(num, num2);
        Base* num3 = new Op(1);
	Base* num4 = new Rand();
        Base* d2 = new Div(num3, num4);
        Base* dummy = new Pow(d, d2);
        Iterator* it = new PreorderIterator(dummy);
        CountVisitor* v = new CountVisitor();

        it->first();
        while(!it->is_done()) {
                Base* c = it->current();
                c->accept(v);
                it->next();
        }

        EXPECT_EQ(v->op_count(), 2);
	EXPECT_EQ(v->rand_count(), 2);
        EXPECT_EQ(v->div_count(), 2);
        EXPECT_EQ(v->pow_count(), 0);
}

TEST(IteratorTest, SubRandtest){
        Base* num = new Op(20);
        Base* num2 = new Rand();
        Sub* s = new Sub(num, num2);
        Base* num3 = new Rand();
        Base* num4 = new Rand();
        Base* s2 = new Sub(s, num3);
	Base* d = new Div(num3, num4);
        Base* dummy = new Mult(s2, d);
        Iterator* it = new PreorderIterator(dummy);
        CountVisitor* v = new CountVisitor();

        it->first();
        while(!it->is_done()) {
                Base* c = it->current();
                c->accept(v);
                it->next();
        }

        EXPECT_EQ(v->op_count(), 1);
        EXPECT_EQ(v->rand_count(), 4);
        EXPECT_EQ(v->sub_count(), 2);
        EXPECT_EQ(v->div_count(), 1);
	EXPECT_EQ(v->mult_count(), 0);
}

TEST(IteratorTest, SubDivtest){
        Base* num = new Op(20);
        Base* num2 = new Op(8);
        Base* s = new Sub(num, num2);
        Base* num3 = new Rand();
        Base* num4 = new Rand();
        Base* d = new Div(num3, num4);
        Base* s2 = new Sub(s, d);
	Base* d2 = new Div(s2, s);
        Base* dummy = new Mult(d2, num);
        Iterator* it = new PreorderIterator(dummy);
        CountVisitor* v = new CountVisitor();

        it->first();
        while(!it->is_done()) {
                Base* c = it->current();
                c->accept(v);
                it->next();
        }

        EXPECT_EQ(v->op_count(), 5);
        EXPECT_EQ(v->rand_count(), 2);
        EXPECT_EQ(v->sub_count(), 3);
        EXPECT_EQ(v->div_count(), 2);
        EXPECT_EQ(v->mult_count(), 0);
}

TEST(IteratorTest, Randtest){
        Base* num = new Rand();
        Base* num2 = new Rand();
        Base* dummy = new Pow(num, num2);
        Iterator* it = new PreorderIterator(dummy);
        CountVisitor* v = new CountVisitor();

        it->first();
        while(!it->is_done()) {
                Base* c = it->current();
                c->accept(v);
                it->next();
        }

        EXPECT_EQ(v->op_count(), 0);
        EXPECT_EQ(v->rand_count(), 2);
        EXPECT_EQ(v->sub_count(), 0);
        EXPECT_EQ(v->div_count(), 0);
        EXPECT_EQ(v->mult_count(), 0);
	EXPECT_EQ(v->pow_count(), 0);
}

TEST(IteratorTest, Mixedtest){
        Base* num = new Op(20);
        Base* num2 = new Rand();
        Base* a = new Add(num, num2);
        Base* num3 = new Op(4);
        Base* num4 = new Rand();
        Base* p = new Pow(num3, num4);
        Base* d = new Div(a, p);
	Base* num5 = new Op(9);
	Base* s = new Sub(d, num5);
        Base* dummy = new Mult(s, num);
        Iterator* it = new PreorderIterator(dummy);
        CountVisitor* v = new CountVisitor();

        it->first();
        while(!it->is_done()) {
                Base* c = it->current();
                c->accept(v);
                it->next();
        }

        EXPECT_EQ(v->op_count(), 4);
        EXPECT_EQ(v->rand_count(), 2);
	EXPECT_EQ(v->add_count(), 1);
        EXPECT_EQ(v->sub_count(), 1);
        EXPECT_EQ(v->div_count(), 1);
        EXPECT_EQ(v->mult_count(), 0);
	EXPECT_EQ(v->pow_count(), 1);
}



#endif
