#include <stdio.h>
#include <stdlib.h>



 typedef struct Nodes
 {
     int data;
    struct Nodes* next;
 }node;
 void insert(node** head,int data,int pos)
 {
     node* temp=(node*)malloc(sizeof(node*));
     temp->data=data;
     temp->next=NULL;
     if(pos<1)
     {
         printf("The position must be integer or the value will be put at the front\n");
         pos=1;
     }
     if(pos==1||(pos>1&&*head==NULL))
     {
         temp->next=*head;
         (*head)=temp;
         return;
     }
     pos-=2;
     node* temp1=*head;
     while(pos--&&(temp1->next!=NULL))
     {
         temp1=temp1->next;
     }
     temp->next=temp1->next;
     temp1->next=temp;
     return;
 }
 void deleteByvalue(node** head,int value)
 {   node* temp=*head;
     if((*head)->data==value)
     {
         *head=(*head)->next;
         free(temp);
         return;
     }
     else if(temp==NULL)
    {
        return;
    }
    else
    {
        deleteByvalue(&((*head)->next),value);
    }
 }
 void delete_node(node** head,int pos)
 {
     node* temp=*head;
     if(*head==NULL)
     {
        printf("There is no data \n");
        return;
     }
     if(pos==1)
     {
         *head=temp->next;
         free(temp);
         return;
     }
     pos-=2;
     while(pos--&&(temp->next!=NULL))
     {
         temp=temp->next;
     }
     if(temp->next==NULL)
     {
         return;
     }
     node* temp1=temp->next;
     temp->next=temp1->next;
     free(temp1);
     return;
 }
 void reverse_nodes(node** head)
 {node* current=*head;
  node* pre=NULL;
  if((current->next==NULL)||current==NULL)return;
   while(current!=NULL)
   { node* next=current->next;
     current->next=pre;
     pre=current;
     current=next;
   }
     *head=pre;
     return;
 }
 void reverse_nodeByre(node** head,node* temp)
 {
     if(temp->next==NULL)
     {
         *head=temp;
         return;
     }
    reverse_nodeByre(head,(temp->next));
     temp->next->next=temp;
     temp->next=NULL;
     return;
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
int reverse_print(node* head)
{
    int i=0;
    if(head==NULL)return (++i);
    i=reverse_print(head->next);
    printf("your %d st element is %d\n",i,(head)->data);
    return (++i);
}
int main()
{   node* head=NULL;
    while(1)
    {   int input[2]={0};
        printf("Enter the element You Want to insert and the position of it or enter -1 to if finished \n");
        scanf("%d",&input[0]);
        if(*input<0)break;
        scanf("%d",input+1);
        insert(&head,input[0],*(input+1));
    }
    print(head,1);
    while(1)
    {int input=0;
      printf("Enter The Position of the element you want to remove or enter -1 to end \n");
      scanf("%d",&input);
      if(input<0)break;
      delete_node(&head,input);
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
    printf("Your Elements reversed are:\n");
    reverse_nodeByre(&head,head);
    print(head,1);
    return 0;
}
