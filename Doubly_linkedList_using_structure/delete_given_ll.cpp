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

void delete_given(int val)
{
  if(head==NULL)
    cout<<"There is no element in the list";

  struct node * temp, *del_node;
  del_node = head;

  if(del_node != NULL && del_node->data==val){
    head = head->next;
    head->prev = NULL;
    free(del_node);
    return;
  }

  while(del_node != NULL && del_node->data!=val){
    temp = del_node;
    del_node = del_node->next;
  }

  if(del_node == NULL)
  {
    cout<<"The element is not there!\n";
    return;
  }


  if(del_node->next==NULL){
    temp->next = NULL;
  }

  else{
    temp->next = del_node->next;
    del_node->next->prev = temp;
  }

  free(del_node);
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

  int num;
  cout<<"Enter the element to be deleted : ";
  cin>>num;
  delete_given(num);
  printll(head);

  return 0;
}
