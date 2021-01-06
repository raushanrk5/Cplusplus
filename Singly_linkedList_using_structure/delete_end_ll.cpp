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

void delete_end(){
  struct node *del_ele, *temp = head;

  if(head == NULL){
      return;
  }

  if(head->next==NULL){
      delete head;
      return;
  }

  while(temp->next->next!=NULL){
    temp = temp->next;
  }
  del_ele = temp->next;
  temp->next = NULL;
  free(del_ele);
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

  delete_end();
  //delete_end();
  cout<<"\n";
  printll(head);

  return 0;
}
