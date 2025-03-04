#include "doublyLinkedList.h"

Node::Node(int value)
{
  data = value;
  prev = nullptr;
  next = nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
  head = nullptr;
  tail = nullptr;
}

void DoublyLinkedList::insertFront(int value)
{
  Node *newNode = new Node(value);
  if (!head)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void DoublyLinkedList::insertBack(int value)
{
  Node *newNode = new Node(value);
  if (!tail)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

void DoublyLinkedList::deleteNode(int value)
{
  if (!head)
  {
    return;
  }
  Node *current = head;
  while (current && current->data != value)
  {
    current = current->next;
  }
  if (!current)
    return;
  if (current == head)
  {
    head = head->next;
    if (head)
    {
      head->prev = nullptr;
    }
    else
    {
      tail = nullptr;
    }
  }
  else if (current == tail)
  {
    tail = tail->prev;
    tail->next = nullptr;
  }
  else
  {
    current->prev->next = current->next;
    current->next->prev = current->prev;
  }
  delete current;
}

void DoublyLinkedList::displayForward()
{
  Node *temp = head;
  while (temp)
  {
    std::cout << temp->data << " <-> ";
    temp = temp->next;
  }
  std::cout << "NULL\n";
}

void DoublyLinkedList::displayBackward()
{
  Node *temp = tail;
  while (temp)
  {
    std::cout << temp->data << " <-> ";
    temp = temp->prev;
  }
  std::cout << "NULL\n";
}