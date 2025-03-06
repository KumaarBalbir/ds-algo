#ifndef STACK_H
#define STACK_H

#include <iostream>

class Node
{
public:
  int data;
  Node *next;
  Node(int value);
};

class Stack
{
private:
  Node *top;

public:
  Stack();
  ~Stack();
  void push(int val);
  int pop();
  int peek();
  bool isEmpty();
};

#endif // STACK_H