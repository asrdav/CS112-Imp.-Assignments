//to create a doubly circular linked list that compares , adds and subtracts two given large numbers.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

        struct dnode//struct dnode is created to store a node.
        {
        long int data;
        struct dnode *prev;//prev pointer is created to keep track of previous links.
        struct dnode *next;//next pointer is created to keep track of succeeding links.
        };


        struct dnode *str(char *s1,int a1,int c) //str function created to create list.
        {
        struct dnode *head=NULL,*p,*prev1;
        int i,b[30],j,l,m,k=0;//i,j,m and k are local variables.
        long int a[30];
        b[0]=b[1]=b[2]=b[3]=b[4]=0;
        for(i=0,m=0;i<c;i++,m++)//for loop made to divide the integer into parts of 5.
        {
        for(j=a1-1-5*m,l=0;j>=0&&l<5;l++,j--)
        {
        b[l]=(s1[j])-'0';
        }
        a[i]=pow(10,4)*b[4] + pow(10,3)*b[3] +pow(10,2)*b[2] + pow(10,1)*b[1] +pow(10,0)*b[0];
        b[0]=b[1]=b[2]=b[3]=b[4]=0;
        }
        i=0;

        do{  //do-while loop made for creating double circular linked list.
        p = (struct dnode *) malloc(sizeof(struct dnode));//p node created to store the data in a node.
        if (head == NULL)
        {
        head = p;
        p->data=c;
        }
        else
     {
        prev1->next = p;
        p->data = a[i];
        p->prev=prev1;
        i++;
        }
        prev1 = p;
        k++;
        }while(k<=c);

        p->next=head;//completing the circular list.
        head->prev=p;

        return head;
        }



        struct dnode *add(struct dnode *head,struct dnode *head1,int c,int d)//add function made to add the numbers in list.
        {
        struct dnode *t,*p,*q,*last,*head2=NULL,*prev1;
        int carry=0,max,i,min;//carry is a local variable made to carry  no. if data in a node is of more than 5 digits.
        if(c>=d)
        {
        max=c;//max and min are local variables made for convenience.
        min=d;
        }
        else
        {
        max=d;
        min=c;
        }
        p=head->next;
        q=head1->next;

        for(i=1;i<=max;i++,min--)//for loop made to add the numbers.
        {
        t = (struct dnode *) malloc(sizeof(struct dnode));//t node created to store corr. sum.
        t->prev=NULL;
        if(min==0&&c>d)//if-else block made to check if  no. is finished or not.
        q->data=0;
        else if(min==0&&c<d)
  p->data=0;
        else ;

        if (head2== NULL)//if-else block made to create the sum list.
        {
        head2 = t;
        head2->prev=NULL;
        t->data=(((p->data)+(q->data))%100000);
        }
        else
        {
        prev1->next = t;
        t->data=(((p->data)+(q->data))%100000)+carry;
        t->prev=prev1;
        }
        carry=((p->data)+(q->data))/100000;
        prev1 = t;
        p=p->next;
        q=q->next;
        }
        if(carry!=0)//if block made to create a new node in case sum requires more no. of nodes.
        {
        t=(struct dnode*) malloc(sizeof(struct dnode));
        t->data=carry;
        t->prev=prev1;
        prev1->next=t;
        t->next=NULL;
        }
        last=t;//storing the last node for future reference. 
        t->next=NULL;
        return last;
        }



        struct dnode *subtract(struct dnode *head,struct dnode *head1,int c,int d,int max)//subtract function created to subtract the numbers. 
        {
        struct dnode *t,*p,*q,*last,*head2=NULL,*prev1;
        int i,carry=0,min;
        if(c>=d)
        min=d;//min is a local variable.
        else
   min=c;

        p=head->next;
        q=head1->next;

        for(i=1;i<=max;i++,min--)//for loop for creating the difference list.
        {
        t = (struct dnode *) malloc(sizeof(struct dnode));//t node created to store difference.
        t->prev=NULL;
        if(min==0&&c>d)//if-else block made to check if  no. is finished or not.
        q->data=0;
        else if(min==0&&c<d)
        p->data=0;
        else ;

        if (head2== NULL)//if-else block made to create difference list.
        {
        head2 = t;
        head2->prev=NULL;
        if(((p->data)-carry)>(q->data))//carry variable used if no. in one of the nodes is smaller than other.
        t->data=((p->data)-carry)-(q->data);
        else if(((p->data)-carry)==q->data)
        t->data=0;
        else
        {
        t->data=(100000+((p->data)-(carry))-(q->data));
        carry=1;
        }
        }

        else
        {
        prev1->next = t;
        if(((p->data)-carry)>(q->data))
        {
        t->data=((p->data)-carry)-(q->data);
        carry=0;
        }
        else if(((p->data)-carry)==q->data)
        {
        t->data=0;
        carry=0;
   }
        else
        {
        t->data=(100000+((p->data)-(carry))-(q->data));
        carry=1;
        }
        t->prev=prev1;
        }
        prev1 = t;//traversing the list.
        p=p->next;
        q=q->next;
        }
        last=t;//storing the last node for future reference.
        t->next=NULL;
        return last;
        }



        void compare(struct dnode *head,struct dnode *head1,int c,int d,char *s1,char *s2)//compare function made to compare the numbers.
        {
        struct dnode *p,*q;
        int i,max;
        if(c>=d)
        max=c;//max is a local variable.
        else
        max=d;

        p=head->prev;
        q=head1->prev;
        if(s1[0]=='-'&&s2[0]=='-')//if else-if else block to check various possibilities of comparison.
        {
        if(c>d)
        {
        printf("\n2nd number is larger.");
        return;
        }
        else if(c<d)
        {
        printf("\n1st number is larger.");
        return;
        }
  else
        {
        for(i=1;i<=max;i++)//for loop made if nodes in both no. is same and sign of both numbers are same.
        {
        if(p->data>q->data)
        {
        printf("\n2nd number is larger.");
        return;
        }
        else if(p->data<q->data)
        {
        printf("\n1st number is larger.");
        return;
        }

        else
        {
        p=p->prev;//traversing the list.
        q=q->prev;
        }
        }
        printf("\nBoth numbers are equal.");
        return;
        }
        }

        else
        {
        if(c>d)
        printf("\n1st number is larger.");
        else if(c<d)
        printf("\n2nd number is larger.");
        else
        {
        for(i=1;i<=max;i++)
        {
        if(p->data>q->data)
        {
        printf("\n1st number is larger.");
        return;
        }
   else if(p->data<q->data)
        {
        printf("\n2nd number is larger.");
        return;
        }
        else
        {
        p=p->prev;//traversing the list.
        q=q->prev;
        }
        }
        printf("\nBoth numbers are equal.");
        return;
        }
        }
        }




int main()
{
        char c1;
        char *s1,*s2;
        int  a1,b1,c,d,e;
        int i,k,count,n1,m1;
        struct dnode *head,*head1,*p,*q,*ptr,*r,*s;//ptr pointer made to store the pointers returned by add and subtract function.
        long int s3,s4,s5;
        printf("Comparison(c) or addition(a) or subtraction(s) or exit(x):");
        scanf(" %c",&c1);//c1 is created to store the choice user enters.
        while(c1!='x')//while loop made to process program if x is not the choice. 
        {                       //count variable is made to distinguish between addition's and subtraction's cases within themselves.
        m1=0;
        s1=(char *) malloc(150*sizeof(char));//s1 pointer made and dynamically allocated to store 1st integer.
        s2=(char *) malloc(150*sizeof(char));//s2 pointer made and dynamically allocated to store 2nd integer.
        scanf(" %s",s1);//taking s1 and s2 from user.
        scanf(" %s",s2);

        if(s1[0]=='-')//if else block made to store lengths of string pointers in various cases.
        a1=strlen(s1)-1;
        else
        a1=strlen(s1);
  if(s2[0]=='-')
        b1=strlen(s2)-1;
        else
        b1=strlen(s2);

        if(a1%5==0)//if else block made to store the actual length of no.
        c=a1/5;
        else
        c=(a1/5)+1;
        if(b1%5==0)
        d=b1/5;
        else
        d=(b1/5)+1;

        if(s1[0]=='-')//if else block made to send positive numbers to str function irrespective of sign.
        head=str(s1+1,a1,c);
        else
        head = str(s1,a1,c);
        if(s2[0]=='-')
        head1=str(s2+1,b1,d);
        else
        head1 = str(s2,b1,d);
        p=head;
        q=head1;
        r=head;
        s=head1;

        if(c1=='a')//if block for processing program if choice is addition.
        {
        printf("\nSum:");
        if((s1[0]=='-'&&s2[0]=='-')||(s1[0]!='-'&&s2[0]!='-'))//if else-if else block made to take care of various possibilities.
        {
        ptr = add(p,q,c,d);
        count=1;
        }
        else
        {
        if(c>d)
        {
        ptr = subtract(p,q,c,d,c);
        n1=2;
        }
     else if(c==d)
        {

        do{
        s3=r->prev->data;
        s4=s->prev->data;
        if(s3>s4)
        {
        ptr=subtract(p,q,c,d,c);
        n1=2;
        m1++;
        break;
        }
        else if(s3<s4)
        {
        ptr=subtract(q,p,d,c,d);
        n1=1;
        m1++;
        break;
        }
        else ;
        r=r->prev;//traversing the list.
        s=s->prev;
        c--;
        d--;
        }while(s3==s4&&c>0&&d>0);

        if(m1==0)
        {
        ptr=(struct dnode*) malloc(sizeof(struct dnode));//new node created if both numbers are equal.
        ptr->prev=NULL;
        ptr->data=0;
        ptr->next=NULL;
        n1=3;
        }
        else ;
        }
        else
        {
        ptr = subtract(q,p,d,c,d);
        n1=1;
        }
 count=2;
        }
        }

        else if(c1=='s')//else-if block for processing program if choice is subtraction.
        {
        printf("\nDifference:");
        m1=0;
        if((s1[0]=='-'&&s2[0]!='-')||(s1[0]!='-'&&s2[0]=='-'))//if else-if else block made to take care of various possibilities.
        {
        ptr = add(p,q,c,d);
        count=4;
        }
        else
        {
        if(c>d)
        {
        ptr = subtract(p,q,c,d,c);
        n1=2;
        }
        else if(c==d)
        {

        do{
        s3=r->prev->data;
        s4=s->prev->data;
        if(s3>s4)
        {
        ptr=subtract(p,q,c,d,c);
        n1=2;
        m1++;
        break;
        }
        else if(s3<s4)
        {
        ptr=subtract(q,p,d,c,d);
        n1=1;
        m1++;
        break;
        }
        else ;
        r=r->prev;//traversing the list.
  s=s->prev;
        c--;
        d--;
        }while(s3==s4&&c>0&&d>0);

        if(m1==0)
        {
        ptr=(struct dnode*) malloc(sizeof(struct dnode));//new node created if both numbers are equal.
        ptr->prev=NULL;
        ptr->data=0;
        ptr->next=NULL;
        n1=3;
        }
        }
        else
        {
        ptr = subtract(q,p,d,c,d);
        n1=1;
        }
        count=3;
        }
        }

        else if(c1=='c')//else -if block for processing program if choice is comparison.
        {
        if((s1[0]=='-'&&s2[0]=='-')||(s1[0]!='-'&&s2[0]!='-'))//if else-if else block made to take care of various possibilities.
        compare(p,q,c,d,s1,s2);
        else if(s1[0]=='-'&&s2[0]!='-')
        printf("\n2nd number is larger.");
        else
        printf("\n1st number is larger.");
        }
        else ;

        k=0;

        if(c1=='a'||c1=='s')//if else block made to print the required numbers in given format.
        {
        while(ptr!=NULL)//while loop for printing the numbers.
        {
        if(k==0)//if else block made to print the resulting zeroes in appropriate format.
        {
 if((count==1&&s1[0]=='-')||(count==4&&s1[0]=='-'))//if else-if else block made to print the negative sign at proper places.
        {
        s5=-(ptr->data);
        ptr->data=s5;
        }

        else if(count==2)
        {
        if((n1==2&&s1[0]=='-')||(n1==1&&s1[0]!='-')||(n1==3))
        {
        s5=-(ptr->data);
        ptr->data=s5;
        }
        else ;
        }

        else if(count==3)
        {
        if((n1==2&&s1[0]=='-')||(n1==1&&s1[0]!='-')||(n1==3))
        {
        s5=-(ptr->data);
        ptr->data=s5;
        }
        else ;
        }
        else ;
        printf("%ld ",ptr->data);//printing the data.
        }

        else//else block made to print zeroes at correct places apart from head node.
        {
        if(ptr->data/10000==0)
        {
        i=4;
        while(i>=1)
        {
        e=pow(10,i);
        if((ptr->data)/e==0)
        printf("0");
        else
        break;
        i--;
    }

        printf("%ld ",ptr->data);
        }
        else
        printf("%ld ",ptr->data);
        }
        k++;
        ptr=ptr->prev;//traversing the list.
        }
        }
        else ;

        printf("\nComparison(c) or addition(a) or subtraction(s) or exit(x):");
        scanf(" %c",&c1);
        while(c1!='a'&&c1!='s'&&c1!='c'&&c1!='x')//while loop made to neglect choices that are not applicable.
        {
        printf("\nInvalid choice.");
        printf("\nComparison(c) or addition(a) or subtraction(s) or exit(x):");
        scanf(" %c",&c1);
        }
        free(s1);//freeing the pointers s1 and s2 after their use.
        free(s2);
        }

return 0;
}
