using namespace std;
#include<iostream>

struct node
{
  int data;
  struct node * next;
};
struct node * head;

void insert_beg(int ele)
{
  struct node * temp = head;
  struct node * new_node;
  new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = ele;

  if(head == NULL){
    new_node->next = new_node;
    head = new_node;
  }

  else{
      while(temp->next!=head){
        temp = temp->next;
      }
      temp->next = new_node;
      new_node->next = head;
      head = new_node;
  }
}

void insert_end(int ele)
{

    struct node * temp = head;
    struct node * new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = ele;

    if(head == NULL){
      new_node->next = new_node;
      head = new_node;
    }

    else{
        while(temp->next!=head){
          temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

void insertAfter(int prev_num, int num){
  struct node * temp;
  temp = (struct node *)malloc(sizeof(struct node));

  struct node * prev;
  prev = head;
  if (head==NULL){
    cout<<"The list can't be empty";
  }

  while(prev->data!=prev_num){
    prev = prev->next;
  }

  if(prev->next = head)
    insert_end(num);

  else{
    temp->data = num;
    temp->next=prev->next;
    prev->next=temp;
  }
}

void printll(struct node * head)
{
  struct node * temp = head;
  if(head == NULL)
   {
       printf("\nnothing to print");
   }
  else
  {
    do
    {
      cout<<temp->data<<" ";
      temp = temp->next;
    }while(temp!=head);
  }
}

int main()
{
int n,i;

  cout<<"Enter the no. of elements: ";
  cin>>n;
  int arr[n];

  cout<<"Enter the elements to be inserted : ";
  for(i=0;i<n;i++){
      cin>>arr[i];
      insert_beg(arr[i]);
  }

  printll(head);
  int req,num;
  cout<<"Enter the no. after which we have to insert: ";
  cin>>req;
  cout<<"Enter the number to be inserted : ";
  cin>>num;
  insertAfter(req,num);
  cout<<"\nafter inserting "<<num<<" : ";
  printll(head);
  return 0;
}
