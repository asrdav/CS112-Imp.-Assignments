//to create two text files one for taking input and other for taking output,then to create a binary tree from postorder and inorder traversal and print preorder traversal in output text file.

#include<stdio.h>
#include<stdlib.h>
#define size 100

char in[size];//in array and post array has been declared globally for convenience for traversal in latter code.
char post[size];
FILE *q;//file pointer introduced globally for writing output in file.

struct node//struct node is basically representing the basic unit of tree.
{
char data;
struct node *left;
struct node *right;
};


int find(int st,int la,int t)//find function has been made to find index of element in inorder having max. index in post order.
{
int i,j,max=0,d;
for(i=st;i<=la;i=i+2)//for loop made to check the occurence of data in postorder traversal.
{
for(j=0;j<=t;j=j+2)
{
if(in[i]==post[j])//if block for calculating the index to be returned.
{
if(j>=max)
{
max=j;
d=i;
}
}
}
}
return d;//returning the index value.
}

struct node *create(int st,int la,int t)//create function has been made to create the tree.
{
int f;
struct node *p;
if(st>la)//if block to remove the case where starting index becomes more than last index.
return NULL;
f=find(st,la,t);//calling find function.
p=(struct node *) malloc(sizeof(struct node));//allocating memory for node of the tree.
p->left=NULL;
p->right=NULL;
p->data=in[f];
if(st==la)
return p;
p->left=create(st,f-2,t);//calling create function for making left subtree.
p->right=create(f+2,la,t);//calling create function for making right subtree.
return p;
}


void preorder(struct node *root,FILE *q)//preorder has been made for preorder traversal.
{
if(root!=NULL)
{
fprintf(q,"%c ",root->data);//writing the output in given output text file.
preorder(root->left,q);
preorder(root->right,q);
}
}


int main()
{
struct node *p,*root;
int i=0,k;
FILE *ofp;//file pointer made for scanning input from input text file.
if((ofp=fopen("ipseq.txt","r"))==NULL)
exit(1);

        fgets(in,size+1,ofp);
        fgets(post,size+1,ofp);
        fclose(ofp);
        while(in[i]!='\n')
        i++;
        k=i-1;

root=create(0,k,k);//create function called.

if((q=fopen("1601CS01.txt","w"))==NULL)
exit(1);
fprintf(q,"Pre-order sequence:");
preorder(root,q);//preorder function called.
fclose(q);
return 0;
}
