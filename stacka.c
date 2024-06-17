#include<stdio.h>
#include<stdlib.h>
int top=-1,size;
void display(int arr[])
{
	if(top>=0)
	{
		for(int i=top;i>=0;i--)
		{
			printf("%d\n",arr[i]);
		}
	}
	else
		printf("The Stack is empty!!\n");
}
void push(int arr[])
{
	top++;
	printf("Enter the element: ");
	scanf("%d",&arr[top]);
	display(arr);
}
void pop(int arr[])
{
	if(top>=0)
	{
		top--;
		display(arr);
	}
    else
		printf("Underflow\n");
}
int main()
  {
	int opt;
	printf("Enter the limit of stack: ");
	scanf("%d",&size);
while(1)
   {
	int arr[100];
	printf("MENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nSelect your otion: ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:if(top<size-1)
			   push(arr);
			   else
			   printf("Overflow\n");
		       break;
		case 2:pop(arr);
		       break;
		case 3:display(arr);
		       break;				
		case 4:exit(0);
		default:printf("INVALID OPTION!!");
		        break;
	}
   }
  }