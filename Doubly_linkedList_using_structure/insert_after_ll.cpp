using namespace std;
#include<iostream>

struct node
{
  int data;
  struct node * next;
  struct node * prev;
};
struct node * head;

void insert_beg(int ele)
{
  struct node * temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = ele;
  temp->next = head;
  temp->prev = NULL;

  if(head!=NULL){
    head->prev = temp;
    head = temp;
    return;
  }
  head = temp;
}

void insert_after(int req, int ele)
{
  struct node * new_node, * temp;
  new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = ele;

  temp = head;
  while(temp->data!=req){
    temp = temp->next;
  }
  new_node->next = temp->next;
  new_node->prev = temp;
  temp->next = new_node;
  temp->next->prev = new_node;

  if(head==NULL)
    cout<<"The list shoudn't be empty";
    return;
}

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
  cout<<"\nEnter the no. after which we have to insert: ";
  cin>>req;
  cout<<"Enter the number to be inserted : ";
  cin>>num;
  insert_after(req,num);
  cout<<"\nafter inserting "<<num<<" : ";
  printll(head);

  return 0;
}
