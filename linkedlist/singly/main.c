#include <stdio.h>
#include "linkedl.c"

int main(int argc, char **argv)
{

  // concept1: Three ways to check if the pointer p is pointing to some node..
  // 1. if(p != NULL)
  // 2. if(p!=0)
  // 3. if(p)

  // concept2: To check if p is last node...
  // if(p->next == NULL || p->next==0 || !p-next)
  int arr[] = {2, 4, 6, 8, 10};
  struct Node *head = NULL;
  struct Node *tail = NULL;
  for (int i = 0; i < 5; i++)
  {
    insertAtEnd(&head, arr[i]);
  }
  display(head);
  puts("\n");
  deleteFirst(&head);
  deleteLast(&head);
  display(head);
  puts("\n");
  insertAtBeginning(&head, 5);
  display(head);
  puts("\n");

  return 0;
}
