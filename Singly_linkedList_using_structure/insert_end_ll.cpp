using namespace std;
#include<iostream>

struct node
{
  int data;
  struct node * next;
};
struct node * head;

void insert_end(int ele)
{
  struct node * temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = ele;

  struct node * last;
  last = head;

  if(head==NULL)
  {
    head = temp;
    return;
  }

  while(last->next)
  {
    last = last->next;
  }
   last->next = temp;
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
      insert_end(arr[i]);
  }

  printll(head);
  return 0;
}
