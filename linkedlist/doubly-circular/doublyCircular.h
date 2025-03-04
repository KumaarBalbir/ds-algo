#ifndef DOUBLY_CIRCULAR_H
#define DOUBLY_CIRCULAR_H

#include <iostream>

class Node
{
public:
  int data;
  Node *next;
  Node *prev;
  Node(int value);
};
/*
 * Class Declaration
 */
class DoublyCircular
{
private:
  Node *head;

public:
  DoublyCircular();
  void insertFront(int value);
  void insertBack(int value);
  void deleteNode(int value);
  void search(int value);
  void updatePosition(int position, int value);
  void updateValue(int oldValue, int newValue);
  void displayList(); // display forward
  void reverseList();
  // void sortList();
};

#endif // DOUBLY_CIRCULAR_H