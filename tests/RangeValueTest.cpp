#include "gtest/gtest.h"
#include "../inc/RangeValue.h"




TEST(RangeTest, defaultConstructorTest) {
	RangeValue <int, -100, 100> n = RangeValue<int,-100,100>();
	EXPECT_EQ(0,n.getValue());
}
TEST(RangeTest, TestDynamicDefaultConstructor) {
    RangeValue<int,100,-100>* n = nullptr;
    n = new RangeValue<int,100,-100>;
    EXPECT_EQ(0,n->getValue());
}

TEST(RangeTest, dynamicConstructorTest) {
	RangeValue <int, -100, 100> *n = new RangeValue<int,-100,100>(3);
	EXPECT_EQ(3,n->getValue());
}

TEST(RangeTest, argumentConstructorTest) {
	RangeValue <int, -100, 100> n = RangeValue<int, -100, 100>(55);
	EXPECT_EQ(55, n.getValue());
}

TEST(RangeTest, valueUnderBoundTest) {
	EXPECT_THROW((RangeValue<int, -100, 100>(-101)), RangeValueException);
}

TEST(RangeTest, valueOverBoundTest) {
	EXPECT_THROW((RangeValue<int, -100, 100>(101)), RangeValueException);
}



TEST(RangeTest, operatorMultiplyTest) {

	RangeValue<int, -100, 100> a(5);
	RangeValue<int, -100, 100> b(5);
	RangeValue<int, -100, 100> ab = a * b;
	EXPECT_EQ(25, ab.getValue());
	
}

TEST(RangeTest, operatorMinusTest) {

	RangeValue<int, -100, 100> a(5);
	RangeValue<int, -100, 100> b(2);
	RangeValue<int, -100, 100>ab = a - b ;
	EXPECT_EQ(3, ab.getValue());	
}

TEST(RangeTest, operatorPlusTest) {
	RangeValue<int,-100,100> a(5);
	RangeValue<int,-100,100> b(2);
	RangeValue<int,-100,100> ab = a+b;
	EXPECT_EQ(7, ab.getValue());
}
	
TEST (RangeTest, operatorEqualTest){

	RangeValue<int, -100, 100> a(99);
	RangeValue<int, -100, 100>b(1);
	EXPECT_FALSE(a==b);
}

TEST (RangeTest, operatorNotEqualTest){

	RangeValue<int, -100, 100> a(99);
	RangeValue<int, -100, 100> b(1);
	EXPECT_TRUE(a!=b);
}

TEST(RangeTest, operatorMultiplyAssignTest) {
	RangeValue<int, -100, 100> a(2);
	a*=3;
	EXPECT_EQ(6, a.getValue());
}


TEST(RangeTest, operatorSumAssignTest) {
	RangeValue<int, -100, 100> a(2);
	a+=2;
	EXPECT_EQ(4, a.getValue());
}

TEST(RangeTest, operatorMinusAssignTest) {

	
	RangeValue<int, -100, 100>  a(2);
	a-=1;
	EXPECT_EQ(1, a.getValue());
}


TEST (RangeTest, operatorGreaterTestTrue){

	RangeValue<int, -100, 100> a(1);
	RangeValue<int, -100, 100> b(2);
	EXPECT_FALSE(a>b);
}

TEST (RangeTest, operatorGreaterTestFalse){

	RangeValue<int, -100, 100> a(99);
	RangeValue<int, -100, 100> b(1);
	EXPECT_TRUE(a>b);
}

TEST (RangeTest, operatorLessTestFalse){

	RangeValue<int, -100, 100> a(99);
	RangeValue<int, -100, 100> b(1);
	EXPECT_FALSE(a<b);
}

TEST (RangeTest, operatorLessTestTrue){

	RangeValue<int, -100, 100> a(1);
	RangeValue<int, -100, 100> b(99);
	EXPECT_TRUE(a<b);
}



TEST(RangeTest, valueOverBoundTestByMultiply) {
	RangeValue<int, -100, 100>  a(10);
	RangeValue<int, -100, 100>  b(11);
	//RangeValue ab(1001);
	EXPECT_THROW((RangeValue<int, -100, 100>) (a*b), RangeValueException);
}

TEST(RangeTest, valueOverBoundTestByAddition) {
	RangeValue<int, -100, 100> a(99);
	RangeValue<int, -100, 100> b(99);
	EXPECT_THROW((RangeValue<int, -100, 100>)(a+b), RangeValueException);
}

TEST(RangeTest, valueOverBoundTestWhenSmallInt) {
	RangeValue<int, -10, 10> a(10);
	RangeValue<int, -10, 10> b(10);
	EXPECT_THROW((RangeValue<int, -10, 10>)(a+b), RangeValueException);
}
