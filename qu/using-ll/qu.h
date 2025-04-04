#pragma once
#include <iostream>

struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int value) : data(value)
  {
    prev = nullptr;
    next = nullptr;
  }
};

class Queue
{
private:
  Node *front;
  Node *rear;

public:
  Queue();
  ~Queue();
  void Enqueue(int val);
  int Dequeue();
  void display();
};
