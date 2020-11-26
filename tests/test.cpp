// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <MyStack.hpp>
#include <iostream>

using std::runtime_error;

class Person {
 public:
  int age;
  bool gender;
  float salary;

  Person(int a, bool g, float s) : age(a), gender(g), salary(s) {}
};

TEST(EmptyStack, no1) {
  MyStack<int> s1;
    EXPECT_THROW(s1.pop(), runtime_error);
}

TEST(PushPop, by_value) {
  MyStack<int> s1;
    s1.push(21);
    s1.push(22);
    EXPECT_EQ(s1.head(), 22);

    s1.pop();
    EXPECT_EQ(s1.head(), 21);
}

TEST(PushPop, move){
  MyStack<Person> s1;
  Person p1 = {10, true, 1000};
  s1.push(std::move(p1));
  EXPECT_EQ(s1.head().salary, 1000);

  s1.pop();
  EXPECT_THROW(s1.pop(), runtime_error);
}

TEST(Emplace, no1){
  MyStack<Person> s1;
  s1.push_emplace(10, true, 1000.0f);
  EXPECT_EQ(s1.head().age, 10);
  EXPECT_TRUE(s1.head().gender);

  EXPECT_EQ(s1.pop_value().salary, 1000.0f);
  EXPECT_THROW(s1.pop(), runtime_error);
  EXPECT_THROW(s1.head(), runtime_error);
}
