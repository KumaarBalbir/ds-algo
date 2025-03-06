#include "stack.h"
Node::Node(int value) : data(value), next(nullptr) {}
Stack::Stack() : top(nullptr) {}

Stack::~Stack()
{
  Node *temp = top;
  while (top != nullptr)
  {
    top = top->next;
    delete temp;
    temp = top;
  }
}

void Stack::push(int value)
{
  Node *newNode = new Node(value);
  if (newNode == nullptr)
  {
    std::cout << "Stack overflow" << std::endl;
    return;
  }
  newNode->next = top;
  top = newNode;
}

bool Stack::isEmpty()
{
  return top == nullptr;
}

int Stack::pop()
{
  if (isEmpty())
  {
    std::cout << "Stack underflow" << std::endl;
    return -1;
  }
  Node *temp = top;
  int value = top->data;
  top = top->next;
  delete temp;
  return value;
}

int Stack::peek()
{
  if (isEmpty())
  {
    std::cout << "Stack is empty" << std::endl;
    return -1;
  }
  return top->data;
}