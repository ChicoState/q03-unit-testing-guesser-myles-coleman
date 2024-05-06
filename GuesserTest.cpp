/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"
#include <iostream>

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

//test correct match
TEST(GuesserTest, matchCorrect) {
	Guesser secret("hello");
	bool actual = secret.match("hello");
	ASSERT_EQ(true, actual);
}

//test distance 1
TEST(GuesserTest, matchDistanceOne) {
	Guesser secret("hello");
	bool actual = secret.match("hello!");
	ASSERT_EQ(false, actual);
}

//test brute force 
TEST(GuesserTest, matchBruteForce) {
	Guesser secret("hello");
	secret.match("!hello");
	bool actual = secret.match("hello");
	ASSERT_EQ(false, actual);
}

//test two guesses remaining
TEST(GuesserTest, matchFailOne) {
	Guesser secret("hello");
	secret.match("hello!");
	bool actual = secret.match("hello");
	ASSERT_EQ(true, actual);
}

//test 1 guess remaining
TEST(GuesserTest, matchFailTwo) {
	Guesser secret("hello");
	secret.match("hello!");
	secret.match("hello!");
	bool actual = secret.match("hello");
	ASSERT_EQ(true, actual);
}

//test 0 guesses remaining
TEST(GuesserTest, matchFailThree) {
	Guesser secret("hello");
	secret.match("hello!");
	secret.match("hello!");
	secret.match("hello!");
	bool actual = secret.match("hello");
	ASSERT_EQ(false, actual);
}

//test constructor?
TEST(GuesserTest, correctConstructor) {
	Guesser secret("hello");
	unsigned int actual = secret.remaining();
	ASSERT_EQ(3, actual);
}

//test remaining guesses for two fails
TEST(GuesserTest, remainingResest) {
	Guesser secret("hello");
	secret.match("hello!");
	secret.match("hello!");
	bool actual = secret.match("hello");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, remainingTwo) {
	Guesser secret("hello");
	secret.match("hello!");
	unsigned int actual = secret.remaining();
	ASSERT_EQ(2, actual);
}

TEST(GuesserTest, remainingOne) {
	Guesser secret("hello");
	secret.match("hello!");
	secret.match("hello!");
	unsigned int actual = secret.remaining();
	ASSERT_EQ(1, actual);
}

TEST(GuesserTest, remainingZero) {
	Guesser secret("hello");
	secret.match("hello!");
	secret.match("hello!");
	secret.match("hello!");
	unsigned int actual = secret.remaining();
	ASSERT_EQ(0, actual);
}