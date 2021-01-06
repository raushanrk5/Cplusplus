using namespace std;
#include <iostream>

struct node {
  int data;
  struct node * next;
  struct node * prev;
}

struct node * head;

void printll()
{
    struct node *ptr;  
    ptr=head;
    if(head == NULL)
    {
        cout<<"\nnothing to print";
    }
    else
    {
        cout<<"\n printing values ... \n";
        while(ptr -> next != head)
        {
            cout<<ptr -> data<<"->";
            ptr = ptr -> next;
        }
        cout<<ptr -> data;
    }
}
