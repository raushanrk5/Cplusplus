using namespace std;
#include<iostream>

struct node{
  int data;
  struct node * next;
  struct node * prev;
};
struct node * head;

void insert_beg(){
    int num;
    struct node * new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node==NULL)
      cout<<"\nOverflow";

    else{
      cout<<"\nEnter the value, you want to insert: ";
      cin>>num;
      new_node->data = num;

      if(head == NULL){
        head = new_node;
        new_node->next = head;
        new_node->prev = head;
      }

      else{
        struct node * temp;
        temp = head;
        while(temp->next != head){
          temp = temp->next;
        }

        new_node->prev = temp;
        new_node->next = head;
        head->prev = new_node;
        temp->next = new_node;
        head = new_node;
        cout<<"\nNode inserted";
      }
    }
}

void delete_end(){
  if(head==NULL)
    cout<<"\nNothing to delete";

  else if(head->next==head){
    head = NULL;
    free(head);
  }

  else{
    struct node * temp, * t;
    temp = head;
    while(temp->next!=head){
      t = temp;
      temp = temp->next;
    }
    cout<<"\nDeleting the node...";
    t->next = head;
    head->prev = t;
    free(temp);
  }
}

void printll(){
  struct node * ptr;
  ptr = head;
  if(head==NULL){
    cout<<"\nNothing to print";
  }

  else{
    cout<<"\nPrinting values...";
    while(ptr->next != head){
      cout<<ptr->data<<"->";
      ptr = ptr->next;
    }
    cout<<ptr->data;
  }
}

int main(){

   delete_end();
   printll();
   delete_end();
   printll();

  return 0;
}
