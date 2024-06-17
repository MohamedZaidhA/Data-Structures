//C program pass arrays to function
#include<stdio.h>
#include<stdlib.h>
int b[100][100],k=0;
void print(int a[],int n)
{
    int i;
    printf("The array is now: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nThe number of elements in the array is %d\n",n);
}
int sort(int a[],int n)
{
       int opt,i,j,t;
    while(1){
    printf("1.Ascending order\n2.Desending order\n");
    scanf("%d",&opt);
      for(int j=0;j<n;j++)
        {
            b[k][j]=a[j];
        }
     
        switch (opt)
        {
          case 1:for(i=0;i<n;i++)
                   {
                     for(j=i+1;j<n;j++)
                     {
                        if(a[i]>a[j])
                        {
                            t=a[i];
                            a[i]=a[j];
                            a[j]=t;
                        }
                     }
                   }
                   return 0; 
          case 2:  for(i=0;i<n;i++)
                   {
                     for(j=i+1;j<n;j++)
                     {
                        if(a[i]<a[j])
                        {
                            t=a[i];
                            a[i]=a[j];
                            a[j]=t;
                        }
                     }
                   } 
                   return 0;       
          default:printf("invalid option!!\n");
                  break;
        }
        } 
}
void undo(int a[],int n)
{
if(k<0)
{
    printf("\nNo previous history\n");
}
else{    
for(int j=0;j<n;j++)
{
a[j]=b[k][j];
    }     
  }
}
int main()
{
    int n,i,opt;
    printf("This program will undo the changes done to an array\n");
    printf("Enter number of elements in your array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter your elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);  
    }
    while(1){
    printf("\n1.Sort the array\n2.Undo\n3.Exit\nEnter option:");
    scanf("%d",&opt);
     switch (opt)
        {
          case 1:sort(arr,n);
                 print(arr,n);
                 k++;
                 break;
          case 2:k--;
                 undo(arr,n);
                 print(arr,n);
                 break;
          case 3:exit(0);
          default:printf("invalid option!!\n");
                  break;
        }
    }
    return 0;
}