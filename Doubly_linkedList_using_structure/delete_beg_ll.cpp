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

void delete_beg()
{
  if(head==NULL)
    cout<<"There is no element in the list";

  else if(head->next == NULL){
    head = NULL;
    free(head);
    cout<<"\n node deleted!";
  }

  else{
    struct node * temp;
    temp = head;
    while (temp->next!=head) {
      temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
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

  delete_beg();
  cout<<"\n";
  printll(head);

  return 0;
}
