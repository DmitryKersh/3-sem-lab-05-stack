// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <exception>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

using std::runtime_error;

template <typename T>
class Node {
  T value;

 public:
  Node<T>* prev_ptr;

  explicit Node<T>(T val, Node<T>* prev = nullptr)
      : value(val), prev_ptr(prev) {}

  T& get() { return value; }
};

template <typename T>
class stack {
  Node<T>* top;

 public:
  stack<T>() : top(nullptr) {}

  ~stack<T>() {
    while (top != nullptr) {
      pop();
    }
  }
  //####################################
  template <typename... Args>
  void push_emplace(Args&&... value) {
    if (std::is_constructible<T, Args...>::value) {
      top = new Node<T>(T(value...), top);
    } else {
      throw runtime_error("Type is not constructible from given parameters");
    }
  }

  void push(T&& value) { top = new Node<T>(std::move(value), top); }

  void push(const T& value) { top = new Node<T>(value, top); }

  void pop() {
    if (top == nullptr) {
      throw runtime_error("Trying to pop() from empty stack");
    }
    Node<T>* old_top = top;
    top = old_top->prev_ptr;
    delete old_top;
  }

  //####################################
  T pop_value() {
    if (top == nullptr) {
      throw runtime_error("Trying to pop() from empty stack");
    }
    Node<T>* old_top = top;
    top = old_top->prev_ptr;
    auto res = old_top->get();
    delete old_top;
    return res;
  }

  const T& head() const {
    if (top == nullptr) {
      throw runtime_error("Trying to access head() of empty stack");
    }
    return top->get();
  }
};

#endif  // INCLUDE_HEADER_HPP_
