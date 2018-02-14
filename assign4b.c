//to find binary representation of 2 decimal integers and their hamming weights and hamming distance if the string lengths are equal and also their hexadecimal representation.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int arr[2],n[2],i,*a,*b,d,e,g,j=0,m,sum=0,c,h;
printf("Enter two decimal integers:");
scanf("%d,%d",&e,&g);//e=1st no.;g=2nd no.
n[0]=0;
n[1]=0;
arr[0]=e;//array element set equal to e
arr[1]=g;//array element set equal to g
for(i=0;i<=1;i++)
{
while(arr[i]!=0)
{
arr[i]=arr[i]/2;
n[i]++;//n[0]=size of 1st array;n[1]=size of 2nd array
}
}
arr[0]=e;
arr[1]=g;
printf("The binary representation for %d is ",arr[0]);
a=malloc(sizeof(int)*n[0]);//a is a pointer which has allocated space for n[0] elements of int type
b=malloc(sizeof(int)*n[1]);//b is a pointer which has allocated space for n[1] elements of int type
for(i=0;arr[0]!=0&&i<n[0];i++)
{
d=arr[0]%2;//d is remainder of respective no.
a[n[0]-1-i]=d;
arr[0]=arr[0]/2;
}
for(i=0;i<n[0];i++)
printf("%d",a[i]);//printing stepwise binary repr. for 1st no.
printf("\nThe binary representation for %d is ",arr[1]);
for(i=0;arr[1]!=0&&i<n[1];i++)
{
d=arr[1]%2;
b[n[1]-1-i]=d;
arr[1]=arr[1]/2;
}
for(i=0;i<n[1];i++)
printf("%d",b[i]);//printing stepwise binary repr. for 2nd no.
for(i=0;i<n[0];i++)
{
if(a[i]==1)
j++;
}
printf("\nHamming weight for the first string=%d\n",j);//j is hamming weight for 1st string
j=0;
for(i=0;i<n[1];i++)
{
if(b[i]==1)
j++;
}
printf("\nHamming weight for the second string=%d",j);//j is reset to print hamming weight for 2nd string
j=0;
if(n[0]==n[1])
{
for(i=0;i<n[0];i++)
{
if(a[i]!=b[i])
j++;
}
printf("\nHamming distance between the two strings=%d",j);// j is again reset to print hamming distance if length of 2 strings are equal
}
else if(n[0]!=n[1])
printf("\nHamming distance does not exist");
printf("\nThe hexadecimal representation for the first string=");
h=n[0]%4;
for(i=0;i<=(n[0]-1);)
{
if(h==0){
m=3;
h=4;
}
else if(h!=0)
m=h-1;
sum=0;
for(j=i;j<=i+h-1;j++)//j is again reset to print hexadecimal repr. for 1st string.
{
c=pow(2,m);
sum = sum +(c*a[j]);
--m;
}
if(sum<10)
printf("%d",sum);
else if(sum==10)
printf("A");
else if(sum==11)
printf("B");
else if(sum==12)
printf("C");
else if(sum==13)
printf("D");
else if(sum==14)
printf("E");
else if(sum==15)
printf("F");
if(h==0)
i=i+4;
else if(h!=0)
i=i+h;
h=4;
}
printf("\nThe hexadecimal representation for the second string=");
h=n[1]%4;
for(i=0;i<=(n[1]-1);)
{
if(h==0){
m=3;
h=4;
}
else if(h!=0)
m=h-1;
sum=0;
for(j=i;j<=i+h-1;j++)//j is again reset to print hexadecimal repr. for 2nd string.
{
c=pow(2,m);
sum = sum +(c*b[j]);
--m;
}
if(sum<10)
printf("%d",sum);
else if(sum==10)
printf("A");
else if(sum==11)
printf("B");
else if(sum==12)
printf("C");
else if(sum==13)
printf("D");
else if(sum==14)
printf("E");
else if(sum==15)
printf("F");
if(h==0)
i=i+4;
else if(h!=0)
i=i+h;
h=4;
}
return 0;
}

