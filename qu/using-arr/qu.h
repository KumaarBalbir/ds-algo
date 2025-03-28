#ifndef QU_H
#define QU_H

#include <iostream>

struct Queue
{
  int front, rear, capacity;
  int *queue;
  Queue(int c);
  ~Queue();
  void Enqueue(int val);
  int Dequeue();
  void display();
};

#endif
