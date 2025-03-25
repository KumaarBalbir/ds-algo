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
  if((rear+1)%capacity == front)
    {
      printf("Q is full\n");
      

    }else
    {
      queue[rear] = val;
      rear = (rear+1)%capacity;
    }
}

int Queue::Dequeue()
{
  if(front == rear)
    {
      printf("Q is empty\n");
      return -1;
    }
  int data = queue[front];
  front = (front+1)%capacity;
  
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

	  
  
