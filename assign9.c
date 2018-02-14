//to print the elements in the list and then sort the list with respect to height and weight values.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {           //node made to store data of list.
        char roll[10];//roll array made to store the roll.
        int ht;//ht made to store heights.
        int wt;//wt made to store weights.
        struct node *nextht;//nextht pointer made to sort the heights.
        struct node *nextwt;//nextwt pointer made to sort the weights.
};

void sortht(struct node **head,int count)//sortht function made to sort the heights and print them.
{
        struct node *p,*next,*prev;//p, prev and next pointers made to store struct type variables.     
        int k;
        p=*head;//head double pointer made to store address of pointer head.
        prev=*head;//prev pointer made to keep track of previous node ; count variable made to store no. of input.
        while(count!=1)//while loop made for continuation of succeeding while loop.
        {                       //next pointer made to keep track of succeeding node.
        k=0;//k is a local variable
        while(p->nextht!=NULL)//main while loop made for sorting the height.
        {
                if((p->ht)>=(p->nextht->ht))//if-else block to sort the heights.
                {
                        prev=p;
                        p=p->nextht;
                }
                else
                {
                next=p->nextht;
                p->nextht=next->nextht;
                next->nextht=p;
                if(k==0)//if-else block made if one of nodes is head.
                {
                *head=next;
                prev=next;
                }
               else
                {
                prev->nextht=next;
                prev=next;
                }
                }
        k++;
        }
        p=*head;
        prev=*head;
        count--;
        }
        printf("\nSort using height:");
        p=*head;
        while(p!=NULL)//while loop made to print the sorted heights.
        {
                printf("%s ",p->roll);
                p=p->nextht;
        }
        return;
}

void sortwt(struct node **head,int count)//sortwt function made to sort the weights and print them.
{
        struct node *p,*next,*prev;//p, prev and next pointers made to store struct type variables.     
        int k;
        p=*head;//head double pointer made to store address of pointer head1.
        prev=*head;//prev pointer made to keep track of previous node ; count variable made to store no. of input.
        while(count!=1)//while loop made for continuation of succeeding while loop.
        {
        k=0;//k is a local variable
        while(p->nextwt!=NULL)//main while loop made for sorting the weight.
        {                       //next pointer made to keep track of succeeding node.
                if((p->wt)>=(p->nextwt->wt))//if-else block to sort the weights.
                {
                        prev=p;
                        p=p->nextwt;
                }
                else
                {
                next=p->nextwt;
                p->nextwt=next->nextwt;
               next->nextwt=p;
                if(k==0)//if-else block made if one of nodes is head.
                {
                *head=next;
                prev=next;
                }
                else
                {
                prev->nextwt=next;
                prev=next;
                }
                }
        k++;
        }
        p=*head;
        prev=*head;
        count--;
        }
        printf("\nSort using weight:");
        p=*head;
        while(p!=NULL)//while loop made to print the sorted weights.
        {
                printf("%s ",p->roll);
                p=p->nextwt;
        }
        return;
}




void display(struct node *r,struct node *s,int c,int d)//display function made to call the sorting functions.
{
        if(c==1)
        {
        sortht(&r,d);//r pointer made corr. to head node in main function ; sortht function called.
        sortwt(&s,d);//s pointer made corr. to head1 node in main function ; sortwt function called.
        }
        else
        printf("\nInvalid option");
return;
}
int main()
{
        int n,i,o;
        printf("enter no. of input\n");
        scanf("%d",&n);//n is no. of nodes to be created.
        struct node *p,*head=NULL,*head1=NULL,*prev;//head and head1 pointers are made for convenience for sorting. 
        for(i=1;i<=n;i++)//for loop made to create the list.
        {               //prev pointer made for convenience to create the list.
        p=(struct node *) malloc(sizeof(struct node));//allocating memory for nodes.
        scanf("%s %d %d",p->roll,&p->ht,&p->wt);
        p->nextht = NULL;
        p->nextwt = NULL;
                if (head == NULL&&head1==NULL)//if-else block made to create the list.
                {
                head = p;
                head1=p;
                }
                else
                {
                prev->nextht = p;
                prev->nextwt = p;
                }
        prev = p;
        }
        printf("\nGive option for traversing\n");
        scanf("%d",&o);
        display(head,head1,o,n);//display function called.
return 0;
}

