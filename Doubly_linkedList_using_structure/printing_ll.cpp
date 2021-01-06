using namespace std;
#include<iostream>

struct node
{
  int data;
  struct node * next;
}
struct node * head;

void printll(struct node * head)
{
  sstruct node * temp;
  if(head == NULL)
   {
       printf("\nnothing to print");
   }

  temp = head;
  while(temp)
  {
    cout<<temp->data;
    temp = temp->next;
    if(temp != NULL)
        cout<<"->";
  }
}
