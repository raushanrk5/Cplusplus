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
  struct node * temp;
  temp = head;
  if(head == NULL)
   {
       printf("\nnothing to print");
   }

  while(temp->next!=head)
  {
    cout<<temp->data;
    temp = temp->next;
    if(temp != NULL)
        cout<<"->";
  }
}
