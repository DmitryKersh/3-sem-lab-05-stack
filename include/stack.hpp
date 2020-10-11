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
  Node<T>* head;
 public:
  stack<T>() : head(nullptr) {}

  ~stack<T>() {
    while (head != nullptr){
      pop();
    }
  }

  void push(T&& value){
    head = new Node<T>(value, head);
  }

  void push(const T& value){
    head = new Node<T>(value, head);
  }

  void pop(){
    if (head == nullptr){
      throw std::runtime_error("Trying to access top() of empty stack");
    }
    Node<T>* old_head = head;
    head = old_head->prev_ptr;
    delete old_head;
  }

  const T& top() const{
    if (head == nullptr){
      throw std::runtime_error("Trying to access top() of empty stack");
    }
    return head->get();
  }
};

#endif  // INCLUDE_HEADER_HPP_
