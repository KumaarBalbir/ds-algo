#include "stack.h"

Stack::Stack(int size)
{
  this->size = size;
  this->elements = new int[size];
  this->top = -1;
}

Stack::~Stack()
{
  delete[] elements;
}

bool Stack::isFull()
{
  return top == size - 1;
}

bool Stack::isEmpty()
{
  return top == -1;
}
void Stack::push(int val)
{
  if (isFull())
  {
    throw "Stack is full";
  }
  elements[++top] = val;
}

int Stack::pop()
{
  if (isEmpty())
  {
    throw "Stack is empty";
  }
  int val = elements[top];
  top--;
  return val;
}

int Stack::peek()
{
  if (isEmpty())
  {
    throw "Stack is empty";
  }
  return elements[top];
}
