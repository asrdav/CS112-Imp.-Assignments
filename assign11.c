//to create a binary search tree of given elements and then write the elements in pre order traversal form and then search max. and min. leaf nodes with their levels.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

        struct node     //struct node represents the basic node of tree.
        {
        int data;
        struct node *leftchild;
        struct node *rightchild;
        struct node *parent;
        };

void insert(struct node *head,struct node **p)//insert function has been made to create links to complete the tree.
{
        struct node *q = head;//head has been made to keep track of varying roots in recursion.
        if((*p)->data<=q->data)//p has been made to keep track of new node to be inserted.
        {
        if(q->leftchild==NULL)//if else block made to insert node having data value less than its to be parent node.
        {
        q->leftchild=*p;
        (*p)->parent=q;
        }
        else
        {
        q=q->leftchild;
        insert(q,p);
        }
        }
        else
        {
        if(q->rightchild==NULL)//if else block made to insert node having data value more than its to be parent node.
        {
        q->rightchild=*p;
        (*p)->parent=q;
        }
else
{
q=q->rightchild;
insert(q,p);//insert function recursively called.
}
}
return ;
}


void preorder(struct node *root,int k,int *min,int *max,int *level1,int *level2,int o)//preorder function made to do preorder traversal of tree.
{
if(root != NULL)
{
        printf("\n%d ",root->data);
if(k==1)//if else block made to deal with parent node separartely.
{
        printf("No parent");
        k++;
}
else
{
        printf("%d",root->parent->data);
        k++;
}
        if(root->leftchild==NULL&&root->rightchild==NULL)//if-else block made for finding largest leaf from maximum level.
        {
        if(o==*level1)//if else-if else block made to consider case where level is more but data value is less than max.
        {
        if(root->data>*max)
        *max=root->data;
        }
        else if(o>*level1)
        {
        *max=root->data;
        *level1=o;
        }
        else ;
        }
        else ;

        if(root->leftchild==NULL&&root->rightchild==NULL)//if-else block made for finding smallest leaf from minimum level.
        {
    if(*level2==0)//if-else block made to consider min. value for main root node.
        {
        *min=root->data;
        *level2=o;
        }
        else
        {
        if(o==*level2)//if else-if else block made to consider case where level is less but data value is more than min.
        {
        if(root->data<*min)
        *min=root->data;
        }
        else if(o<*level2)
        {
        *min=root->data;
        *level2=o;
        }
        else ;
        }
        }
        else ;
        o=o+1;
preorder(root->leftchild,k,min,max,level1,level2,o);    //traversing left sub tree
preorder(root->rightchild,k,min,max,level1,level2,o);   //traversing right sub tree
}
return ;
}



 int main()
        {
int n,k=1,i,max=0,min=0,level1=0,level2=0,o=0;
struct node *p,*prev,*root=NULL;
printf("n:");
scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
if(root==NULL)//if-else block made to insert data into the node and that too separately for root node.
{
        p=(struct node*) malloc(sizeof(struct node));//allocating memory for basic node of tree.
        p->leftchild=NULL;
      p->rightchild=NULL;
        scanf("%d",&(p->data));
        root=p;
        root->parent=NULL;
}
else
{
        p=(struct node*) malloc(sizeof(struct node));
        p->leftchild=NULL;
        p->rightchild=NULL;
        scanf("%d",&(p->data));
        insert(root,&p);//calling insert function to create links between nodes of the tree.
}
prev=p;
}
        printf("NODE PARENT");
preorder(root,k,&min,&max,&level1,&level2,o);//calling preorder function to traverse the tree.
printf("\nLargest leaf from maximum level:element %d level %d",max,level1);
printf("\nSmallest leaf from minimum level:element %d level %d",min,level2);
        return 0;
        }
