#ifndef LINKED_L_H
#define LINKED_L_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
  int data;
  struct Node *next; // self referencial structure
};

void display(struct Node *head);
void insertAtBeginning(struct Node **head, int data);
void insertAtEnd(struct Node **head, int data);
void insertAtPosition(struct Node **head, int data, int position);
int count(struct Node *head);
int recCount(struct Node *head);
int sum(struct Node *head);
int recSum(struct Node *head);
int maxElement(struct Node *head);
void deleteFirst(struct Node **head);
void deleteLast(struct Node **head);
void deleteAtPosition(struct Node **head, int position);
int isSorted(struct Node *head);
void reverseList(struct Node **head);
#endif // LINKED_L.h