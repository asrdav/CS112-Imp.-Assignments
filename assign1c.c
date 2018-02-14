//to calculate tickets price from available seats and base fare.
#include<stdio.h>
int main()
{
int s,i;
float f;
printf("Enter the base fare:");
scanf("%f",&f);
printf("\nEnter the remaining seats:");
scanf("%d",&s);
i=(700-s);
if(i<70)
    printf("\nYour ticket price: %f",f);
else if(i>=70 && i<140)
    printf("\nYour ticket price: %f",1.1*f);
else if(i>=140 && i<210)
    printf("\nYour ticket price: %f",1.2*f);
else if(i>=210 && i<280)
    printf("\nYour ticket price: %f",1.3*f);
else if(i>=280 && i<350)
    printf("\nYour ticket price: %f",1.4*f);
else if(i>=350 && i<=700)
        printf("\nYour ticket price: %f",1.5*f);
return 0;
}

