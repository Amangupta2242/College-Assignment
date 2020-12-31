#include<stdio.h>
int main()
{
	int na,nb,i,j,r;
	printf("Enter the length of set A and B");
	scanf("%d%d",&na,&nb);
	int sa[na],sb[nb],u[na+nb],q=na;
///////////////////////// input
	printf("Enter Set A");
	for(i=0;i<na;i++)
	{
		scanf("%d",&sa[i]);\
		u[i]=sa[i];
	}
	printf("Enter Set B");
	for(i=0;i<nb;i++)
	{
		scanf("%d",&sb[i]);
	}
//////////////////////////union	
	for(i=0;i<nb;i++)
	{ r=0;
		for(j=0;j<na;j++)
		{ 
			if(sb[i]==sa[j])
			{
				r=1;
				break;			
			}
		}
		if(r==0)
		{
			u[q]=sb[i];
			q++;
		}
	}
////////////////////////intersection
	int in[na],x=0;	
	for(i=0;i<na;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(sa[i]==sb[j])
			{
				in[x]=sa[i];
				x++;
				break;
			}	
		}
	}
///////////////////////////DifferenceA
int difa[na],w,ha=0;
	for(i=0;i<na;i++)
	{ w=0;
		for(j=0;j<x;j++)
		{
			if(sa[i]==in[j])
			{
				w=1;
				break;
			}
			if(w==0)
			{
				difa[ha]=sa[i];
				ha++;
			}	
		}
	}
///////////////////////////DifferenceB
int difb[nb],hb=0;
	for(i=0;i<nb;i++)
	{ w=0;
		for(j=0;j<x;j++)
		{
			if(sb[i]==in[j])
			{
				w=1;
				break;
			}
			if(w==0)
			{
				difb[hb]=sb[i];
				hb++;
			}	
		}
	}
////////////////////////////symmertic diff
int sd[ha+hb];
	for(i=0;i<ha;i++)
	{
		sd[i]=difa[i];
	}
	for(i=hb;i<ha+hb;i++)
	{
		sd[i]=difb[i-hb];
	}
///////////////////////////output
	printf("\n Union");
	for(i=0;i<na+nb-1;i++)
	{
		printf(" %d",u[i]);
	}
	printf("\n Intersection");
	for(i=0;i<x;i++)
	{
		printf(" %d",in[i]);
	}
	printf("\n Difference of A");
	for(i=0;i<ha;i++)
	{
		printf(" %d",difa[i]);
	}
	printf("\n Difference of B");
	for(i=0;i<hb;i++)
	{
		printf(" %d",difb[i]);
	}
	printf("\n Symmetric Difference");
	for(i=0;i<hb+ha;i++)
	{
		printf(" %d",sd[i]);
	}
return 0;
}
