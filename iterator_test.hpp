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
        it->next();
        EXPECT_EQ(it->current(), nullptr);
        EXPECT_EQ(it->is_done(), true);
}

#endif
