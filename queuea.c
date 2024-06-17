#include<stdio.h>
#include<stdlib.h>
int front=0,back=0;
int isfull(int n);
int isempty();
void enqueue(int arr[]);
void dequeue(int arr[]);
void display(int arr[]);
int main()
  {
	int opt,size;
	printf("Enter the limit of queue: ");
	scanf("%d",&size);
while(1)
   {
	int arr[100];
	printf("MENU\n1.Enqueue\n2.Dequeue\n3.DISPLAY\n4.EXIT\nSelect your otion: ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:if(!isfull(size))
               {enqueue(arr);
               display(arr);}
               else
               printf("Queue overflow!!!\n");
		       break;
		case 2:dequeue(arr);
               display(arr);
		       break;
		case 3:display(arr);
		       break;				
		case 4:exit(0);
		default:printf("INVALID OPTION!!\n");
		        break;
	}
   }
  }
int isfull(int n)
{
if(back<n)
   return 0;
else
   return 1;
}
int isempty()
{
    if(back>0)
    return 0;
    else
    return 1;
}
void enqueue(int arr[])
{
    printf("Enter the element: ");
	scanf("%d",&arr[back]);
    back++;
}
void dequeue(int arr[])
{
 if(!isempty()){
  for(int i=1;i<=back;i++)
    {
     arr[i-1]=arr[i];
    }
  back--;}
  else
  printf("Queue underflow!!\n");
}
void display(int arr[])
{
if(!isempty()){    
for(int i=0;i<back;i++)
{
    printf("%d ",arr[i]);
}
printf("\n");}
else
printf("The Queue is Empty!!\n");
}