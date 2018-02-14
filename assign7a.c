//To take input as elements of an array of size n*m and to find out if matrix is invertible or not.If invertible, then to print the inverse matrix in proper form,to determine if matrix is square or not.If square matrix,then to find the position of the element having highest minor value.
#include<stdio.h>
#include<math.h>


int det(int n,int l,int b[n][n])//det function made to find determinant of matrix.
{           //n is made corr. to size of array,l is row along which expansion is done,b array is made corr. to array whose det. is to be found.
int c[n-1][n-1],j,k,e,f,g,i;//c array has been made to find det. for square matrix of size greater than 3 by storing submatrix made.
int sum,d;//sum is det. value that is returned.
if(n==2)    //j,k,e,f,g,i,d are local variables of det function.
{
sum=(b[0][0]*b[1][1])-(b[0][1]*b[1][0]);//determinant value for square matrix of order 2*2.
return sum;
}
else if(n==3)
{
e=b[0][0]*(b[1][1]*b[2][2]-b[2][1]*b[1][2]);
f=-b[0][1]*(b[1][0]*b[2][2]-b[1][2]*b[2][0]);
g=b[0][2]*(b[1][0]*b[2][1]-b[1][1]*b[2][0]);
sum=e+f+g;//determinant value for square matrix of order 3*3.
return sum;
}

else//else block for finding det. value for square matrix of order greater than 3.
{
sum=0;
for(j=0;j<n;j++)
{
if(b[l][j]==0)
continue;
for(i=0;i<n-1;i++)//main functional for block.
{
for(k=0;k<n-1;k++)
{
if(i>=l&&k>=j)
{
c[i][k]=b[i+1][k+1];
continue;
}
else if(i>=l&&k<=j)
c[i][k]=b[i+1][k];
}
}
d=pow(-1,l+j);//d variable made for convenience.
sum=sum+(b[l][j]*d*det(n-1,0,c));
}
return sum;
}
}


int minor(int y,int l,int m,int b2[y][y])//minor function is made for breaking the matrix into submatrix for finding minors.
{      //y is order of matrix passed,l and m are row,column of element whose minor is to be found.
 int c[y-1][y-1],k,i;//b array is made corr. to array whose elements' minor is to be found.
int z;  //c array has been made for storing the submatrix.
for(i=0;i<y-1;i++)
{                    //k,i and z are local variables of minor function.
for(k=0;k<y-1;k++)
{
if(i>=l&&k>=m)//main if block for storing submatrix.
{
c[i][k]=b2[i+1][k+1];
continue;
}
else if(i<=l&&k>=m)
{
c[i][k]=b2[i][k+1];
continue;
}
else if(i>=l&&k<=m)
{
c[i][k]=b2[i+1][k];
continue;
}
else if(i<=l&&k<=m)
c[i][k]=b2[i][k];
}
}
z=det(y-1,0,c);//det function called for finding minor.
return z;
}


int hcf(int a,int b)//hcf function has been made to calculate hcf for printing elements in proper form.
{        //a and b are local variables of hcf function.
if(b==0)
return a;
return hcf(b,a%b);
}


int main()
{
int n,m,i,j,x,t,e=1,f=1,z=0,d;//variables declared here are local to main function.
float c3,c4;
printf("Enter the size of the matrix(n*m)=");
scanf("%d,%d",&n,&m);//n is no. of rows and m is no. of columns of matrix to be entered.
int a[n][m];         // a array made to store 2D matrix.
for(i=0;i<n;i++)//for loop made to scan the elements of 2D array made.
{
printf("\nEnter elements of row %d=",i+1);
for(j=0;j<m;j++)
scanf("%d",&a[i][j]);
}
if(n!=m)
printf("\nThe entered matrix is not invertible.\nThe entered matrix is not a square matrix.\nMinor does not exist.");
else
{
int c1[n][m],b1[n][m],c2[n][m],max;//c1,b1 and c2 array are temporary array made for printing the inverse matrix.
x=det(m,0,a);//det function called to find det. of the matrix.
if(x==0)
{
printf("\nThe entered matrix is not invertible.\nThe entered matrix is a square matrix.");
for(i=0;i<n;i++)//for loop for storing minors for non-invertible matrix.
{
for(j=0;j<n;j++)
c1[i][j]=minor(n,i,j,a);
}
}
else if(x!=0)
{
printf("\nThe entered matrix is invertible.The inverse matrix is:\n");
for(i=0;i<n;i++)//for loop made to store cofactors of the matrix.
{
for(j=0;j<n;j++)
{
d=pow(-1,i+j);
b1[i][j]=d*minor(n,i,j,a);
}
}
for(i=0;i<n;i++)//for loop made to store minors for invertible matrix.
{
for(j=0;j<n;j++)
{
d=pow(-1,i+j);
c1[i][j]=b1[i][j]/d;
}
}
for(i=0;i<n;i++)//functional for loop to get adjoint matrix (transpose of cofactor matrix.)
{
for(j=i;j<n;j++)
{
t=b1[i][j];
b1[i][j]=b1[j][i];
b1[j][i]=t;
}
}
for(i=0;i<n;i++)//for loop made to store respective hcf's of adjoint matrix's elements and det. of the matrix.
{
for(j=0;j<n;j++)
{
c3=(float)(b1[i][j]);
c4=(float)(x);
c2[i][j]=hcf(fabs(c3),fabs(c4));//hcf function called.
}
}
for(i=0;i<n;i++)//functional for loop for printing elements of inverse matrix in proper form.
{
for(j=0;j<n;j++)
{
if(b1[i][j]==0)
printf("%d ",b1[i][j]);
else
{         //if-else block made to consider various cases.
if(b1[i][j]<0&&x<0)
printf("%d/%d ",(-b1[i][j])/c2[i][j],-x/c2[i][j]);
else if(b1[i][j]>0&&x<0)
printf("%d/%d ",(-b1[i][j]/c2[i][j]),-x/c2[i][j]);
else
printf("%d/%d ",b1[i][j]/c2[i][j],x/c2[i][j]);
}
}
printf("\n");
}
printf("\nThe entered matrix is a square matrix.");
}
max=c1[0][0];//max variable made to find maximum minor.
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(c1[i][j]>max)//if-else block made to calculate position of element having highest minor.
{
max=c1[i][j];
e=i+1;
f=j+1;
}
else if(c1[i][j]==max)
z++;
}
}
if(z==n*n)
printf("\nAll minors are equal and their values are %d.",max);
else
printf("\nThe position of the element with highest minor is i=%d , j=%d",e,f);
}
return 0;
}
