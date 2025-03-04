#include "doublyCircular.cpp"
int main()
{
  DoublyCircular dcll;
  dcll.insertFront(1);
  dcll.insertFront(2);
  dcll.insertFront(3);
  dcll.insertFront(4);
  dcll.insertFront(5);
  dcll.insertBack(10);
  dcll.displayList();
  dcll.deleteNode(3);
  dcll.deleteNode(5);
  dcll.deleteNode(10);
  dcll.displayList();
  dcll.search(4);
  dcll.search(3);
  dcll.reverseList();
  dcll.displayList();
  dcll.updatePosition(2, 100); // update position 2 to 100
  dcll.displayList();
  dcll.updateValue(100, 200); // update value 100 to 200
  dcll.displayList();
  return 0;
}