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
  struct node * temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = ele;
  temp->next = head;
  head = temp;
}

void insertAfter(int prev_num, int num){
  struct node * temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = num;

  struct node * prev;
  prev = head;
  if (head==NULL){
    cout<<"The list can't be empty";
  }

  while(prev->data!=prev_num){
    prev = prev->next;
  }

  temp->next=prev->next;
  prev->next=temp;
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
  cout<<"Enter the no. after which we have to insert: ";
  cin>>req;
  cout<<"Enter the number to be inserted : ";
  cin>>num;
  insertAfter(req,num);
  cout<<"\nafter inserting"<<num<<" : ";
  printll(head);
  return 0;
}
