#include "circularLinkedList.h"

Node::Node(int value)
{
  data = value;
  next = nullptr;
}

CircularLinkedList::CircularLinkedList()
{
  tail = nullptr;
}

void CircularLinkedList::insert(int value)
{
  Node *newNode = new Node(value);
  if (!tail)
  {
    tail = newNode;
    tail->next = tail;
  }
  else
  {
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
  }
}

void CircularLinkedList::display()
{
  if (!tail)
  {
    std::cout << "empty list\n";
    return;
  }
  Node *temp = tail->next;
  do
  {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  } while (temp != tail->next);
  std::cout << "(circular)\n";
}
void CircularLinkedList::deleteNode(int value)
{
  if (!tail)
    return;
  Node *current = tail->next;
  Node *prev = tail;
  do
  {
    if (current->data == value)
    {
      if (current == tail)
      {
        if (tail == tail->next)
        {
          delete tail;
          tail = nullptr;
        }
        else
        {
          prev->next = tail->next;
          delete tail;
          tail = prev;
        }
      }
      else
      {
        prev->next = current->next;
        delete current;
      }
      return;
    }
    prev = current;
    current = current->next;
  } while (current != tail->next);
}
