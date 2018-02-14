/*to find out if the points are collinear and if non-collinear,then state triangle's area and also its type.*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
float m,n,o,ar,x1,y1,x2,y2,x3,y3,t1,s1,a,b,c;/*m=var1,n=var2,o=var3*/
printf("Enter the points:");/*ar=area,t1=slope1,s1=slope2,a=(side1)^2,b=(side2)^2,c=(side3)^2*/
printf("\nPoint1:");
scanf("%f,%f",&x1,&y1);
printf("\nPoint2:");
scanf("%f,%f",&x2,&y2);
printf("\nPoint3:");
scanf("%f,%f",&x3,&y3);
t1=(y2-y1)/(x2-x1);
s1=(y3-y2)/(x3-x2);
if(t1==s1)
printf("The points are collinear.");
else if(t1!=s1)
{
a = pow((x2-x1),2.0) + pow((y2-y1),2.0);
b = pow((x3-x2),2.0) + pow((y3-y2),2.0);
c = pow((x3-x1),2.0) + pow((y3-y1),2.0);
ar = 0.5 * abs((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)));
m= a+b-c;
n= b+c-a;
o= a+c-b;
if(m<0.0 || n<0.0 || o<0.0)
printf("\nThe points are non-collinear. The formed triangle is a obtuse-angled triangle with area = %f.",ar);
else if(m==0.0 || n==0.0 || o==0.0)
printf("\nThe points are non-collinear. The formed triangle is a right-angled triangle with area = %f.",ar);
else if(m>0.0 && n>0.0 && o>0.0)
printf("\nThe points are non-collinear. The formed triangle is a acute-angled triangle with area = %f.",ar);
}
return 0;
}



