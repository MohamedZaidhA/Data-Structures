#include<stdio.h>
#include<stdlib.h>
struct node
{
	int e;
	struct node*next;
	struct node*prev;
};
typedef struct node Node;
int isempty(Node *list);
Node *find(Node * list,int x);
void display(Node*list);
void insbeg(Node * list,int x);
void insmid(Node * list,int x,int p);
void insend(Node * list,int x);
void delbeg(Node *list);
void delmid(Node *list,int p);
void delend(Node *list);
int main()
{
int ch,x,p;
Node *list;
list=malloc(sizeof(Node));
list->next=NULL;
while(1){
printf("1.insert element at begining\n2.insert element at middle\n3.insert element at end\n4.delete element at begining\n5.delete element at middle\n6.delete element at end\n7.display elements\n8.Find an element\n9.exit\nEnter your choice: ");
scanf("%d",&ch);
switch(ch)
  {
case 1: printf("Enter element to be inserted: ");
        scanf("%d",&x);
        insbeg(list,x);
        display(list);
        break;
case 2: printf("Enter element to be inserted: ");
        scanf("%d",&x);
		printf("Enter element next to which the element to be inserted:\n");
		scanf("%d",&p);
        insmid(list,x,p);
        display(list);
        break;
case 3: printf("Enter element to be inserted: ");
        scanf("%d",&x);
        insend(list,x);
        display(list);
        break;				
case 4: delbeg(list);
        display(list);
        break;
case 5: printf("Enter element to be deleted: ");
		scanf("%d",&p);
        delmid(list,p);
        display(list);
        break;
case 6: delend(list);
        display(list);
        break;		        
case 7: display(list);
        break;
case 8: printf("Enter the element to be found: ");
        scanf("%d",&ch);
        if(find(list,ch)!=NULL)
		{
		printf("The element is found!!\n");	
		}
		else
		{
		printf("The element is not found!!\n");	
		}
        break;
case 9: exit(0);
default:printf("Invalid input\n");
        break;
  }
 }
}
int isempty(Node *list)
{
	if(list->next==NULL)
    return 1;
    else
	return 0;
}
Node *find(Node * list,int x)
   {
	if(isempty(list))
	{
	printf("The list is empty!!\n");
	return NULL;
	}
	else{
	Node * position=list->next;
	while(position!=NULL)
	{
	if(position->e==x)
	{break;}	
	position=position->next;
	}
	if(position!=NULL)
	{return position;}
	else
	{  printf("The element is not found in the list.\n");
	   return NULL;
	}
   }
 }
void display(Node*list)
{
	Node * position=list;
	if(!isempty(list)){
	printf("The elements are:\n");
	while(position->next!=NULL)
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
void insbeg(Node * list,int x)
{	
 Node * newnode;
 newnode=malloc(sizeof(Node));
 newnode->e=x;
 newnode->next=list->next;
 if(!isempty(list))
 {newnode->next->prev=newnode;}
 list->next=newnode;
 newnode->prev=list;
}
void insmid(Node * list,int x,int p)
{
 Node * newnode;
 Node * position;
 position=list;
 newnode=malloc(sizeof(Node));
 newnode->e=x;
 position=find(list,p);
 if(position!=NULL)
 {
 newnode->next=position->next;
 position->next=newnode;
 newnode->prev=position;
 newnode->next->prev=newnode;
 }	
}
void insend(Node * list,int x)
{	
 Node * newnode;
 Node * position;
 position=list;
 newnode=malloc(sizeof(Node));
 newnode->e=x;
 while(position->next!=NULL)
	{
	  position=position->next;
	}
 newnode->next=NULL;
 position->next=newnode;
 newnode->prev=position; 
}
void delbeg(Node *list)
{
if(!isempty(list))
{
list->next=list->next->next;
if(list->next!=NULL)
list->next->prev=list;
 }	
}
void delmid(Node *list,int p)
{
	if(!isempty(list))
	{
	Node*position;
	position=list;
	position=find(list,p);
	if(position!=NULL)
	{
	position->prev->next=position->next;
	position->next->prev=position->prev;
	}
  }
}
void delend(Node *list)
{
	if(!isempty(list))
	{
	Node*position;
	position=list;
	while(position->next->next!=NULL)
	{position=position->next;}
	 position->next=NULL;
  }
}