// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

template <typename T>
class Node {
  T value;
 public:
  Node<T>* prev_ptr;

  explicit Node<T>(T val, Node<T>* prev = nullptr)
      : value(val), prev_ptr(prev) {}

  T& get(){
    return value;
  }
};

template <typename T>
class stack {
  Node<T>* top;
 public:
  stack<T>() : top(nullptr) {}

  ~stack<T>() {
    while (top != nullptr){
      pop();
    }
  }

  void push(T&& value){ top = new Node<T>(value, top);
  }

  void push(const T& value){ top = new Node<T>(value, top);
  }

  void pop(){
    if (top == nullptr){
      throw std::runtime_error("Trying to pop() from empty stack");
    }
    Node<T>* old_top = top;
    top = old_top->prev_ptr;
    delete old_top;
  }

  const T& head() const{
    if (top == nullptr){
      throw std::runtime_error("Trying to access head() of empty stack");
    }
    return top->get();
  }
};

#endif  // INCLUDE_HEADER_HPP_
