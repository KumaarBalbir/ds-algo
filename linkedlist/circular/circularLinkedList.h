#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>

class Node
{
public:
  int data;
  Node *next;
  Node(int value);
};
class CircularLinkedList
{
private:
  Node *tail;

public:
  CircularLinkedList();
  void insert(int value);
  void display();
  void deleteNode(int value);
};

#endif // CIRCULAR_LINKED_LIST_H
