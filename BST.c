#include <stdio.h>
#include <stdlib.h>
 struct node
 {
     int value;
   struct node * bigvalue ,* smallvalue;
 };
 int comparison=0;
struct  node * create_node(int data)
  { struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    ptr -> value = data;
    ptr -> bigvalue = NULL;
    ptr -> smallvalue = NULL;
    return ptr;
  }
  void insert_node(struct node ** root ,struct node * child)
  { if(*root==NULL)
      *root =child;
    else if(((*root) -> value )>=(child -> value))
    {
     insert_node(&((*root) -> smallvalue),child);
    }
    else
        insert_node(&((*root) -> bigvalue),child);
  }
  struct node * search_value(struct node * root,int data)
  { if(root == NULL){
      comparison++;
      return NULL;
      }
    else if (root -> value == data){
            comparison++;
        return root;
        }
    else if (root -> value >= data ){
    comparison++;
    search_value(root ->smallvalue ,data);
    }
    else{
     comparison++;
     search_value(root -> bigvalue ,data);
    }
}
int main()
{ struct node * ptrroot = NULL;
  struct node * child = NULL;
   int input=0;
    while (1)
    { printf("please Enter Your elements & Enter negative to exit \n");
      scanf("%i",&input);
      if(input<0)
            break;
      child=create_node(input);
      insert_node(&ptrroot,child);
    }
    printf("Please Enter value to search for : \n");
    scanf("%i",&input);
    struct node * found=search_value(ptrroot,input);
    if(found == NULL)
        printf("Your Value Wasn't found \n");
    else
        printf("Your Value is found after %i comparison \n",comparison);
    return 0;
}
