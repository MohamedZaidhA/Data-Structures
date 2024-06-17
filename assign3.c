//C program to pass structure to a function
#include<stdio.h>
void print(int ans)
{
printf("%d",ans);
}
void add(int a, int b)
{
    int ans;
    ans=a+b;
    print(ans);
}
void sub(int a, int b)
{
    int ans;
    ans=a-b;
    print(ans);
}
void mul(int a, int b)
{
    int ans;
    ans=a*b;
    print(ans);
}
void div(int a, int b)
{
    int ans;
    ans=a/b;
    print(ans);
}
int main()
{
    int opt;
    struct calc
    {
        int a;
        int b;
    }s;
    while(1){
    printf("\nEnter number 1:\n");
    scanf("%d",&s.a);
    printf("Enter number 2:\n");
    scanf("%d",&s.b);
    printf("Select the operation to be done\n");
    printf("1.add\n2.sub\n3.multiply\n4.divide\n5.exit\n");
    scanf("%d",&opt);
        switch (opt)
        {
          case 1:add(s.a,s.b);
                 break;
          case 2:;sub(s.a,s.b);
                 break;
          case 3:mul(s.a,s.b);
                 break;
          case 4:div(s.a,s.b);
                 break;
          case 5:return 0;
                 break;
         default:printf("Invalid option!!");
                 break;       
    }
  }
}
