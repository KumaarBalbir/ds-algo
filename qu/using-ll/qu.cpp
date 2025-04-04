#include "qu.h"

Queue::Queue()
{
  front = rear = nullptr;
}
Queue::~Queue()
{
  while (front != nullptr)
  {
    Node *temp = front;
    front = front->next;
    delete temp;
  }
}
void Queue::Enqueue(int val)
{
  if (rear == nullptr)
  {
    front = rear = new Node(val);
    return;
  }
  rear->next = new Node(val);
  rear->next->prev = rear;
  rear = rear->next;
}
int Queue::Dequeue()
{
  if (front == nullptr)
  {
    printf("Q is empty\n");
    return -1;
  }
  int data = front->data;
  Node *temp = front;
  front = front->next;
  if (front != nullptr)
    front->prev = nullptr;
  else
    rear = nullptr; // queue is now empty
  delete temp;
  return data;
}
void Queue::display()
{
  if (front == nullptr)
  {
    printf("Q is empty\n");
    return;
  }
  Node *temp = front;
  while (temp != nullptr)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}