#include "linkedl.h"

void display(struct Node *head) // O(n) both time and space
{
  if (head != NULL)
  {
    printf("%d ", head->data);
    display(head->next);
  }
}

// count number of nodes
int count(struct Node *head) // O(n) time
{
  int res = 0;
  while (head->next != NULL)
  {
    res++;
    head = head->next;
  }
  return res + 1;
}

// recursively count
int recCount(struct Node *head)
{
  if (head == NULL)
    return 0;
  return recCount(head->next) + 1;
}

// sum all nodes values
int sum(struct Node *head)
{
  int sum = 0;
  while (head != NULL)
  {
    sum += head->data;
    head = head->next;
  }
  return sum;
}

int recSum(struct Node *head)
{
  if (head == NULL)
    return 0;
  return recSum(head->next) + head->data;
}

int maxElement(struct Node *head)
{
  int res = INT_MIN;
  while (head != NULL)
  {
    if (head->data > res)
    {
      res = head->data;
    }
    head = head->next;
  }
  return res;
}
void insertAtBeginning(struct Node **head, int data)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  if (temp == NULL)
  {
    printf("failed to allocate memory\n");
    return;
  }
  temp->data = data;
  temp->next = *head;
  *head = temp;
}

void insertAtEnd(struct Node **head, int data)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  if ((*head) == NULL) // empty list
  {
    *head = temp;
    return;
  }
  struct Node *p = *head;
  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = temp;
}

void insertAtPosition(struct Node **head, int data, int position) // 0-based indexing
{
  int cnt = count(*head);
  if (position < 0 || position > cnt)
  {
    printf("Invalid position\n");
    return;
  }
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  if (position == 0)
  {
    temp->next = *head;
    *head = temp;
    return;
  }
  struct Node *p = *head;
  for (int i = 0; i < position - 1 && p != NULL; i++)
  {
    p = p->next;
  }
  if (p == NULL)
  {
    printf("invalid position\n");
    free(temp);
    return;
  }
  temp->next = p->next;
  p->next = temp;
}

void deleteFirst(struct Node **head)
{
  if ((*head) == NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void deleteLast(struct Node **head)
{
  if ((*head) == NULL) // empty list
  {
    printf("List is empty\n");
    return;
  }
  if ((*head)->next == NULL) // only one node
  {

    (*head) = NULL;
  }
  struct Node *p = *head;
  while (p->next->next != NULL)
  {
    p = p->next;
  }
  struct Node *temp = p->next;
  free(temp);
  p->next = NULL;
}

void deleteAtPosition(struct Node **head, int position) // 0-based indexing
{
  // Need two pointers
  struct Node *p = *head;
  struct Node *q = NULL;
  for (int i = 0; i < position - 1 && p != NULL; i++)
  {
    q = p;
    p = p->next;
  }
  if (p == NULL)
  {
    printf("Invalid position\n");
    return;
  }

  q->next = p->next;
  free(p);
}

int isSorted(struct Node *head)
{
  int x = INT_MIN;
  struct Node *p = head;
  while (p != NULL)
  {
    if (x > p->data)
    {
      return 0;
    }
    x = p->data;
    p = p->next;
  }
  return 1;
}

void reverseList(struct Node **head)
{
  struct Node *prev = NULL;
  struct Node *current = *head;
  struct Node *next = NULL;
  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}
struct Node *mergeSortedList(struct Node *first, struct Node *second) // TODO: how to do in place merging?
{
  struct Node *result = NULL;
  while (first != NULL && second != NULL)
  {
    if ((first)->data <= (second)->data)
    {
      insertAtEnd(&result, (first)->data);
      first = (first)->next;
    }
    else
    {
      insertAtEnd(&result, (second)->data);
      second = (second)->next;
    }
  }
  while ((first) != NULL)
  {
    insertAtEnd(&result, (first)->data);
    first = (first)->next;
  }
  while ((second) != NULL)
  {
    insertAtEnd(&result, (second)->data);
    second = (second)->next;
  }
  return result;
}
int hasCycle(struct Node *head)
{
  struct Node *slow = head;
  struct Node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      return 1;
    }
  }
  return 0;
}