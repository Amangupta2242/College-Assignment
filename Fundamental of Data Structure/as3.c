#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a,**b,**ad,**m,**t1,**t2,**s,m1,n1,m2,n2,i,j,z;
//////////////////////////////////////intial
	printf("\nEnter Rows and Coloums Of Matrix 1 : ");	
	scanf("%d %d",&m1,&n1);
	a=(int**)malloc(m1*sizeof(int*));
	for(i=0;i<m1;i++)
	{
		*(a+i)=(int*)malloc(n1*sizeof(int));
	}
	
	printf("\nEnter Rows and Coloums Of Matrix 2 : ");	
	scanf("%d %d",&m2,&n2);
	b=(int**)malloc(m2*sizeof(int*));
	for(i=0;i<m2;i++)
	{
		*(b+i)=(int*)malloc(n2*sizeof(int));
	}
////////////////////////////////////////////extra intial
	ad=(int**)malloc(m1*sizeof(int*));
	for(i=0;i<m1;i++)
	{
		*(ad+i)=(int*)malloc(n1*sizeof(int));
	}
	s=(int**)malloc(m1*sizeof(int*));
	for(i=0;i<m1;i++)
	{
		*(s+i)=(int*)malloc(n1*sizeof(int));
	}
	m=(int**)malloc(m1*sizeof(int*));
	for(i=0;i<m1;i++)
	{
		*(m+i)=(int*)malloc(n2*sizeof(int));
	}
	t1=(int**)malloc(m1*sizeof(int*));
	for(i=0;i<m1;i++)
	{
		*(t1+i)=(int*)malloc(n1*sizeof(int));
	}
	t2=(int**)malloc(m2*sizeof(int*));
	for(i=0;i<m1;i++)
	{
		*(t2+i)=(int*)malloc(n2*sizeof(int));
	}
//////////////////////////////////////////////////////////input
	printf("\nEnter Elements Of Matrix 1 : ");	
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			scanf("%d",(*(a+i)+j));
		}
	}
	printf("\nEnter Elements Of Matrix 2 : ");	
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{
			scanf("%d",(*(b+i)+j));
		}
	}
/////////////////////////////////////////////////////////////addition
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			*(*(ad+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
		}	
	}
/////////////////////////////////////////////////////////////subtraction
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			*(*(s+i)+j)=(*(*(a+i)+j))-(*(*(b+i)+j));
		}	
	}
/////////////////////////////////////////////////////////////////multiplication
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{*(*(m+i)+j)=0;
			for(z=0;z<n1;z++)
			{
				*(*(m+i)+j)=(*(*(a+i)+z))*(*(*(b+z)+j))+*(*(m+i)+j);
			}		
		}
	}
///////////////////////////////////////////////////////Transpose
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			*(*(t1+i)+j)=*(*(a+j)+i);
		}	
	}
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{
			*(*(t2+i)+j)=*(*(b+j)+i);
		}	
	}
/////////////////////////output
	printf("\nMatrix 1 :\n");	
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{	
			printf("\t%d",*(*(a+i)+j));
		}
		printf("\n");
	}	
	printf("\nMatrix 2 :\n");		
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{	
			printf("\t%d",*(*(b+i)+j));
		}
		printf("\n");
	}
	printf("\nAddition Of Matrix :\n");		
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{	
			printf("\t%d",*(*(ad+i)+j));
		}
		printf("\n");
	}
	printf("\nSubtration Of Matrix :\n");		
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{	
			printf("\t%d",*(*(s+i)+j));
		}
		printf("\n");
	}
	printf("\nMultiplication Of Matrix :\n");		
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{	
			printf("\t%d",*(*(m+i)+j));
		}
		printf("\n");
	}
	printf("\nTranspose of Matrix 1 :\n");	
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{	
			printf("\t%d",*(*(t1+i)+j));
		}
		printf("\n");
	}	
	printf("\nTranspose Of Matrix 2 :\n");		
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{	
			printf("\t%d",*(*(t2+i)+j));
		}
		printf("\n");
	}
return 0;
}
