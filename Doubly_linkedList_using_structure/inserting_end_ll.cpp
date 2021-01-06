using namespace std;
#include<iostream>

struct node
{
  int data;
  struct node * next;
  struct node * prev;
};
struct node * head;

void insert_end(int ele)
{
  struct node * new_node, * temp;
  new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = ele;
  new_node->next = NULL;

  if(head==NULL){
    new_node->prev = NULL;
    head = new_node;
    return;
  }

  temp = head;
  while(temp->next){
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->prev = temp;

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
