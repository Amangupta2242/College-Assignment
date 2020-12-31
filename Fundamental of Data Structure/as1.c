#include<stdio.h>
int multi(int so[],int s[],int no)
{
	int n=0,i,j,flag=0;
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
return n;
}
int input(int s[],int so[],int *no)
{	
	int n=0,i=0;
	printf(" Enter the length of set  ");
	scanf("%d",no);
	printf(" Enter Elements Of Set ");
	for(i=0;i<*no;i++)
	{
		scanf("%d",&so[i]);
	}
	n=multi(so,s,*no);
	return n;
}
int unions(int sa[],int sb[],int u[],int na,int nb)
{
	int i,j,flag=0,nu=na;
	for(i=0;i<na;i++)
	{
		u[i]=sa[i];
	}
	for(i=0;i<nb;i++)
	{ flag=0;
		for(j=0;j<na;j++)
		{ 
			if(sb[i]==sa[j])
			{
				flag=1;
				break;			
			}
		}
		if(flag==0)
		{
			u[nu]=sb[i];
			nu++;
		}
	}
	return nu;
}
int intersection(int sa[],int sb[],int in[],int na,int nb)
{
	int i=0,j=0,ni=0;	
	for(i=0;i<na;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(sa[i]==sb[j])
			{
				in[ni]=sa[i];
				ni++;
				break;
			}	
		}
	}
	return ni;
}
int diff(int s[],int dif[],int in[],int n,int ni)
{
	int flag,nd=0,i,j;
	for(i=0;i<n;i++)
	{ flag=0;
		for(j=0;j<ni;j++)
		{
			if(s[i]==in[j])
			{
				flag=1;
				break;
			}	
		}
		if(flag==0)
			{
				dif[nd]=s[i];
				nd++;
			}
	}
	return nd;
}
int sym(int sy[],int difa[],int difb[],int nda,int ndb)
{
	int ns=nda+ndb,i=0;
	for(i=0;i<nda;i++)
	{
		sy[i]=difa[i];
	}
	for(i=nda;i<ns;i++)
	{
		sy[i]=difb[i-nda];
	}
	return ns;
}
int show(int s[],int n)
{	int i;
	for(i=0;i<n;i++)
	{
		printf(" %d",s[i]);
	}
	return 0;
}
int main()
{
	int sa[10],sb[10],soa[10],sob[10],u[20],in[10],difa[10],difb[10],sy[20],na,noa,nob,nb,ni,nu,nda,ndb,ns,i,j,c,flag=0;
	for(j=0;;j++)
	{
	printf("\n\n\n Enter Your Choice \n 1.Input Set\n 2.Show Simple Set\n 3.Show Multi Set\n 4.Union\n 5.Intersection\n 6.Difference A\n 7.Difference B\n 8.Symmetric Difference\n 9.Exit  ");
	scanf("%d",&c);
		switch(c)
		{
			case 1: {	
						printf("\n Set A \n");
						na=input(sa,soa,&noa);
						printf("\n Set B \n");
						nb=input(sb,sob,&nob);		
					}break;
			case 2: {
						printf("\n Set A");
						show(sa,na);
						printf("\n Set B");
						show(sb,nb);
					}break;
			case 3: {
						printf("\n Set A");
						show(soa,noa);
						printf("\n Set B");
						show(sob,nob);
					}break;
			case 4: {
						nu=unions(sa,sb,u,na,nb);\
						printf("\n Union");
						show(u,nu);
						
					}break;
			case 5: {
						ni=intersection(sa,sb,in,na,nb);
						printf("\n Intersection");
						show(in,ni);
					}break;
			case 6: {
						ni=intersection(sa,sb,in,na,nb);
						nda=diff(sa,difa,in,na,ni);
						printf("\n Difference of A");
						show(difa,nda);
					}break;
			case 7: {
						ni=intersection(sa,sb,in,na,nb);
						ndb=diff(sb,difb,in,nb,ni);
						printf("\n Difference of B");
						show(difb,ndb);
					}break;
			case 8: {
						ni=intersection(sa,sb,in,na,nb);
						nda=diff(sa,difa,in,na,ni);
						ndb=diff(sb,difb,in,nb,ni);
						ns=sym(sy,difa,difb,nda,ndb);	
						printf("\n Symmetric Difference");
						show(sy,ns);
					}break;
			case 9: {flag=1;
					}break;
			default:{ printf("\n Wrong Choice \n");						
					}break;
		}
		if(flag==1)
		{
			break;
		}
	}
	return 0;
}
