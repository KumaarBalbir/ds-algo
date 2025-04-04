#include "qu.cpp"

int main()
{
  Queue q;
  q.Enqueue(10);
  q.Enqueue(20);
  q.Enqueue(30);
  q.display();
  printf("Dequeued: %d\n", q.Dequeue());
  q.display();
  return 0;
}