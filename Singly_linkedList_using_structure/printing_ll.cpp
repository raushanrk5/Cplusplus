using namespace std;
#include<iostream>

Struct node
{
  int data;
  Struct node * next;
}
Struct node * head;

void printll(struct node * head)
{
  while(head)
  {
    cout<<head->data;
    head = head->next;
    if(head != NULL)
        cout<<"->";
  }
}
