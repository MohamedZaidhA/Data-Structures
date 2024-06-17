#include<stdio.h>
#include<stdlib.h>
    int n,x;
    typedef struct node Node;
    struct node
    {
      int e;
      struct node * p;
    };
    void display(Node * ptr)
    {  
    while(ptr!=NULL)
    {
        printf("%d ",ptr->e);
        ptr=ptr->p;
        
    }
    free(ptr); 
    }
    void insert(Node * list)
    {
        Node *newnode;
        newnode=malloc(sizeof(list));
        printf("Enter element to be inserted\n");
        scanf("%d",&x);
        newnode->e=x;
        newnode->p=list;
        list->p=newnode;
        display(list);
    }
int main()
{
    printf("Enter number of elements\n");
    scanf("%d",&n);
    Node a[n];
    a[n-1].p=NULL;
    for(int i=0;i<n;i++)
    {   
        printf("enter element %d\n",i+1);
        scanf("%d",&a[i].e);
        if(i<n-1){
            a[i].p=&a[i+1];
        }
    }
    int opt;
    printf("Menu\n1.Insert element\n2.Delete element\n3.Display elements\n4.exit\n");
    scanf("%d",&opt);
       while(1){
        switch (opt)
        {
          case 1:insert(&a[0]);
                 break;
          case 2:
                 break;
          case 3:display(&a[0]);
                 break;
          case 4:exit(0);
          default:printf("invalid option!!\n");
                  break;
        }
    }
    return 0;
}