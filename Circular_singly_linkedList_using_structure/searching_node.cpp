using namespace std;
#include<iostream>

struct node{
  int data;
  struct node * next;
};
struct node * head;

void insert_beg(){
  int val;
  cout<<"\nEnter the node, you want to insert: ";
  cin>>val;
  struct node * new_node;
  new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = val;

  if(head == NULL){
    head = new_node;
    new_node->next = head;
    cout<<"\nnode inserted";
  }

  else if(head->next==NULL){
    new_node->next = head;
    head->next = new_node;
    head = new_node;
    cout<<"\nNode inserted";
  }

  else{
    struct node * temp = head;
    while(temp->next!=head){
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    head = new_node;
    cout<<"\nNode inserted";
  }
}

void search_node(){
  int search_ele, flag=0, pos = 0;
  cout<<"\nEnter the element, u want to search for: ";
  cin>>search_ele;

  if(head == NULL)
    cout<<"\nThere is no element in the list to search over";

  else if(head->data == search_ele)
      cout<<"\nThe elment is at head position of the list";

  else
  {
      struct node * temp = head;
      do{
        if(temp->data == search_ele){
          cout<<"\nThe element is found at location "<<pos+1;
          flag = 0;
        }
        else
          flag = 1;
        pos++;
        temp = temp->next;
      }while(temp!=head);
      if(flag == 1)
        cout<<"The element is not found";
  }
}

void printll(){
  struct node * ptr = head;
  if(head == NULL)
    cout<<"\nNothing to print";
  else{
    cout<<"\nPrinting nodes...";
    while(ptr->next!=head){
      cout<<ptr->data<<"->";
      ptr = ptr->next;
    }
    cout<<ptr->data;
  }
}

int main(){
  insert_beg();
  insert_beg();
  printll();
  search_node();
  insert_beg();
  printll();
  search_node();
  insert_beg();
  printll();
  return 0;
}
