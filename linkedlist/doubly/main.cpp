#include "doublyLinkedList.cpp"
int main()
{
  DoublyLinkedList dl;
  dl.insertFront(1);
  dl.insertFront(2);
  dl.insertFront(3);
  dl.insertFront(4);
  dl.insertFront(5);
  dl.insertBack(10);
  dl.displayForward();
  dl.displayBackward();
  dl.deleteNode(3);
  dl.deleteNode(5);
  dl.deleteNode(10);
  dl.displayForward();
  dl.displayBackward();
  return 0;
}