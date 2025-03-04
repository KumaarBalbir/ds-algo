#include "doublyCircular.h"
Node::Node(int value)
{
  data = value;
  next = nullptr;
  prev = nullptr;
}

DoublyCircular::DoublyCircular()
{
  head = nullptr;
}

void DoublyCircular::insertFront(int value)
{
  Node *newNode = new Node(value);
  if (!head)
  {
    head = newNode;
    head->next = head;
    head->prev = head;
  }
  else
  {
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    head = newNode;
  }
}

void DoublyCircular::insertBack(int value)
{
  Node *newNode = new Node(value);
  if (!head)
  {
    head = newNode;
    head->next = head;
    head->prev = head;
  }
  else
  {
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
  }
}

void DoublyCircular::deleteNode(int value)
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
    if (head == head->next)
    {
      delete head;
      head = nullptr;
    }
    else
    {
      head->next->prev = head->prev;
      head->prev->next = head->next;
      current = current->next;
      delete head;
      head = current;
    }
  }
  else
  {
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
  }
}

void DoublyCircular::search(int value)
{
  if (!head)
  {
    return;
  }
  Node *current = head;
  do
  {
    if (current->data == value)
    {
      std::cout << "Found\n";
      return;
    }
    current = current->next;
  } while (current != head);
  std::cout << "Not Found\n";
}

void DoublyCircular::updatePosition(int position, int value)
{
  if (!head)
  {
    return;
  }
  Node *current = head;
  do
  {
    if (position == 0)
    {
      current->data = value;
      return;
    }
    current = current->next;
    position--;
  } while (current != head);
}

void DoublyCircular::updateValue(int oldValue, int newValue)
{
  if (!head)
  {
    return;
  }
  Node *current = head;
  do
  {
    if (current && current->data == oldValue)
    {
      current->data = newValue;
    }
    current = current->next;
  } while (current != head);
}

void DoublyCircular::displayList()
{
  if (!head)
  {
    std::cout << "empty list\n";
    return;
  }
  Node *current = head;
  do
  {
    std::cout << current->data << " <-> ";
    current = current->next;
  } while (current != head);
  std::cout << "(circular)\n";
}

void DoublyCircular::reverseList()
{
  if (!head || head->next == head)
    return;

  Node *prev = head;
  Node *current = head->next;
  Node *next = nullptr;
  do
  {
    next = current->next;
    current->next = prev;
    current->prev = next;
    prev = current;
    current = next;
  } while (current != head);

  head->next = prev;
  head = prev;
}