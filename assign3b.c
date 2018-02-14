//program that reads last two no.'s of roll no. and display seven segment display those two numbers separately.
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int n[2],r,i;
char m[]="";
printf("Enter last two digits of your Roll No.:");/*r=roll no. last 2 digits.*/
scanf("%d",&r);
printf("Enter the character for display:");//m=character used to display the characters.
scanf("%s",m);
n[0]=r/10;
n[1]=r%10;
//n[i]=two digits stored separately in this array.
for(i=0;i<2;i++)
{
switch(n[i])//switch statement used.
{
case 0:
printf("%s%s%s%s\n%s  %s\n%s  %s\n%s  %s\n%s%s%s%s",m,m,m,m,m,m,m,m,m,m,m,m,m,m);
break;
case 1:
printf("   %s\n   %s\n   %s\n   %s\n   %s",m,m,m,m,m);
break;
case 2:
printf("%s%s%s%s\n   %s\n%s%s%s%s\n%s\n%s%s%s%s",m,m,m,m,m,m,m,m,m,m,m,m,m,m);
break;
case 3:
printf("%s%s%s%s\n   %s\n%s%s%s%s\n   %s\n%s%s%s%s",m,m,m,m,m,m,m,m,m,m,m,m,m,m);
break;
case 4:
printf("%s  %s\n%s  %s\n%s%s%s%s\n   %s\n   %s",m,m,m,m,m,m,m,m,m,m);
break;
case 5:
printf("%s%s%s%s\n%s\n%s%s%s%s\n   %s\n%s%s%s%s",m,m,m,m,m,m,m,m,m,m,m,m,m,m);
break;
case 6:
printf("%s%s%s%s\n%s\n%s%s%s%s\n%s  %s\n%s%s%s%s",m,m,m,m,m,m,m,m,m,m,m,m,m,m,m);
break;
case 7:
printf("%s%s%s%s\n   %s\n   %s\n   %s\n   %s",m,m,m,m,m,m,m,m);
break;
case 8:
printf("%s%s%s%s\n%s  %s\n%s%s%s%s\n%s  %s\n%s%s%s%s",m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m);
break;
case 9:
printf("%s%s%s%s\n%s  %s\n%s%s%s%s\n   %s\n%s%s%s%s",m,m,m,m,m,m,m,m,m,m,m,m,m,m,m);
}
printf("\n\n");
}
return 0;
}
