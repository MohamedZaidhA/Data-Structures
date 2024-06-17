//C program for complete Array ADT operations
#include<stdio.h>
#include<stdlib.h>
int n;
void print(int a[])
{
    int i;
    printf("The array is now: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nThe number of elements in the array is %d\n",n);
}
int insert(int arr[])
{
    int opt,num,pos;
    while(1){
    printf("1.At the begining\n2.In the middle\n3.At the end\n4.Return\n");
     scanf("%d",&opt);
        switch (opt)
        {
          case 1:for(int i=n;i>=0;i--)
                   {
                     arr[i]=arr[i-1];
                   }
                   printf("Enter the element to be insert:");
                   scanf("%d",&num);
                   arr[0]=num;
                   n++;
                   break;
          case 2:  printf("At what position the element should be inserted:");
                   scanf("%d",&pos);
                   printf("Enter the element should be inserted:");
                   scanf("%d",&num);
                   for(int i=n;i>=pos;i--)
                   {
                    arr[i]=arr[i-1];
                   }
                   arr[pos-1]=num;
                   n++;
                   break;
          case 3:  printf("Enter the element to be inserted:");
                   scanf("%d",&num);
                   arr[n]=num;
                   n++;
                   break;
          case 4:  return 0;       
          default:printf("invalid option!!\n");
                  break;
        }
        if(opt<4)  
        {print(arr);}
        }

}
void search(int arr[])
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
int delete(int arr[])
{
    int opt,pos;
    while(1){
    printf("1.At the begining\n2.In the middle\n3.At the end\n4.Return\n");
     scanf("%d",&opt);
        switch (opt)
        {
          case 1:for(int i=1;i<n;i++)
                   {
                     arr[i-1]=arr[i];
                   }
                   n--;
                   break;
          case 2:  printf("At what position the element should be deleted:");
                   scanf("%d",&pos);
                   if(pos>n){printf("Invalid position!");}
                   else{
                   for(int i=pos;i<n;i++)
                   {
                    arr[i-1]=arr[i];
                   }
                   n--;}
                   break;
          case 3:  n--;
                   break;
          case 4:  return 0;
          default:printf("invalid option!!\n");
                  break;
        }
      if(opt<4)  
        {print(arr);}
        }

}  
int sort(int a[])
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
    int i,opt;
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
        printf("1.insert an element\n2.Delete an element\n3.Search an element\n4.Sort the array\n5.Print\n6.Create New array\n7.Exit\n");
        scanf("%d",&opt);
        switch (opt)
        {
          case 1:insert(arr);
                 break;
          case 2:delete(arr);
                 break;
          case 3:search(arr);
                 break;
          case 4:sort(arr);
                 print(arr);
                 break;
          case 5:print(arr);
                 break;
          case 6: printf("Enter number of elements in your array:");
                  scanf("%d",&n);
                  printf("Enter your elements:");
                  for(i=0;i<n;i++)
                 {
                 scanf("%d",&arr[i]);  
                 }
                 break;
          case 7:exit(0);
          default:printf("invalid option!!\n");
                  break;
        }
    }
    return 0;
}
