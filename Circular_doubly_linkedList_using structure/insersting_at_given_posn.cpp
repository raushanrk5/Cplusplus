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

void insert_end(){
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
        cout<<"\nNode inserted";
      }
    }
}

void insert_given(){
    int val,pos;
    struct node * temp;
    struct node * new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node==NULL)
      cout<<"\nOverflow";

    else{
      cout<<"\nEnter the position, where you want to insert a new node: ";
      cin>>pos;

      if(head == NULL){
        cout<<"There is no element in the linked list!";
      }

      else{
        int position = 1;
        temp = head;

        int count = 1;
        while(temp->next!head){
          count++;
          temp = temp->next;
        }

        if(pos>count){
          cout<<"\nPosition not found!";
        }

        else{
          while(position!=pos){
            temp = temp->next;
            position++;
          }

          if(temp==NULL){
              cout<<"value not found";
          }

          else if(temp->next == head){
            insert_end();
          }

          else{
            cout<<"\nEnter the value, you want to insert: ";
            cin>>val;
            new_node->data = val;
            new_node->prev = temp;
            new_node->next = temp->next;
            temp->next = new_node;
            temp->next->prev = new_node;
            cout<<"\nNode inserted";
          }
        }
      }
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
   insert_beg();
   printll();
   insert_beg();
   printll();
   insert_beg();
   printll();
   insert_beg();
   printll();
   insert_given();
   printll();
   insert_given();
   printll();
   insert_given();
   printll();
  return 0;
}
