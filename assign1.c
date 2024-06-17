//C program using pointers and arrays
#include<stdio.h>
int main(){
int n,i,opt,*ptr,sum=0,sq;
    printf("The square of the given numbers will be added\n");
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter your elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);  
    }
    ptr=arr;
    for(i=0;i<n;i++)
    {
      for(int j=0;j<2;j++)
      {
        sq=(*ptr)*(*ptr);
      }
      sum=sum+sq;
      ptr++;    
    }
    printf("The sum of square of given numbers is %d",sum);
    return 0;
    }