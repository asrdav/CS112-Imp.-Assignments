//to encrypt and decrypt a number.
#include<stdio.h>
int main()
{
int a1,a2,a3,a4,a5,a6,b1,b2,b3,b4,n,n1,b5,b6,b7,b8,b9,b10,a7,a8,a9,a10;
printf("Enter the four digit number to be encrypted:");
scanf("%d",&n);
a1=n%10;
a2=n/10;
a3=a2%10;
a4=a2/10;
a5=a4%10;
a6=a4/10;
b1=(a1+7)%10;
b2=(a3+7)%10;
b3=(a5+7)%10;
b4=(a6+7)%10;
printf("\nThe encrypted number:%d%d%d%d",b2,b1,b4,b3);
printf("\nEnter the four digit number to be decrypted:");
scanf("%d",&n1);
b5=n1%10;
b6=n1/10;
b7=b6%10;
b8=b6/10;
b9=b8%10;
b10=b8/10;
a7=(b5+3)%10;
a8=(b7+3)%10;
a9=(b9+3)%10;
a10=(b10+3)%10;
printf("\nThe decrypted number:%d%d%d%d",a8,a7,a10,a9);
return 0;
}

