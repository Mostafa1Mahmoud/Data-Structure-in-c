#include <stdio.h>
#include <stdlib.h>
typedef struct Nodes
{
    int data;
   struct Nodes* pre;
   struct Nodes* next;
}node;
node* new_node(int data)
{
    node* head=(node*)malloc(sizeof(node));
    head->data=data;
    head->next=NULL;
    head->pre=NULL;
    return head;
}
void insert_front(node** head,node* temp)
{
    if(*head==NULL)*head=temp;
    else
    {
      temp->next=*head;
      (*head)->pre=temp;
      temp->pre=NULL;
      *head=temp;
    }
    return;
}
void insert_back(node** head,node* temp)
{
    if(*head==NULL)*head=temp;
    while(((*head)->next!=NULL))
    {
        *head=(*head)->next;
    }
    (*head)->next=temp;
    temp->pre=*head;
    temp->next=NULL;
    return;
}
void insert_position(node** head,node* temp,int pos)
{
    if(pos==1||(pos>1&&*head==NULL))
    {
      temp->next=*head;
      temp->pre=NULL;
      *head=temp;
      return;
    }
    node* temp1=*head;
    pos-=2;
    while(pos--&&(temp1->next!=NULL))
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
    temp->pre=temp1;
    return;
}
void deleteBypos(node** head,int pos)
{
    if(pos==1)
    {
        *head=(*head)->next;
        free((*head)->pre);
        return;
    }
    node* temp=*head;
    pos-=2;
    while(pos--&&(temp->next==NULL))
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    if(temp->next->next!=NULL)temp->next->next->pre=temp;
    free(temp->next);
    return;
}
void deleteByvalue(node** head,int value)
{
    if((*head)->data==value)
    {
        *head=(*head)->next;
        free((*head)->pre);
        return;
    }
    else if((*head)->next==NULL)return;
    else
        deleteByvalue(&((*head)->next),value);
}
void print(node* head,int i)
 {
    if(head==NULL)return;
    else
    {
        printf("your %d st element is %d\n",i,(head)->data);
        i++;
        print(head->next,i);
    }
    return;
}
int main()
{
    node* head=NULL;
    node* temp=NULL;
    while(1)
    {   int input[2]={0};
        printf("Enter the element You Want to insert and the position of it or enter -1 to if finished \n");
        scanf("%d",&input[0]);
        if(*input<0)break;
        scanf("%d",input+1);
        temp=new_node(input[0]);
        insert_position(&head,temp,input[1]);
    }
    print(head,1);
    while(1)
    {int input=0;
      printf("Enter The Position of the element you want to remove or enter -1 to end \n");
      scanf("%d",&input);
      if(input<0)break;
      deleteBypos(&head,input);
      print(head,1);
    }
    while(1)
        {
      int input =0;
      printf("Enter value You want to delete or -1 to end\n");
      scanf("%d",&input);
      if(input<0)break;
      deleteByvalue(&head,input);
      print(head,1);
        }
    return 0;
}
