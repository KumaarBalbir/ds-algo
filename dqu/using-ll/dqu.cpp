#include "dqu.h"

Node::Node(int value)
{
  data = value;
  prev = nullptr;
  next = nullptr;
}

DEQueue::DEQueue(int size)
{
  front = nullptr;
  rear = nullptr;
}

DEQueue::~DEQueue()
{
  while (front != nullptr)
  {
    Node *temp = front;
    front = front->next;
    delete temp;
  }
}

void DEQueue::insertFront(int val)
{
  Node *newNode = new Node(val);
  if (front == nullptr)
  {
    front = rear = newNode;
  }
  else
  {
    newNode->next = front;
    front->prev = newNode;
    front = newNode;
  }
}