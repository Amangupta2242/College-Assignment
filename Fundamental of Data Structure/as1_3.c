#include<stdio.h>
int main()
{
	int so[10],s[10],no,n=0,i,j,flag=0;
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{scanf("%d",&so[i]);}
	for(i=0;i<no;i++)
	{flag=0;
		for(j=0;j<n;j++)
		{
			if(so[i]==s[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			s[n]=so[i];
			n++;
		}
	}
	for(i=0;i<n;i++)
	{printf(" %d ",s[i]);}
return 0;
}
