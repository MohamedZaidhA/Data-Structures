#include<stdio.h>
#include<stdlib.h>
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
int insert(int arr[],int *n)
{
    int opt,num,pos;
    while(1){
    printf("1.At the begining\n2.In the middle\n3.At the end\n4.Return\n");
     scanf("%d",&opt);
        switch (opt)
        {
          case 1:for(int i=*n;i>=0;i--)
                   {
                     arr[i]=arr[i-1];
                   }
                   printf("Enter the element to be insert:");
                   scanf("%d",&num);
                   arr[0]=num;
                   *n=*n+1;
                   break;
          case 2:  printf("At what position the element should be inserted:");
                   scanf("%d",&pos);
                   printf("\nEnter the element should be inserted:");
                   scanf("%d",&num);
                   for(int i=*n;i>=pos;i--)
                   {
                    arr[i]=arr[i-1];
                   }
                   arr[pos-1]=num;
                   *n=*n+1;
                   break;
          case 3:printf("Enter the element to be inserted:");
                 scanf("%d",&num);
                 arr[*n]=num;
                 *n=*n+1;
                 break;
          case 4:return 0;       
          default:printf("invalid option!!\n");
                  break;
        }
         if(opt<4)  
        {print(arr,*n);}
        }

}
void search(int arr[],int n)
{
  int num,flag=0,i;  
  printf("Enter the element to be searched:");
  scanf("%d",&num);
  for(i=0;i<n;i++)
  {
    if(arr[i]==num)
    {
        printf("The element is found to be at %d position of the array\n",i+1);
        flag=1;
    }
 }
  if(flag==0){
              printf("The element is not found in the array\n");
             }
}
int delete(int arr[],int *n)
{
    int opt,pos;
    while(1){
    printf("1.At the begining\n2.In the middle\n3.At the end\n4.Return\n");
     scanf("%d",&opt);
        switch (opt)
        {
          case 1:for(int i=1;i<=*n;i++)
                   {
                     arr[i-1]=arr[i];
                   }
                   *n=*n-1;
                   break;
          case 2:  printf("At what position the element should be deleted:");
                   scanf("%d",&pos);
                   for(int i=pos;i<=*n;i++)
                   {
                    arr[i-1]=arr[i];
                   }
                   *n=*n-1;
                   break;
          case 3:  *n=*n-1;
                  break;
          case 4:return 0;       
          default:printf("invalid option!!\n");
                  break;
        }
      if(opt<4)  
        {print(arr,*n);}
        }

}  
int sort(int a[],int n)
{
       int opt,i,j,t;
    while(1){
    printf("1.Ascending order\n2.Desending order\n");
     scanf("%d",&opt);
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

int main()
{
    int n,i,opt;
    printf("Enter number of elements in your array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter your elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);  
    }
    while(1)
    {
        printf("1.insert an element\n2.Delete an element\n3.Search an element\n4.Sort the array\n5.Print\n6.Exit\n");
        scanf("%d",&opt);
        switch (opt)
        {
          case 1:insert(arr,&n);
                 n++;
                 break;
          case 2:delete(arr,&n);
                 break;
          case 3:search(arr,n);
                 break;
          case 5:print(arr,n);
                 break;
          case 4:sort(arr,n);
                 print(arr,n);
                 break;       
          case 6:exit(0);
          default:printf("invalid option!!\n");
                  break;
        }
    }
    return 0;
}
