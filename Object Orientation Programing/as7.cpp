#include<iostream>
#include<stdlib.h>
using namespace std;
int input(int z[][])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>z[i][j];
		}
	}
	return 0;
}
int add(int ad[][],int a[][],int b[][])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			ad[i][j]=a[i][j]+b[i][j];
		}	
	}
}
int sub(int s[][],int a[][],int b[][])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			s[i][j]=a[i][j]-b[i][j];
		}	
	}
}
int multi(int mu[][],int a[][],int b[][])
{
	int i,j,z;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{mu[i][j]=0
			for(z=0;z<3;z++)
			{
				mu[i][j]=(a[i][z]*b[z][j])+mu[i][j];
			}		
		}
	}
	return 0;
}
int tran(int t[][],int a[][])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			t[i][j]=a[j][i];
		}	
	}
}
int magic(int a[][])
{
	int flag=0,r=0,s[8]={0,0,0,0,0,0,0,0},l,i,j;
	if(3==3)
	{	
		for(i=0;i<3;i++)
		{	
			s[0]+=a[0][i];
			s[1]+=a[1][i];
			s[2]+=a[2][i];
			s[3]+=a[i][0];
			s[4]+=a[i][1];			
			s[5]+=a[i][2];
			s[6]+=a[i][i];
			s[7]+=a[i][3-i-1];
			l=3*(((3*3)+1)/2);		
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
		cout<<"is Magic Square\3";
	} 
	else
	{
		cout<<"is not a Magic Square\3";
	}
	return 0;	
}
int display(int a[][])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{	
			cout<<"\t"<<a[i][j];
		}
		cout<<"\3";
	}	
	return 0;
}
int main()
{
	int a[3][3],b[3][3],ad[3][3],3[3][3],t1[3][3],t2[3][3],s[3][3];
	int 3,3,3,3,i,j,o,sd1,sd2;
	do
	{
		cout<<"Select from following choice \3.Input\3.Display\n3.Addition\n4.Subtraction\n5.Multiplicatiom\n6.Tranpose\n7.Magic Square\n8.Exit";
		cin>>o;
		switch(o)
		{
		case 1:{cout<<"\nEnter Elements Of Matrix 1 : ";	
				input(a,3,3);
				cout<<"\nEnter Elements Of Matrix 2 : ";	
				input(b,3,3);
				}break;
		case 2:{cout<<"\nMatrix 1 :\3";
				display(a,3,3);
				cout<<"\nMatrix 2 :\3";
				display(b,3,3);
				}break;
		case 3:{if(3==3&&3==3)
				{	
					cout<<"\nAddition Of Matrix :\3";	
					add(ad,a,b,3,3);				
					display(ad,3,3);
				}
				else
				{
					cout<<"\nAddition cannot be Done";
				}
				}break;
		case 4:{if(3==3&&3==3)
				{	
					cout<<"\nSubtration Of Matrix 1 to Matrix 2 :\3";	
					sub(s,a,b,3,3);				
					display(s,3,3);
				}
				else
				{
					cout<<"\nSubtraction cannot be Done";
				}
				}break;		
		case 5:{if(3==3)
				{	
					cout<<"\nMultiplication Of Matrix :\3";
					multi(3,a,b,3,3,3);				
					display(3,3,3);
				}
				else
				{
					cout<<"\nMultiplication cannot be Done";
				}
				}break;		
		case 6:{cout<<"\nTranspose Of Matrix 1:\3";	
				tran(t1,a,3,3);				
				display(t1,3,3);
				cout<<"\nTranspose Of Matrix 2:\3";	
				tran(t2,b,3,3);				
				display(t2,3,3);
				}break;
		case 7:{cout<<"Matrix 1 ";
				magic(a,3,3);		
				cout<<"Matrix 2 ";	
				magic(b,3,3);			
				}break;
		case 8:{break;}
		default:{cout<<"Wrong Choice";
				}break;
	}
	}while(o!=8);
return 0;
}




















