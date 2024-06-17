#include<stdio.h>
#include<stdlib.h>
struct node
{
int e;
struct node*next;
};
typedef struct node Node;
Node * end;
int isempty(Node * list);
void display(Node*list);
Node *findnext(Node * list,int x);
Node *findprev(Node * list,int x);
void insbeg(Node * list,int x);
void insmid(Node * list,int x);
void insend(Node * list,int x);
void delbeg(Node *list);
void delmid(Node *list);
void delend(Node *list);
int main()
{
int ch,x;
Node *list;
list=malloc(sizeof(Node));
list->next=NULL;
end=list;
while(1){
printf("1.insert element at begining\n2.insert element at middle\n3.insert element at end\n4.delete element at begining\n5.delete element at middle\n6.delete element at end\n7.display elements\n8.Find an element\n9.exit\nEnter your choice: ");
scanf("%d",&ch);
switch(ch)
  {
case 1: printf("Enter element to be inserted:\n");
        scanf("%d",&x);
        insbeg(list,x);
        display(list);
        break;
case 2: printf("Enter element to be inserted:\n");
        scanf("%d",&x);
        insmid(list,x);
        display(list);
        break;
case 3: printf("Enter element to be inserted:\n");
        scanf("%d",&x);
        insend(list,x);
        display(list);
        break;				
case 4: delbeg(list);
        display(list);
        break;
case 5: delmid(list);
        display(list);
        break;
case 6: delend(list);
        display(list);
        break;                
case 7: display(list);
        break;
case 8: printf("Enter the element to be found: ");
        scanf("%d",&ch);
        if(findnext(list,ch)!=NULL)
		{
		printf("The element is found!!\n");	
		}
		else
		{
		printf("The element is not found!!\n");	
		}
        break;
case 9: exit(0);
default:printf("Invalid input");
        break;
  }
 }
}
int isempty(Node * list)
{
if(list->next==NULL)
    return 1;
else
	return 0;
}
void display(Node*list)
{
	Node * position=list;
	if(!isempty(list)){
	printf("The elements are:\n");
	while(position->next!=list)
	{
		position=position->next;
		printf("%d ",position->e);
	}
	printf("\n");
	}
 else
 {
 	printf("the list is empty!!!\n");
 }
}
Node *findnext(Node * list,int x)
   {
	if(isempty(list))
	{
	printf("The list is empty!!\n");
	return NULL;
	}
	else{
	Node * position=list->next;
	while(position!=list)
	{
	if(position->e==x)
	{break;}	
	position=position->next;
	}
    return position;
   }
 }
 Node *findprev(Node * list,int x)
   {
	if(isempty(list))
	{
	printf("The list is empty!!\n");
	return NULL;
	}
	else{
	Node * position=list;
	while(position->next!=list)
	{
	if(position->next->e==x)
	{break;}	
	position=position->next;
	}
    return position;
 }
}
void insbeg(Node * list,int x)
{	
 Node * newnode;
 newnode=malloc(sizeof(Node));
 newnode->e=x;
 if(isempty(list))
 { newnode->next=list;}
 else
 {newnode->next=list->next;}
 list->next=newnode;
}
void insmid(Node * list,int x)
{
 int p;	
 Node * newnode;
 Node * position;
 position=list;
 newnode=malloc(sizeof(Node));
 newnode->e=x;
 printf("next to which element the element should be inserted:");
 scanf("%d",&p);
 position=findnext(list,p);
 newnode->next=position->next;
 position->next=newnode;
}
void insend(Node * list,int x)
{	
 Node * newnode;
 Node * position;
 position=list;
 newnode=malloc(sizeof(Node));
 newnode->e=x;
 while(position->next!=list)
	{
	  position=position->next;
	}
 newnode->next=position->next;
 position->next=newnode;	
}
void delbeg(Node *list)
{
   if(!isempty(list))
    list->next=list->next->next;	
}
void delmid(Node *list)
{
	if(!isempty(list))
	{
	Node*position;
	int pos;
	position=list;
	printf("what element should be deleted:");
	scanf("%d",&pos);
	position=findprev(list,pos);
	position->next=position->next->next;
	}
}
void delend(Node *list)
{
	if(!isempty(list))
	{
	Node*position;
	position=list;
	while(position->next->next!=list)
	{position=position->next;}
	 position->next=list;
  }
}