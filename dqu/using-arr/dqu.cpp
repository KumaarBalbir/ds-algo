#include "dqu.h"

DEQueue::DEQueue(int size)
{
  front = -1;
  rear = -1;
  this->size = size;
  arr = new int[size];
}
DEQueue::~DEQueue()
{
  delete[] arr;
}
void DEQueue::insertFront(int val)
{
  if ((front == 0 && rear == size - 1) || (front == rear + 1))
  {
    printf("DEQueue is full\n");
    return;
  }
  if (front == -1) // first element
  {
    front = rear = 0;
  }
  else if (front == 0)
  {
    front = size - 1;
  }
  else
  {
    front--;
  }
  arr[front] = val;
}
int DEQueue::deleteFront()
{
  if (front == -1)
  {
    printf("DEQueue is empty\n");
    return -1;
  }
  int data = arr[front];
  if (front == rear) // last element
  {
    front = rear = -1;
  }
  else if (front == size - 1)
  {
    front = 0;
  }
  else
  {
    front++;
  }
  return data;
}
void DEQueue::insertRear(int val)
{
  if ((front == 0 && rear == size - 1) || (front == rear + 1))
  {
    printf("DEQueue is full\n");
    return;
  }
  if (front == -1) // first element
  {
    front = rear = 0;
  }
  else if (rear == size - 1)
  {
    rear = 0;
  }
  else
  {
    rear++;
  }
  arr[rear] = val;
}
int DEQueue::deleteRear()
{
  if (front == -1)
  {
    printf("DEQueue is empty\n");
    return -1;
  }
  int data = arr[rear];
  if (front == rear) // last element
  {
    front = rear = -1;
  }
  else if (rear == 0)
  {
    rear = size - 1;
  }
  else
  {
    rear--;
  }
  return data;
}
void DEQueue::display()
{
  if (front == -1)
  {
    printf("DEQueue is empty\n");
    return;
  }
  int i = front;
  while (true)
  {
    printf("%d ", arr[i]);
    if (i == rear)
      break;
    i = (i + 1) % size;
  }
  printf("\n");
}