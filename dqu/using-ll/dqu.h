#ifndef DQU_H
#define DQU_H

#include <iostream>

typedef struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int value);
};

class DEQueue
{
public:
  Node *front;
  Node *rear;

  DEQueue(int size);
  ~DEQueue();
  void insertFront(int val);
  void insertRear(int val);
  int deleteFront();
  int deleteRear();
  void display();
};

#endif