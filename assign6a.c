//to write a program that take letters as input and produce all possible distinct words.
#include<stdio.h>
#include<string.h>

void swap(char *x,char *y)//swap function has been made to compare the values.
{
        char t;//x and y are pointers that has been made to take the corresponding addrresses passed.
        t=*x;//t is a local variable made for swapping
        *x=*y;
        *y=t;
}
//b array has been made corresponding to a array to take the characters.
void permute(char b[], int s, int e)//permute array has been made to calculate all possible permutations.
{
        if(s==e)//s is integer corr. to first input character,e is integer corr. to last input character.
                {
                        int j;
                        for(j=0;j<=e;j++)
                                printf("%c",b[j]);
                        printf(" ");
                        return ;
                }
        char check[256]={0};//check array made to eliminate the possibilities of duplicates.
        int k,i;//k variable introduced for check array,i is a local variable.
        for(k=0;k<256;k++)//for loop for checking cases of possibilities.
                check[k]=0;
        for(i=s;i<=e;i++)//for loop for permuting the characters.
        {
                if(!check[b[i]])// fundamental if block.
                {
                        swap(b+i,b+s);//swap function called to swap the characters.
                        permute(b,s+1,e);
                        swap(b+i,b+s);
                        check[b[i]]=1;
                }
        }
}
int main()
{
        int n,i;//i is a local variable.
        char a[50];//a array has been made to take characters as input.
        printf("Number of letters: ");
        scanf("%d",&n);//n is made to take no. of letters.
        printf("\nEnter the letters: ");
        for(i=0;i<n;i++)
                scanf(" %c",&a[i]);
        if(n>5)
        printf("Can't compute.\n");
        else
        {
                printf("\nThe possible words are:\n");
                permute(a,0,n-1);
        }
        return 0;
}
