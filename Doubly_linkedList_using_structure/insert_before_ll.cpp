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

void insert_before(int req, int ele)
{
  struct node * new_node;
  new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = ele;


  if(head==NULL){
    cout<<"The list shouldn't be empty!";
    return;
  }

  else if(head->next == NULL){
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }

  else{
    struct node * temp, * t;
    temp = head;
    while(temp->data!=req){
      temp = temp->next;
    }

   // temp->prev->next = new_node;
    if(temp->prev!=NULL){
     temp->prev->next = new_node;
     new_node->prev = temp->prev;
    }

    else{
      new_node->prev = NULL;
      head = new_node;
    }
    temp->prev = new_node;
    new_node->next = temp;
   // new_node->prev = temp->prev;


  }
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
  cout<<"\nEnter the no. before which we have to insert: ";
  cin>>req;
  cout<<"Enter the number to be inserted : ";
  cin>>num;
  insert_before(req,num);
  cout<<"\nafter inserting "<<num<<" : ";
  printll(head);

  return 0;
}
