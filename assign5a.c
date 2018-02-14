//to take the no. of students and their heights and colour of their robes and find out the no. of students who can see the stage and to find out whether it is a BOYS party or GIRLS party.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int n,*a,n1=1,j,max,*b,n2=0,i;//n=no. of students,a and b are pointers to make array of variable size.
printf("Enter the number of students participated:");
scanf("%d",&n);
a=malloc(sizeof(int) *n);
b=malloc(sizeof(int) *n);
printf("\nEnter the heights:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);//a[i] an array to store heights
printf("\nEnter the color of robes denoted by integers:");
for(i=0;i<n;i++)
scanf("%d",&b[i]);//b[i] an array to store colour of robes.
max=a[0];
for(i=0,j=1;j<n;j++,i++)
{
if(a[j]>=max)
{
max=a[j];//max is introduced to store the variable maximum height of student.
n1++;
}
}
printf("No. of students can see the stage: %d",n1);//n1 is required no. of students who can see the stage.
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(b[i]==b[j])
{
n2++;
break;
}
}//n2 is introduced to check whether it is a BOYS or GIRLS party.
if(n2!=0)
{
printf("\nIt is a BOYS party.");
break;
}
}
if(n2==0)
printf("\nIt is a GIRLS party.");
return 0;
}
