#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
class Node
{
public:
  Node *prev;
  Node *next;
  int data;
  Node(int value);
};

class DoublyLinkedList
{
private:
  Node *head;
  Node *tail;

public:
  DoublyLinkedList();
  void insertFront(int value);
  void insertBack(int value);
  void deleteNode(int value);
  void displayForward();
  void displayBackward();
};

#endif // DOUBLY_LINKED_LIST_H