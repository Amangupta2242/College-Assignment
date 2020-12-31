#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a,sum,m,n,i,j;
	printf("\nEnter Rows and Coloums Of Matrix : ");	
	scanf("%d %d",&m,&n);
	a=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
	{
		*(a+i)=(int*)malloc(n*sizeof(int));
	}
	printf("\nEnter Elements Of Matrix : ");	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{		
			scanf("%d",(*(a+i)+j));
		}
	}
	printf("\nMatrix 1 :\n");	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{	
			printf("\t%d",*(*(a+i)+j));
		}
		printf("\n");
	}	
	int min,max,x=0,y=0,o=0,p=0;
	max=-10000;
	for(i=0;i<n;i++)
	{min=*(*(a+i));
		x=i;		
		for(j=0;j<m;j++)
		{
			if(*(*(a+i)+j)<min)
			{
				min=*(*(a+i)+j);
				x=i;
				y=j;		
			}
		}
		if(min>max)
		{	
			max=min;
			o=x;
			p=y;
			printf("\nmax [%d,%d]\n",o,p);						
		}
	}
	printf("%d at Position [%d,%d]\n",max,o,p);
return 0;
}
