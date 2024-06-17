//C program with call by reference on structures.
#include<stdio.h>
 struct student
{
  long roll;
  char name[20];
  int mark;

}s[100];
void new(int n)
{
printf("Enter roll.no:");
scanf("%ld",&s[n].roll);
printf("Enter name:");
scanf("%s",&s[n].name);
printf("Enter mark:");
scanf("%d",&s[n].mark);
}
void print(int n)
{
    
for(int i=0;i<n;i++)
{
printf("%ld   %s   %d\n",s[i].roll,s[i].name,s[i].mark);
}
}
void search(int n)
{
    long num;
    int pos=0;
    printf("Enter the roll no of the student:");
    scanf("%ld",&num);
    for(int i=0;i<n;i++)
    {
        if(s[i].roll==num)
        {
          pos=i+1;
          break;
        }
    }
    if(pos)
    {
        printf("Found entry\nRoll no: %ld\nName : %s\nMarks secured : %d",s[pos-1].roll,s[pos-1].name,s[pos-1].mark);
    }
    else
    {
        printf("No entry found!!!");
    }
}
int main()
{

    int n=0,opt;
    printf("In this program you can enter and search the details of the entered students");
    while(1){
    printf("\n1.New entry\n2.Print entry\n3.search details\n4.exit\n");
    scanf("%d",&opt);
        switch (opt)
        {
          case 1:  new(n);
                   n++;
                   break;
          case 2:  print(n);
                   break;
          case 3:  search(n);
                   break;
          case 4:  return 0;       
          default:printf("invalid option!!\n");
                  break;
       }
    }
    return 0;
}