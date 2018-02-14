//to find perfect squares between given range of numbers.
#include<stdio.h>
int main()
{
int a,b,i,c,n=0;//a=lower limit of range;b=upper limit of range.
//i is declared variable ; n is initialized variable.
printf("Enter the range of numbers.:");
scanf("%d-%d",&a,&b);
while(n==0)//while loop used.
{
for(i=1,c=1;c<=b;i++,(c=i*i))
{
if(c>=a&&c<=b)//if statement used.
{
++n;//n pre incremented.
if(n==1)
printf("The perfect squares in the given range are: %d ",c);
else if(n!=1)
printf("%d ",c);//c is perfect square in the range.
}
}
if(n!=0)
break;//break statement used.
printf("\nNo perfect square exists.Please enter another range.:");
scanf("%d-%d",&a,&b);
}
return 0;
}

