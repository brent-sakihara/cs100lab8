#ifndef FACTORY_TEST
#define FACTORY_TEST

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "arithmetic_operations.hpp"

//add, multiply

TEST(NullIteratorTest, TreeWithOneOperandThree){
	Op* three = new Op(3);
	Iterator* it = three->create_iterator();
	EXPECT_EQ(it->is_done(), true);
	EXPECT_EQ(it->current(), nullptr);
}

TEST(NullIteratorTest, TreeWithOneOperandNegFive){
        Op* negFive = new Op(-5);
        Iterator* it = negFive->create_iterator();
        EXPECT_EQ(it->is_done(), true);
        EXPECT_EQ(it->current(), nullptr);
}

TEST(BinaryIteratorTest, TreeWithAddOperatorTest1){
	Op* two = new Op(2);
	Op* three = new Op(3);
	Add* sum = new Add(two, three);
	Iterator* it = sum->create_iterator();
	it->first();
	EXPECT_EQ(it->current()->evaluate(), 2);
	it->next();
	EXPECT_EQ(it->current()->evaluate(), 3);
	it->next();
	EXPECT_EQ(it->current(), nullptr);
	EXPECT_EQ(it->is_done(), true);
}

TEST(BinaryIteratorTest, TreeWithAddOperatorTest2){
        Op* twenty = new Op(20);
        Op* negTen = new Op(-10);
        Add* sum = new Add(twenty, negTen);
        Iterator* it = sum->create_iterator();
        it->first();
        EXPECT_EQ(it->current()->evaluate(), 20);
        it->next();
        EXPECT_EQ(it->current()->evaluate(), -10);
        it->next();
        EXPECT_EQ(it->current(), nullptr);
        EXPECT_EQ(it->is_done(), true);
}

TEST(BinaryIteratorTest, TreeWithMultOperatorTest1){
        Op* five = new Op(5);
        Op* four = new Op(4);
        Mult* product = new Mult(five, four);
        Iterator* it = product->create_iterator();
        it->first();
        EXPECT_EQ(it->current()->evaluate(), 5);
        it->next();
        EXPECT_EQ(it->current()->evaluate(), 4);
        it->next();
        EXPECT_EQ(it->current(), nullptr);
        EXPECT_EQ(it->is_done(), true);
}

TEST(BinaryIteratorTest, TreeWithMultOperatorTest2){
        Op* eight = new Op(8);
        Op* negOne = new Op(-1);
        Mult* product = new Mult(eight, negOne);
        Iterator* it = product->create_iterator();
        it->first();
        EXPECT_EQ(it->current()->evaluate(), 8);
        it->next();
        EXPECT_EQ(it->current()->evaluate(), -1);
}

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
