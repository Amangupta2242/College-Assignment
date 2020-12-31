#include<stdio.h>
#include<stdlib.h>
int input(int **z,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",(*(z+i)+j));
		}
	}
	return 0;
}
int add(int **ad,int **a,int **b,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			*(*(ad+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
		}	
	}
}
int sub(int **s,int **a,int **b,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			*(*(s+i)+j)=(*(*(a+i)+j))-(*(*(b+i)+j));
		}	
	}
}
int multi(int **mu,int **a,int **b,int m1,int n1,int n2)
{
	int i,j,z;
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{*(*(mu+i)+j)=0;
			for(z=0;z<n1;z++)
			{
				*(*(mu+i)+j)=(*(*(a+i)+z))*(*(*(b+z)+j))+*(*(mu+i)+j);
			}		
		}
	}
	return 0;
}
int tran(int **t,int **a,int m,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			*(*(t+i)+j)=*(*(a+j)+i);
		}	
	}
}
int saddle(int **a,int m,int n)
{
	int i,j,min,max,x=0,y=0,o=0,p=0;
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
		}
	}
	printf("%d at Position [%d,%d]\n",max,o+1,p+1);
return 0;
}
int magic(int **a,int m,int n)
{
	int flag=0,r=0,s[8]={0,0,0,0,0,0,0,0},l,i,j;
	if(m==n)
	{	
		for(i=0;i<m;i++)
		{	
			s[0]+=a[0][i];
			s[1]+=a[1][i];
			s[2]+=a[2][i];
			s[3]+=a[i][0];
			s[4]+=a[i][1];			
			s[5]+=a[i][2];
			s[6]+=a[i][i];
			s[7]+=a[i][n-i-1];
			l=m*(((m*m)+1)/2);		
		}
		for(i=0;i<8;i++)
		{		
			if(s[i]==l)
			{
			r++;}
			}
		if(r!=8)
		{
			flag=1;
		}
	}
	else
	{flag=1;}
	if(flag==0)
	{
		printf("is Magic Square\n");
	} 
	else
	{
		printf("is not a Magic Square\n");
	}
	return 0;	
}
int display(int **a,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{	
			printf("\t%d",*(*(a+i)+j));
		}
		printf("\n");
	}	
	return 0;
}
int main()
{
	int **a,**b,**ad,**m,**t1,**t2,**s,m1,n1,m2,n2,i,j,o,sd1,sd2;
	printf("\nEnter Rows and Coloums Of Matrix 1 : ");	
	scanf("%d %d",&m1,&n1);
	printf("\nEnter Rows and Coloums Of Matrix 2 : ");	
	scanf("%d %d",&m2,&n2);
	a=(int**)malloc(m1*sizeof(int*));
	for(i=0;i<m1;i++)
	{
		*(a+i)=(int*)malloc(n1*sizeof(int));
	}
	b=(int**)malloc(m2*sizeof(int*));
	for(i=0;i<m2;i++)
	{
		*(b+i)=(int*)malloc(n2*sizeof(int));
	}
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
	t1=(int**)malloc(n1*sizeof(int*));
	for(i=0;i<n1;i++)
	{
		*(t1+i)=(int*)malloc(m1*sizeof(int));
	}
	t2=(int**)malloc(n2*sizeof(int*));
	for(i=0;i<n2;i++)
	{
		*(t2+i)=(int*)malloc(m2*sizeof(int));
	}	
	do
	{
		printf("Select from following choice \n1.Input\n2.Display\n3.Addition\n4.Subtraction\n5.Multiplicatiom\n6.Tranpose\n7.Saddle Point\n8.Magic Square\n9.Exit");
		scanf(" %d",&o);
		switch(o)
		{
		case 1:{printf("\nEnter Elements Of Matrix 1 : ");	
				input(a,m1,n1);
				printf("\nEnter Elements Of Matrix 2 : ");	
				input(b,m2,n2);
				}break;
		case 2:{printf("\nMatrix 1 :\n");
				display(a,m1,n1);
				printf("\nMatrix 2 :\n");
				display(b,m2,n2);
				}break;
		case 3:{if(m1==m2&&n1==n2)
				{	
					printf("\nAddition Of Matrix :\n");	
					add(ad,a,b,m1,n1);				
					display(ad,m1,n1);
				}
				else
				{
					printf("\nAddition cannot be Done");
				}
				}break;
		case 4:{if(m1==m2&&n1==n2)
				{	
					printf("\nSubtration Of Matrix 1 to Matrix 2 :\n");	
					sub(s,a,b,m1,n1);				
					display(s,m1,n1);
				}
				else
				{
					printf("\nSubtraction cannot be Done");
				}
				}break;		
		case 5:{if(m2==n1)
				{	
					printf("\nMultiplication Of Matrix :\n");
					multi(m,a,b,m1,n1,n2);				
					display(m,m1,n2);
				}
				else
				{
					printf("\nMultiplication cannot be Done");
				}
				}break;		
		case 6:{printf("\nTranspose Of Matrix 1:\n");	
				tran(t1,a,m1,n1);				
				display(t1,n1,m1);
				printf("\nTranspose Of Matrix 2:\n");	
				tran(t2,b,m2,n2);				
				display(t2,n2,m2);
				}break;
		case 7:{if(m1==n1)
				{
					printf("Saddle Point Of Matrix 1 ");	
					sd1=saddle(a,m1,n1);			
				}
				else
				printf("Saddle Point does not exist Matrix 1 ");	
				if(m2==n2)
				{					
					printf("Saddle Point Of Matrix 2 ");	
					sd2=saddle(b,m2,n2);			
				}
				else
				printf("Saddle Point does not exist Matrix 2 ");					
				}break;
		case 8:{printf("Matrix 1 ");
				magic(a,m1,n1);		
				printf("Matrix 2 ");	
				magic(b,m2,n2);			
				}break;
		case 9:{break;}
		default:{printf("Wrong Choice");
				}break;
	}
	}while(o!=9);
return 0;
}




















