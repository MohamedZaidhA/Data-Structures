#include<stdio.h>
int n;
void print(int a[])
{
  printf("The array is now: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void insb(int a[])
{
   int num; 
  for(int i=n;i>=0;i--)
     {
         a[i]=a[i-1];
     }
     printf("Enter the element to be inserted: ");
     scanf("%d",&num);
     a[0]=num;
     n++;  
}
void insm(int a[])
{
   int num,pos;
   printf("element should be insterted at ?:");
   scanf("%d",&pos);
   printf("the element to be insterted:");
   scanf("%d",&num);
   for(int i=n;i>=pos;i--)
    {
    a[i]=a[i-1];
    }
    a[pos-1]=num;
    n++;
}
void inse(int a[])
{
    int num;
    printf("Enter the element to be inserted:");
    scanf("%d",&num);
    a[n]=num;
    n++;
}
void delb(int a[])
{
for(int i=1;i<n;i++)
{
  a[i-1]=a[i];
}
n--;
}
void delm(int a[])
{
     int pos;
     printf("At what position the element should be deleted:");
     scanf("%d",&pos);
     for(int i=pos;i<n;i++)
     {
         a[i-1]=a[i];
     }
     n--;
}
void dele(int a[])
{
  n--;
}


int main()
{
    int chs;
    printf("Enter number of elements in your array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter your elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);  
    }
     while(1)
    {
        printf("\n1.insert begining\n2.instert middle\n3.instert end\n4.delete begining \n5.delete middle\n6.delete end\n7.print\n");
        scanf("%d",&chs);
        switch (chs)
        {
          case 1:insb(a);
				print (a);
                 break;
          case 2:insm(a);
				print (a);
                 break;
          case 3:inse(a);
				print (a);
                 break;
          case 4:delb(a);
                 print(a);
                 break;
          case 5:delm(a);
				print (a);
                 break;
          case 6:dele(a);
				print (a);
                 break;
          case 7:print(a);
                 break;
          case 8:return 0;       
          default:printf("invalid\n");
                  break;
         }
    }
}