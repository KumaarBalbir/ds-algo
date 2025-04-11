#ifndef QU_H
#define QU_H

#include <stack>
using namespace std;
class Queue
{
private:
  stack<int> e_st;
  stack<int> d_st;

public:
  void enqueue(int x);
  int dequeue();
};

#endif