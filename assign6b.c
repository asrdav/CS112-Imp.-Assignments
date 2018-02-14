//to write a program that will take input as no.of bowlers and the max. no. of overs one can deliver along with total no.of overs, and produce all unique combinations of overs.
#include <stdio.h>
#include<stdlib.h>

void combine(int b[],int c[],int st,int la,int d,int n1,int t2,int sum)//combine function introduced to find out all possible combinations.
{        //st has been made to initialize b array,la has been made to end the array,d is to initialize c array. 
int k,i,j;//k,i and j are intermediate variables.
if(d!=0)     //t2 made corr.to total overs(to).
sum=sum+c[d-1];
if(d==n1)
{
sum=0;
for(k=0;k<n1;k++)//for block made to interpret all possible distinct combinations.
sum=sum+c[k];
if(sum==t2)
{
for(k=0;k<n1;k++)
printf("%d ", c[k]);
printf("\n");
}
return;
}
if(t2>sum&&st!=0)//if-else block made for enabling the combinations to take same no. more than once.
st=st-1;
else if(t2<sum&&st!=0)
st=st+1;
for(i=st;i<=la;i++)
{
c[d]=b[i];
combine(b,c,i+1,la,d+1,n1,t2,sum);
}
}

void combine1(int b[],int e,int f,int to)//combine1 function has been made for convenience.
{             //c array has been made to store the combinations made.
int c[f],s3=0;//b array corr. to s4 array,e corr. to max+1,f corr. to n1,to corr. to n are made for ease of access of values.
combine(b,c,0,e-1,0,f,to,s3);//s3 has been made to calculate sum in combine function
}

int main()
{
int n,max,n1,s4[1000],i;//s4 is an array introduced to store max. no. of overs along with 0.
printf("Total overs:");
scanf("%d",&n);//n is introduced to take total no. of overs.
printf("\nMaximum no. of overs for one bowler:");
scanf("%d",&max);//max is the max limit of s4 array
printf("\nNo. of bowlers:");
scanf("%d",&n1);//n1 has been introduced to take no. of bowlers.
for(i=0;i<=max;i++)
s4[i]=(max-i);
combine1(s4,max+1,n1,n);
}
