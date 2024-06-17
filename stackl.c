#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node* prev;
};
typedef struct node Node;
Node*top;
void display()
{
    Node * position;
    position=top;
    if(position->prev==NULL)
    {
        printf("The stack is empty!!\n");
    }
    else
    {
        while(position->prev!=NULL)
        {
            printf("%d\n",position->element);
            position=position->prev;
        }
    }
}
void push()
{
    Node*newnode;
    newnode=malloc(sizeof(Node));
    printf("Enter the element to be inserted: ");
    scanf("%d",&newnode->element);
    newnode->prev=top;
    top=newnode;

}
void pop()
{
   if(top->prev==NULL)
   {
    printf("Underflow!!\n");
   }
   else
   {
    top=top->prev;
   }
}
void Top()
{
   if(top->prev==NULL)
   {
    printf("Underflow!!\n");
   }
   else
   {
    printf("The top element in the stack is: %d\n",top->element);
   }
}
int main()
{
   int opt;
   top=malloc(sizeof(Node));
   top->prev=NULL;
   while(1){
    printf("MENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.TOP\n5.EXIT\nSelect your otion: ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:push();
		       display();
		       break;
		case 2:pop();
		       display();
		       break;
		case 3:display();
		       break;
        case 4:Top();
               break;       				
		case 5:exit(0);
		default:printf("INVALID OPTION!!");
		        break;
	}
   }
}