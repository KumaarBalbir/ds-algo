#include "qu.cpp"

int main()
{
  Queue q(5);
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  q.Enqueue(4);
  q.Enqueue(5);
  q.display();
  q.Dequeue();
  q.display();
}