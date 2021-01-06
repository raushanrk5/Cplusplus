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

void delete_given(int ele){
  struct node *temp, *del_ele = head;

  if(del_ele != NULL && del_ele->data==ele){
      head = head->next;
      free(del_ele);
      return;
  }

  while(del_ele != NULL && del_ele->data!=ele){
    temp = del_ele;
    del_ele = del_ele->next;
  }

  if(del_ele == NULL)
  {
    cout<<"The element is not there!\n";
    return;
  }

  temp->next = del_ele->next;
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

  int num;
  cout<<"Enter the element to be deleted : ";
  cin>>num;
  delete_given(num);
  printll(head);

  return 0;
}



// void delete_given(int ele){
//   struct node *del_ele, *temp = head;
//   if(del_ele != NULL && del_ele->data==ele){
//    head = head->next;
//    free(del_ele);
//    return;
//   }
  // if(del_ele == NULL)
  // {
  // cout<<"The element is not there!\n";
  // return;
  // }
//   while(temp->next->data!=ele){
//     temp = temp->next;
//   }
//   del_ele = temp->next;
//   temp->next = del_ele->next;
//   free(del_ele);
// }
