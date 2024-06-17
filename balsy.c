//BALANCING SYMBOLS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
struct node
{
    char e;
    struct node*next;
};
typedef struct node Node;
Node*top;
void push(char x);
void pop();
int main()
{
 Node*list;
 list=malloc(sizeof(Node));
 list->next=NULL;
 top=list;
 char exp[max];
 printf("Enter expression:\n");
 scanf("%s",exp);
 for(int i=0;i<strlen(exp);i++)
 {
   if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
   {
    push(exp[i]);
   }
   else if(exp[i]==')'||exp[i]=='}'||exp[i]==']') 
   {
   if(top->next==NULL)
   {
     printf("Missing opening symbol!!");
     exit(0);
   } 
   else if(exp[i]==')'&&top->e!='(')
   {
     printf("Symbol mismatched!!!");
     exit(0);
   }
   else if(exp[i]=='}'&&top->e!='{')
   {
     printf("Symbol mismatched!!!");
     exit(0);
   }
   else if(exp[i]==']'&&top->e!='[')
   {
     printf("Symbol mismatched!!!");
     exit(0);
   }
   else
    pop();
   }
  }
if(top->next==NULL)
printf("the symbols are balanced!!");
else
printf("Missing closing symbol!!");
}
void push(char c)
{
Node*newnode;
newnode=malloc(sizeof(Node));
newnode->e=c;
newnode->next=top;
top=newnode;
}
void pop()
{
    top=top->next;
}