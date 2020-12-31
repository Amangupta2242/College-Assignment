#include<stdio.h>
#include<string.h>
int input(char s[])
{
	scanf("%s",s);
	return 0;
}
int stlen(char s[])
{
	int n=0,i;
	for(i=0;s[i]!='\0';i++)
	{	
		n++;
	}
	return n;
}
int stcat(char s1[],char s2[],char s12[])
{
	int n1,n2,i;
	n1=stlen(s1);
	n2=stlen(s2);
	for(i=0;i<=n1;i++)
	{
 		s12[i]=s1[i];
 	}
 	for(i=0;i<=n2;i++)
 	{
 		s12[i+n1]=s2[i];
 	}
	return 0;
}
int stcmp(char s1[],char s2[])
{
	int res=0,n1,n2,i;
	n1=stlen(s1);
	n2=stlen(s2);
	if(n1==n2)
	{
		for(i=0;i<n1;i++)
		{
			if(s1[i]!=s2[i])
			{
				res=2;
				break;
			}
		}
	}
	else if(n1>n2)
	{
		res=1;
	}
	else
	{
		res=-1;	
	}
	return res;
}
int strev(char s[],char rs[])
{	
	int n,i;
	n=stlen(s);
	for(i=0;i<=n;i++)
	{
		rs[i]=s[n-i-1];
	}
	rs[n]='\0';
	return 0;
}
int stpal(char s[])
{
	int n,res=0;
	char rs[10];
	n=stlen(s);
	strev(s,rs);	
	res=strcmp(s,rs);
	return res;	
}
int ststr(char s1[],char s2[])
{
	int i,j,n1,n2,p=0,o,rs=0;
	n1=stlen(s1);
	n2=stlen(s2);		
	for(i=0;i<n1;i++)
	{	o=0;
		if(s1[i]==s2[0])
		{	p=i;
		 	o=1;
			for(j=1;j<n2;j++)
			{	p++;
				if(s1[p]!=s2[j])
				{
					break;	
				}
				o++;
			}
		}
		if(o==n2)
		{
			break;
		}

	}
	if(o==n2)
	{	
		rs=1;
	}

return rs;
}
int main()
{
	char s1[10],s2[10],rs1[10],rs2[10],s12[20],s21[20],res,rp1,rp2,su12,su21;
	int o1,o2,n1,n2;
	do{
		printf("\n\nSelect Option from Following\n 1.Input String\n 2.Show String\n 3.Strlen\n 4.Strcat\n 5.Strrev\n 6.Strcmp\n 7.Pallidrome\n 8.Substring\n 9.Exit");
		scanf("\n%d",&o1);
		switch(o1)
		{
			case 1:{printf("\n Enter String 1 ");	
				input(s1);
				printf("\n Enter String 2 ");	
				input(s2);
				}break;
			case 2:{printf("\n String 1: %s\n String 2: %s",s1,s2);
				}break;
			case 3:{n1=stlen(s1);
				n2=strlen(s2);
				printf("\n String Length 1: %d\n String Length 2: %d",n1,n2);
				}break;
			case 4:{stcat(s1,s2,s12);
				stcat(s2,s1,s21);
				printf("\n String Concatenation 1-2 :%s\n String Concatenation 2-1 :%s",s12,s21);
				}break;
			case 5:{strev(s1,rs1);
				strev(s2,rs2);
				printf("\n Reverse String 1:%s\n Reverse String 2:%s",rs1,rs2);
				}break;
			case 6:{res=stcmp(s1,s2);
				if(res==0)
				printf("\nStrings are Equal and Same");
				else if(res==1)
				printf("\nString 1 is Greater than String 2");
				else if(res==-1)	
				printf("\nString 2 is Greater than String 1");		
				else
				printf("\nStrings are Equal and not Same");
				}break;
			case 7:{rp1=stpal(s1);
				rp2=stpal(s2);
				if(rp1==0)
				printf("\nString 1 is a Palidrome");
				else
				printf("\nString 1 is not a Palidrome");
				if(rp2==0)
				printf("\nString 2 is a Palidrome");
				else
				printf("\nString 2 is not a Palidrome");
				}break;
			case 8:{su12=ststr(s1,s2);
				su21=ststr(s2,s1);
				if(su12==1)
				printf("\nString B is Subset Of String A");
				else
				printf("\nString B is not Subset Of String A");
				if(su21==1)
				printf("\nString A is Subset Of String B ");
				else
				printf("\nString A is not Subset Of String B");
				}break;
			case 9:break;
			default:{printf("\n Wrong Choice");	
				}break;
		}
	}while(o1!=9);
return 0;
}
