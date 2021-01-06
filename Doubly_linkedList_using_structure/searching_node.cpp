using namespace std;
#include<iostream>

struct node {
  int data;
  struct node * next;
  struct node * prev;
};
struct node * head;

void insert_beg(){
  int val;
  cout<<"\nEnter the element, you want to insert: ";
  cin>>val;
  struct node * new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = val;
  new_node->prev = NULL;

  if(head==NULL){
    head = new_node;
    new_node->next == NULL;
    cout<<"\nNode inserted";
  }

  else{
    new_node->next = head;
    head-> prev = new_node;
    head = new_node;
    cout<<"\nNode inserted";
  }
}

void search_node(){
  int search_ele,flag=0,pos=0;
  cout<<"\nEnter the element, you want to search: ";
  cin>>search_ele;

  if(head==NULL)
    cout<<"\nThere is no elements in the list to search over!";

  else if(head->data == search_ele)
      cout<<"\n The element is found at head* position";

  else{
    struct node * ptr = head;
    while(ptr){
      if(ptr->data==search_ele){
        cout<<"\nThe elementis found at location "<<pos+1;
        flag = 0;
      }
      else
        flag = 1;
      pos++;
      ptr = ptr->next;
    }
    if(flag == 1)
      cout<<"\nElement not found";
  }
}

void printll(){
  if(head==NULL)
    cout<<"\nNothing to print";

  else{
    cout<<"\nPrinting elements...";
    struct node * temp = head;
    while(temp){
      cout<<temp->data;
      temp = temp->next;
      if(temp!=NULL)
        cout<<"->";
    }
  }
}

int main(){
    insert_beg();
    printll();
    insert_beg();
    insert_beg();
    printll();
    search_node();
    insert_beg();
    printll();
    search_node();
    return 0;
}
