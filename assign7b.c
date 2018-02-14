//to take no. of words as input and then sort them as sorted in dictionary.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
   int n,i,j;//n is no. of words taken.,i and j are local variables.
    char w[30],**p,*q;//w is a temporary array that has been made to store the characters in a word.

    printf("Input:\n");
  scanf("%d",&n);
   p= (char**) malloc(n*sizeof(char*));//p is a double pointer made to point to the starting character of word stored in w.
  for(i=0;i<n;i++)//for loop made to scan the word and point p to the required character.
  {
  scanf("%s",w);
  p[i]=(char*)malloc((strlen(w)+1) *sizeof(char));
   strcpy(p[i],w);
  }
   q= (char*)malloc((strlen(p[0])+1) *sizeof(char));//q is a sorting pointer made to facilitate sorting.

  for(i=0;i<n;i++)// functional for loop for bubble sorting
  {
 for(j=0;j<n-i-1;j++)
   {
 if(strcasecmp(p[j],p[j+1])>0)//strcasecmp function used to give equal priority to uppercase and lowercase characters.
    {
  if(strlen(q)<strlen(p[j]))
   q=realloc(q,(strlen(p[j])+1) *sizeof(char));//reallocation made if size of succeeding string is more.

  if(strlen(p[j])<strlen(p[j+1]))
   p[j]=realloc(p[j],(strlen(p[j+1])+1) *sizeof(char));

  if(strlen(p[j+1])<strlen(q))
   p[j+1]=realloc(p[j+1],(strlen(q)+1) *sizeof(char));

  strcpy(q,p[j]);//strcpy function used to temporarily copy pointer p[j] to pointer q.
   strcpy(p[j],p[j+1]);
    strcpy(p[j+1],q);
  }
   }
    }
    printf("Output:\n");

for(i=0;i<n;i++)//for loop made finally to print the strings.
printf("%s\n",p[i]);
return 0;
}
