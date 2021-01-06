using namespace std;
#include<iostream>

Struct node
{
  int data;
  Struct node * next;
}
Struct node * head;

def detect_cycle(){
  struct node * big, *small;
  big=small=head;
  if (head->next==NULL)
    return 0;
  while(big->next!=NULL){
    big = big->next->next;
    small = small->next;
    if (big==small)
      rerturn 1;
    else
      return 0;
  }
}
