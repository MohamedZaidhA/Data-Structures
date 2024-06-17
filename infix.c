//infix to postfix
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
int priority(char c);
int main()
{
    Node*list;
    list=malloc(sizeof(Node));
    list->next=NULL;
    top=list;
    char exp[max];
    printf("Enter expression :");
    scanf("%s",exp);
    printf("The postfix expression is :");
    for(int i=0;i<strlen(exp);i++)
    {
      if(exp[i]>='a'&&exp[i]<='z')
       printf("%c",exp[i]);
      else if(exp[i]=='(')
       push(exp[i]);
      else if(exp[i]==')')
      {
        while(top->e!='(')
        {
            printf("%c",top->e);
            pop();
        }
        pop();
      }
      else
      {
            while(priority(exp[i])<=priority(top->e) && top->next!=NULL)
            {
              printf("%c",top->e);
              pop();
            }
            push(exp[i]);
      }
    }
    while(top->next!=NULL)
    {
        if(top->e!='('&&top->e!=')')
        {
        printf("%c",top->e);
        pop();
        }
    }
}
void push(char x)
{
Node*newnode;
newnode=malloc(sizeof(Node));
newnode->e=x;
newnode->next=top;
top=newnode;
}
void pop()
{
    top=top->next;
}
int priority(char x)
{
  int p;
 switch(x)
 {
 case'(':p=0;
         break;
 case'+':
 case'-':p=1;
         break;
 case'*':
 case'/':
 case'%':p=2;
         break;
 case'^':p=3;
        break;
 }
 return p;
}