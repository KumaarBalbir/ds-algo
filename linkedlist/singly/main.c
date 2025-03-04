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
  for (int i = 0; i < 5; i++)
  {
    insertAtEnd(&head, arr[i]);
  }
  int arr2[] = {1, 3, 4, 5, 9, 12};
  struct Node *head2 = NULL;
  for (int i = 0; i < 6; i++)
  {
    insertAtEnd(&head2, arr2[i]);
  }
  // display(head);
  // puts("\n");
  // deleteFirst(&head);
  // deleteLast(&head);
  // display(head);
  // puts("\n");
  // insertAtBeginning(&head, 5);
  // display(head);
  // puts("\n");
  // reverseList(&head);
  display(head);
  puts("\n");
  display(head2);
  puts("\n");
  struct Node *ans = mergeSortedList(head, head2);
  display(ans);

  return 0;
}
