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