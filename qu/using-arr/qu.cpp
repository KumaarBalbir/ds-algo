#include "qu.h"

Queue::Queue(int c)
{
  front = rear = -1;
  capacity = c;
  queue = new int[c];
}

Queue::~Queue()
{
  delete[] queue;
}

void Queue::Enqueue(int val)
{
  if ((rear + 1) % capacity == front)
  {
    printf("Q is full\n");
    return;
  }
  if (front == -1) // first element
  {
    front = 0;
  }
  rear = (rear + 1) % capacity;
  queue[rear] = val;
}

int Queue::Dequeue()
{
  int data;
  if (front == -1)
  {
    printf("Q is empty\n");
    return -1;
  }
  if (front == rear) // last element
  {
    data = queue[front];
    front = rear = -1;
  }
  else
  {
    data = queue[front];
    front = (front + 1) % capacity;
  }
  return data;
}

void Queue::display()
{
  if (front == -1)
  {
    printf("Q is empty\n");
    return;
  }
  int i = front;
  while (true)
  {
    printf("%d ", queue[i]);
    if (i == rear)
    {
      break;
    }
    i = (i + 1) % capacity;
  }
  printf("\n");
}
