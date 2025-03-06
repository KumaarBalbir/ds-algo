#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{
private:
  int top;
  int size;
  int *elements;

public:
  Stack(int size);
  ~Stack();
  void push(int val);
  int pop();
  int peek();
  bool isEmpty();
  bool isFull();
};

#endif // STACK_H