#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node*next;
};
typedef struct node Node;
Node*rear;
Node*front;
void display()
{
    Node * position;
    position=front;
    if(position->next==NULL)
    {
        printf("The stack is empty!!");
    }
    else
    {
        while(position->next!=NULL)
        {
            position=position->next;
            printf("%d ",position->element);
        }
        printf("\n");
    }
}
void enqueue()
{
    Node*newnode;
    newnode=malloc(sizeof(Node));
    printf("Enter the element to be inserted: ");
    scanf("%d",&newnode->element);
    newnode->next=NULL;
    rear->next=newnode;
    rear=newnode;

}
void dequeue()
{
   Node*position;
   position=rear;
   if(front->next==NULL)
   {
    printf("Underflow!!\n");
   }
   else
   {
    front=front->next;
   }
}
int main()
{
   int opt;
   front=malloc(sizeof(Node));
   front->next=NULL;
   rear=front;
   while(1){
    printf("MENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\nSelect your otion: ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:enqueue();
		       display();
		       break;
		case 2:dequeue();
		       display();
		       break;
		case 3:display();
		       break;
        case 4:exit(0);
		default:printf("INVALID OPTION!!");
		        break;
	}
   }
}