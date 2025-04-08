#ifndef __DQU_H__
#define __DQU_H__
#include <iostream>
class DEQueue
{
private:
  int front;
  int rear;
  int size;
  int *arr;

public:
  DEQueue(int size);
  ~DEQueue();
  void insertFront(int val);
  void insertRear(int val);
  int deleteFront();
  int deleteRear();
  void display();
};

#endif // __DQU_H__