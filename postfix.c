//Evaluation of postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
struct node
{
    int e;
    struct node*next;
};
typedef struct node Node;
Node*top;
void push(int x);
void pop();
int main()
{
    Node*list;
    list=malloc(sizeof(Node));
    list->next=NULL;
    top=list;
    char exp[max];
    int e,a,b,c;
    printf("Enter expression :");
    scanf("%s",exp);
    for(int i=0;i<strlen(exp);i++)
    {
      if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
      {
        a=top->e;
        pop();
        b=top->e;
        pop();
        switch (exp[i])
        {
        case '+':c=a+b;
                 push(c);
                 break;
        case '-':c=a-b;
                 push(c);
                 break;
        case '*':c=a*b;
                 push(c);
                 break;
        case '/':c=a/b;
                 push(c);
                 break;
        }
      }
      else
      {
        printf("Enter the value of %c:",exp[i]);
        scanf("%d",&e);
        push(e);
      }
    }
   printf("The result is %d",top->e);
}
void push(int c)
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