/*to determine the winner and also to determine the winning margin*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
float x,y,t,s;
/*x is time for which hare runs before he takes rest.
y is time for which hare takes rest.*/
printf("Enter X=");
scanf("%f",&x);
printf("\nEnter Y=");
scanf("%f",&y);
t=(18.0-(0.9*(x+y)))/0.9;
s=(18.0-(1.4*x))/1.4;
/*t is left time tortoise takes to complete race(if possible first) after hare starts running again.
s is left time taken by hare to complete race(if possible first) after waking up.*/
if(x>=90/7)
{
printf("\nWinner: Hare");
printf("\nWinning distance margin:%f",0.5*x);
}
else if(x<90/7)
{
if(t<s)
{
printf("\nWinner : Tortoise");
printf("\nWinning distance margin: %f metres",((1.4*y)-10.0));
}
else if(t>s)
{
printf("\nWinner : Hare");
printf("\nWinning distance margin: %f metres",(18.0-(0.9*y)-(81/7)));
}
else if(t==s)
{
printf("\nWinner : Tortoise and Hare");
printf("\nWinning distance margin: 0 metres");
}
}
return 0;
}

