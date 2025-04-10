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

int DEQueue::deleteFront()
{
  if (front == nullptr)
  {
    std::cout << "DEQueue is empty" << std::endl;
    return -1;
  }
  int data = front->data;
  Node *temp = front;
  front = front->next;
  if (front != nullptr)
  {
    front->prev = nullptr;
  }
  else
  {
    rear = nullptr;
  }
  delete temp;
  return data;
}

void DEQueue::insertRear(int val)
{
  Node *newNode = new Node(val);
  if (rear == nullptr)
  {
    front = rear = newNode;
  }
  else
  {
    rear->next = newNode;
    newNode->prev = rear;
    rear = newNode;
  }
}
