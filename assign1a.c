// to calculate and display the user's mass index
#include<stdio.h>
int main()
{
float m,h,b;
printf("Please enter your weight and height(separated by comma):");
scanf(" %f,%f",&m,&h);
b=m/(h*h);
if(b<18.5)
    printf("\nYour BMI is : %f and you are underweight.",b);
else if(b>=18.5 && b<=24.9)
    printf("\nYour BMI is : %f and you are normal.",b);
else if(b>=25 && b<=29.9)
    printf("\nYour BMI is : %f and you are overweight.",b);
else if(b>=30)
    printf("\nYour BMI is : %f and you are obese.",b);
return 0;
}
