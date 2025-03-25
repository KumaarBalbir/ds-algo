#include "qu.h"

Queue::Queue(int c)
{
  front = rear = 0;
  capacity = c;
  queue = new int[c];

}

Queue::~Queue()
{
  delete[] queue;
}

void Queue::Enqueue(int val)
{
  if(capacity == rear)
    {
      printf("Q is full\n");
      

    }else
    {
      queue[rear] = val;
      rear++;
    }
}

int Queue::Dequeue()
{
  if(front == rear)
    {
      printf("Q is empty\n");
      return -1;
    }
  int data = queue[front-1];
  // shift the data towards front
  for(int i=0;i<rear-1;i++)
    {
      queue[i] = queue[i+1];
    }
  rear--;
  return data;
}

void Queue::display()
{
  if(front == rear)
    {
      printf("Q is empty\n");
    }else
    {
      for(int i=front;i<rear;i++)
	{
	  if(i!=rear-1)
	  printf("%d <-- ",queue[i]);
	  else
	    printf("%d",queue[i]);
	}
    }
}

	  
  
