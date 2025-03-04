#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
};
class LinkedList
{
private:
  Node *first;

public:
  LinkedList()
  {
    first = NULL;
  }
  LinkedList(int arr[], int n);
  ~LinkedList(); // delete entire linked list
  void Display();
  void Insert(int idx, int val);
  int Delete(int idx);
  int Length();
};

LinkedList::LinkedList(int arr[], int n)
{
  Node *t, *last;
  first = new Node;
  first->data = arr[0];
  first->next = NULL;
  last = first;
  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}
LinkedList::~LinkedList()
{
  Node *p = first;
  while (first != NULL)
  {
    first = first->next;
    delete p;
    p = first;
  }
}
void LinkedList::Display()
{
  Node *p = first;
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}
int LinkedList::Length()
{
  Node *p = first;
  int len = 0;
  while (p != NULL)
  {
    len++;
    p = p->next;
  }
  return len;
}
void LinkedList::Insert(int idx, int val)
{
  Node *t, *p = first;
  if (idx < 0 || idx > Length())
  {
    cout << "Invalid index" << endl;
    return;
  }
  t = new Node;
  t->data = val;
  t->next = NULL;
  if (idx == 0)
  {
    first = t;
  }
  else
  {
    for (int i = 0; i < idx - 1; i++)
      p = p->next;
    t->next = p->next;
    p->next = t;
  }
}
int LinkedList::Delete(int idx)
{
  Node *p, *q = NULL;
  int x = -1;
  if (idx < 1 || idx > Length())
  {
    return -1;
  }
  if (idx == 1)
  {
    p = first;
    first = first->next;
    x = p->data;
    delete p;
  }
  else
  {
    p = first;
    for (int i = 0; i < idx - 1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
  }
  return x;
}

int32_t main()
{
  int ar[] = {1, 2, 3, 4, 5, 6};
  LinkedList l1(ar, 6);
  l1.Display();
  return 0;
}
