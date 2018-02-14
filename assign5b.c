//to display the seating arrangement of guests,to find out a person with a unique id.,to calculate the no.of males and females and their guest ids,to calculate the no. of persons wearing red and blue dress resp. and display their seating positions and to find out the new seating arrangement for a new guest(if possible). 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int i,a[16],s[15],n1,n2,n=0,j,k,t,m=0,f=0,n3=0,r=0,b=0;//a[16] is an array made to take and store the unique ids of the guests.
printf("Enter the unique id's of the guests:");//s[15] has been made to store the data of a[16] for future reference.
for(i=0;i<=15;i++)
{
if(i==0)
scanf("%d",&a[i]);
else
scanf(",%d",&a[i]);
if(a[i]<0)
m++;//m is introduced to find out the no. of males.
else if(a[i]>0)
f++;//f is introduced to find out the no. of females. 
else if(a[i]==0)
break;
n++;
}
printf("\nEnter the id to be searched:");
scanf("%d",&n1);//n1 is to take the id that is to be searched.
printf("\nEnter the unique id of the new guest:");
scanf("%d",&n2);//n2 is to take the id of the new guest.
printf("The seating arrangement is:\n");
for(k=0;k<n;k++)
{
for(i=n-1,j=n-2;j>=k;i--,j--)
{
if(a[i]>=a[j])
{
t=a[i];//t here is swapping variable.
a[i]=a[j];
a[j]=t;
}
}
}
j=0;
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
if((i+1)%5==0)
printf("\n");
}
for(i=0;i<n;i++)
{
if(a[i]==n1)
{
n3++;
printf("\nThe guest with id %d is present in the party and is seated at position %d.",n1,(i+1));
break;
}
}
if(n3==0)
printf("\nNo guest is present of required id.");
printf("\nThere are %d males and %d females.",m,f);
printf("\nThe male guest ids are:");
for(i=0;i<n;i++)//for loop introduced to find out males' ids.
{
if(a[i]<0)
printf("%d ",a[i]);
}
printf("\nThe female guest ids are:");
for(i=0;i<n;i++)//for loop introduced to find out females' ids.
{
if(a[i]%2==0)
r++;//r is introduced to find out no. of persons wearing red dress.
else
b++;//b is introduced to find out no. of persons wearing blue dress.
if(a[i]>0)
printf("%d ",a[i]);
}
printf("\nThere are %d guests in red and %d guests in blue dress respectively.",r,b);
printf("\nThe seating positions of guests in red dress are:");
for(i=0;i<n;i++)//for loop for red dress's people seating positions.
{
if(a[i]%2==0)
printf("%d ",(i+1));
}
printf("\nThe seating positions of guests in blue dress are:");
j=0;
for(i=0;i<n;i++)//for loop for blue dress's people seating positions.
{
if(a[i]%2!=0)
printf("%d ",(i+1));
}
if(n==15)
printf("\nNo vacant seat");
else
{
for(i=0;i<n;i++)
s[i]=a[i];//s[i] is being introduced.
printf("\nThe new seating arrangement is:\n");
for(i=0;i<n+1;i++)
{
if(j==0)
{
if(n2>a[i])
{
k=i+1;
j++;
t=a[i];//t here is swapping variable
a[i]=n2;
}
}
if(j==1)
{
if(i==k)
a[i]=t;
else if(i>k)
a[i]=s[i-1];//s[i] introduced earlier is used here.
}
else if(n2<a[n-1])
a[n]=n2;
printf("%d ",a[i]);
if((i+1)%5==0)
printf("\n");
}
}
return 0;
}
