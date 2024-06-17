//C program with pointers with structures
#include<stdio.h>
int main ()
{
    struct BMI
    {
        float h;
        char name[20];
        float w;
        float bmi;
    }s1,*s;
printf("Enter name:\n");
scanf("%s",&s1.name);
printf("Enter weight in kgs:\n");
scanf("%f",&s1.w);
printf("Enter height in meters:\n");
scanf("%f",&s1.h);
s=&s1;
s->bmi=s->w/(s->h*s->h);
if(s->bmi<18.5)
{
printf("%s is uderweight",s->name);
}
else if(s->bmi<=24.9)
{
printf("%s is fit",s->name);
}
else if(s->bmi<=29.9)
{
printf("%s is overweight",s->name);
}
else if(s->bmi<=34.9)
{
printf("%s is uder class 1 obesity",s->name);
}
else if(s->bmi<=39.9)
{
printf("%s is uder class 2 obesity",s->name);
}
else
{
printf("%s is uder class 3 obesity",s->name);
}
return 0;
}
    
