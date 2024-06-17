//C program with self referential structures
#include<stdio.h>
int main()
{
    int i,n,m,flag=0;
    printf("This program will show who sits before and after you\n");
    printf("Enter number seats :");
    scanf("%d",&n); 
struct seat
{
    int num;
    char name[20];
    struct seat* prev_link;
    struct seat* next_link;
}s[n];
s[0].prev_link = NULL;
s[n-1].next_link = NULL;
for(i=0;i<n;i++)
{
    printf("Enter number %d : ",i+1);
    scanf("%d",&s[i].num);
    printf("Enter name %d : ",i+1);
    scanf("%s",&s[i].name);
    if(i>0)
    {
       s[i].prev_link=&s[i-1];
    }
    if(i<n-1)
    {
      s[i].next_link=&s[i+1];
    }

}
printf("To get information about your seat\n") ;   
printf("Enter your seat number:");
scanf("%d",&m);
  for(i=0;i<n;i++)
  {
    if(s[i].num==m)
    {
      flag=1;  
      break;
    }
  }
  if(flag==1)
  {
    if(i==0)
    {
        printf("Your seat is before %s's seat",s[i].next_link->name);
    }
    else  if(i==n-1)
    {
        printf("Your seat is behind %s's seat",s[i].prev_link->name);
    }
    else
    {
        printf("Your seat is behind %s's seat and before %s's seat",s[i].prev_link->name,s[i].next_link->name);
    }
  }
  else
  {
    printf("There is no such seat in the given number");
  }
 return 0;
}

