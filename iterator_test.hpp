#ifndef ITERATOR_TEST
#define ITERATOR_TEST

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "arithmetic_operations.hpp"
#include "op.hpp"
#include "pow.hpp"

TEST(SubBinaryIteratorTest, Sub){
	Base* num = new Op(4);
	Base* num2 = new Op(1);
	Sub* dummy = new Sub(num,num2);
	
	Iterator* it = dummy->create_iterator();
	it->first();
	EXPECT_EQ(it->current(), num);
	it->next();
	EXPECT_EQ(it->current(), num2);
}

TEST(SubBinaryIteratorTest, Sub2){
        Base* num = new Op(9);
        Base* num2 = new Op(5);
        Sub* dummy = new Sub(num,num2);

        Iterator* it = dummy->create_iterator();
        it->first();
        EXPECT_EQ(it->current(), num);
	EXPECT_EQ(it->is_done(), false);
        it->next();
        EXPECT_EQ(it->current(), num2);
	EXPECT_EQ(it->is_done(), false);
	it->next();
	EXPECT_EQ(it->is_done(), true);
}


TEST(DivBinaryIteratorTest, Div){
        Base* num = new Op(2);
        Base* num2 = new Op(16);
        Div* dummy = new Div(num,num2);

        Iterator* it = dummy->create_iterator();
        it->first();
        EXPECT_EQ(it->current(), num);
        it->next();
        EXPECT_EQ(it->current(), num2);
}

TEST(DivBinaryIteratorTest, Div2){
        Base* num = new Op(72);
        Base* num2 = new Op(9);
        Div* dummy = new Div(num,num2);

        Iterator* it = dummy->create_iterator();
        it->first();
        EXPECT_EQ(it->current(), num);
        EXPECT_EQ(it->is_done(), false);
        it->next();
        EXPECT_EQ(it->current(), num2);
        EXPECT_EQ(it->is_done(), false);
        it->next();
        EXPECT_EQ(it->is_done(), true);
}


TEST(PowBinaryIteratorTest, Pow){
        Base* num = new Op(10);
        Base* num2 = new Op(3);
        Pow* dummy = new Pow(num,num2);

        Iterator* it = dummy->create_iterator();
        it->first();
        EXPECT_EQ(it->current(), num);
        it->next();
        EXPECT_EQ(it->current(), num2);
}

TEST(PowBinaryIteratorTest, Pow2){
        Base* num = new Op(1);
        Base* num2 = new Op(17);
        Pow* dummy = new Pow(num,num2);

        Iterator* it = dummy->create_iterator();
        it->first();
        EXPECT_EQ(it->current(), num);
        EXPECT_EQ(it->is_done(), false);
        it->next();
        EXPECT_EQ(it->current(), num2);
        EXPECT_EQ(it->is_done(), false);
        it->next();
        EXPECT_EQ(it->is_done(), true);
}


TEST(NullIteratorTest, Null1){
        Base* num = new Op(4);

        Iterator* it = num->create_iterator();
        it->first();
	EXPECT_EQ(it->is_done(), true);
        it->next();
	EXPECT_EQ(it->is_done(), true);
}

TEST(NullIteratorTest, Null2){
        Base* num = new Op(15);

        Iterator* it = num->create_iterator();
        it->first();
        EXPECT_EQ(it->current(), nullptr);
        EXPECT_EQ(it->is_done(), true);
        it->next();
        EXPECT_EQ(it->current(), nullptr);
        EXPECT_EQ(it->is_done(), true);
}


#endif
