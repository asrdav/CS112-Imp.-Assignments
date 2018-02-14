//to create a list and then swap two nodes and finally reverse the list and print list in each case.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stud //stud structure made to create a unique node.
{
char roll[5];//roll variable made to store roll
float cpi;//cpi variable made to store cpi
float attendance;//attendance variable made to store attendance
struct stud *next;
};

void swap(struct stud **head1,char r3[5],char r4[5])//swap function to swap nodes in logical orders.
{
int d;//r3 made corr. to r1,r4 made corr. to r2.
d=strcmp(r3,r4);//strcmp made to compare r3 and r4.
if(d==0)
return;

struct stud *prev1=NULL,*curr=*head1;
while(curr && strcmp(curr->roll,r3)!=0)
{
prev1=curr;
curr=curr->next;
}

struct stud *prev2=NULL,*curr1=*head1;
while(curr1 && strcmp(curr1->roll,r4)!=0)
{
prev2=curr1;
curr1=curr1->next;
}

if(curr==NULL || curr1==NULL)
return;
if(prev1!=NULL)
prev1->next=curr1;
else
*head1=curr1;

if(prev2!=NULL)
prev2->next=curr;
else
*head1=curr;

struct stud *t1=curr1->next;
curr1->next=curr->next;
curr->next=t1;
}


void rev(struct stud** head2)//rev function made to reverse the list.
{
struct stud* prev   = NULL;
struct stud* current = *head2;
struct stud* next;
while(current != NULL)
{
  next  = current->next;
  current->next = prev;
  prev = current;
  current = next;
}
*head2 = prev;
}


int main()
{
struct stud *p,*head=NULL,*prev;//head node for pointing to first element of first node.
char ch='y',r1[5],r2[5];
int i,j;
while(ch=='y')
{
p=(struct stud*) malloc(sizeof(struct stud));//malloc function used to create space for p nodes of struct stud type.
printf("Enter the elements of the node");
printf("\nEnter the roll:");
scanf("%s",p->roll);
printf("\nEnter the cpi:");
scanf("%f",&p->cpi);
printf("\nEnter the attendance:");
scanf("%f",&p->attendance);
p->next=NULL;

if(head == NULL)//if else block made to traverse along the list.
head=p;

else
prev->next=p;

prev=p;
printf("\nAny more node(y/n):");
scanf(" %c",&ch);
}
while(1)//while loop made to print various cases depending on choice entered.
{
printf("\nEnter 1 for print,2 for swap,3 for reverse,0 for exit:");
scanf("%d",&j);
if(j==1)
{
p=head;
printf("\nThe list of the elements in linked list is:");
while(p!=NULL)
{
printf("<%s,%0.1f,%0.1f> ",p->roll,p->cpi,p->attendance);
p=p->next;
}
}
else if(j==2)
{
printf("\nEnter roll of first node to be swapped:");
scanf("%s",r1);
printf("\nEnter roll of second node to be swapped:");
scanf("%s",r2);
swap(&head,r1,r2);
printf("\nSwap successfull.");
}
else if(j==0)
{
printf("\nProgram ends");
break;
}
else if(j==3)
{
rev(&head);
printf("\nReverse operation is successfully done.");
}
}
return 0;
}
