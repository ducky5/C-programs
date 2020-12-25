#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int n;
  struct node *next;
}
node;

void insert(int n);
bool search(int n);
void freeLlist(void);

node *head = NULL;//head of the linked list

int main(void)
{
  //inserting data into list
  for (int i = 0; i < 10; i++)
    insert(i);
  //printing list data
  node *ptr = head;
  for (int i = 0; i < ptr->n; ptr = ptr->next)
    printf("%i\n", ptr->n);
  //free list from memory
  freeLlist();
}

void insert(int n)
{
  node *new = malloc(sizeof(node));//allocate enough memory for and store new node
  //check for NULL
  if (new == NULL)
    exit(1);
  //fill node data
  new->n = n;
  new->next = NULL;
  //attach node to the linked list
  new->next = head;//point node pointer to first node
  head = new;//then safely update head to point at new node
}

bool search(int n)
{
  node *ptr = NULL;//temporary pointer
  //do the following if ptr = head != NULL
  while ((ptr = head) != NULL)
  {
    if (ptr->n == n)//check if node data == n
      return true;
    ptr = ptr->next;//update ptr to point at next node, the i++ of linked lists
  }
  return false;//return if ptr = head = NULL, also works if data isn't found in list/ptr->next = NULL
}

void freeLlist(void)
{
  node *ptr = NULL;//temporary pointer
  //do if ptr = head != NULL
  while ((ptr = head) != NULL)
  {
    head = head->next;//points head at next node
    free(ptr);//frees current node without breaking the chain, hence usage of a temporary pointer
  }
}
