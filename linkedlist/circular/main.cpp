#include "circularLinkedList.cpp"

int main()
{
  CircularLinkedList cl1;
  cl1.insert(1);
  cl1.insert(2);
  cl1.insert(3);
  cl1.insert(4);
  cl1.insert(5);
  cl1.display();
  cl1.deleteNode(3);
  cl1.display();
  return 0;
}