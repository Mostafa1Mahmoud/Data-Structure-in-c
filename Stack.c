#include <stdio.h>
#include <stdlib.h>
typedef struct Cell
{
    int data;
    struct Cell* next;
}cell;
void push(cell** top,int value)
{
    cell* temp=(cell*)malloc(sizeof(cell));
    temp->data=value;
    temp->next=*top;
    *top=temp;
    return;
}
void pop(cell** top)
{
    if(*top==NULL)return;
    cell* temp=*top;
    *top=temp->next;
    free(temp);
    return;
}
 void print(cell* top,int i)
 {
    if(top==NULL)return;
    else
    {
        printf("your %d st element is %d\n",i,top->data);
        i++;
        print(top->next,i);
    }
    return;
}
int main()
{   cell* top=NULL;
        while(1)
    {   int input=0;
        printf("Enter the element You Want to push it or enter -1 to if finished \n");
        scanf("%d",&input);
        if(input<0)break;
        push(&top,input);
    }
    print(top,1);
    return 0;
}
