#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int inputp(char *s)
{	char ch;
	int i,d;
	scanf("%d",&d);
	do
	{
	 ch=getchar();
	 *s=ch;
	 s++;	
	}while(ch!='\n');
	s--;	
	*s='\0';
	return 0;
}
int stlenp(char *s)
{
	int n=0;
	char *p;
	p=s;
	for(;*s!='\0';s++)
	{	
		n++;
	}
	s=p;
	return n;
}
int stcatp(char *s1,char *s2,char *s12)
{
	int n1,n2,i;
	char *p1,*p2,*p3;
	p1=s1;
	p2=s2;
	p3=s12;
	n1=stlenp(s1);
	n2=stlenp(s2);
	for(i=0;i<n1;i++,p1++,p3++)
	{
 		*p3=*p1;
 	}
 	for(i=0;i<=n2;i++,p2++,p3++)
 	{
 		*p3=*p2;
 	}
	return 0;
}
int strevp(char *s,char *rs)
{	
	int n,i;
	char *re,*se;
	se=s;	
	re=rs;
	n=stlenp(s);
	re=re+n-1;
	for(i=0;i<n;i++,se++,re--)
	{
		*re=*se;
	}
	rs[n]='\0';
	return 0;
}
int stcmpp(char *s1,char *s2)
{
	int res=0,n1,n2,i;
	char *se1,*se2;
	se1=s1;
	se2=s2;
	n1=stlenp(s1);
	n2=stlenp(s2);
	if(n1==n2)
	{
		for(i=0;i<n1;i++,se1++,se2++)
		{
			if(*se1!=*se2)
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
int stpalp(char *s)
{
	int n,res=0;
	char *rs;	
	rs=(char*)malloc(10*sizeof(char));
	n=stlenp(s);
	strevp(s,rs);	
	res=strcmp(s,rs);
	return res;	
}
int ststrp(char *s1,char *s2)
{
	int i,j,n1,n2,p=0,o,rs=0;
	char *se1,*se2;
	se1=s1;
	se2=s2;
	n1=stlenp(s1);
	n2=stlenp(s2);		
	for(i=0;i<=(n1-n2);i++,se1++)
	{se2=s2;
		for(j=0;j<n2;j++,se2++)
		{
			if(*(se1+j)!=*se2)
				{break;}
		}
		if(j==n2)
		{rs=1;	
		break;}
		else
		{rs=0;}

	}
return rs;
}
int vowelp(char *s)
{
	char *se;
	se=s;
	int n,i;
	n=stlenp(s);
	for(i=0;i<n;i++,se++)
	{	
		if((*se=='a')||(*se=='e')||(*se=='i')||(*se=='o')||(*se=='u')||(*se=='A')||(*se=='E')||(*se=='I')||(*se=='O')||(*se=='U'))
		{
			printf("%c",*se);	
		}
	}
	return 0;
}
int main()
{
	char *s1,*s2,*rs1,*rs2,*s12,*s21,*temp;
	s1=(char*)malloc(10*sizeof(char));
	s2=(char*)malloc(10*sizeof(char));
	rs1=(char*)malloc(10*sizeof(char));
	rs2=(char*)malloc(10*sizeof(char));
	s12=(char*)malloc(20*sizeof(char));
	s21=(char*)malloc(20*sizeof(char));
	int o1,o2,n1,n2,res,rp1,rp2,su12,su21;
	do{
		printf("\n\nSelect Option from Following\n 1.Input String\n 2.Show String\n 3.Strlen\n 4.Strcat\n 5.Strrev\n 6.Strcmp\n 7.Pallidrome\n 8.Substring\n 9.Vowel\n 10.Exit");
		scanf("\n%d",&o1);
		switch(o1)
		{
			case 1:{printf("\n Enter String 1 ");	
				inputp(s1);
				printf("\n Enter String 2 ");	
				inputp(s2);
				}break;
			case 2:{printf("\n String 1: %s\n String 2: %s",s1,s2);
				}break;
			case 3:{n1=stlenp(s1);
				n2=strlen(s2);
				printf("\n String Length 1: %d\n String Length 2: %d",n1,n2);
				}break;
			case 4:{stcatp(s1,s2,s12);
				stcatp(s2,s1,s21);
				printf("\n String Concatenation 1-2 :%s\n String Concatenation 2-1 :%s",s12,s21);
				}break;
			case 5:{strevp(s1,rs1);
				strevp(s2,rs2);
				printf("\n Reverse String 1:%s\n Reverse String 2:%s",rs1,rs2);
				}break;
			case 6:{res=stcmpp(s1,s2);
				if(res==0)
				printf("\nStrings are Equal and Same");
				else if(res==1)
				printf("\nString 1 is Greater than String 2");
				else if(res==-1)	
				printf("\nString 2 is Greater than String 1");		
				else
				printf("\nStrings are Equal and not Same");
				}break;
			case 7:{rp1=stpalp(s1);
				rp2=stpalp(s2);
				if(rp1==0)
				printf("\nString 1 is a Palidrome");
				else
				printf("\nString 1 is not a Palidrome");
				if(rp2==0)
				printf("\nString 2 is a Palidrome");
				else
				printf("\nString 2 is not a Palidrome");
				}break;
			case 8:{su12=ststrp(s1,s2);
				su21=ststrp(s2,s1);
				if(su12==1)
				printf("\nString B is Subset Of String A");
				else
				printf("\nString B is not Subset Of String A");
				if(su21==1)
				printf("\nString A is Subset Of String B ");
				else
				printf("\nString A is not Subset Of String B");
				}break;
			case 9:{printf("\nVowels in String 1: ");
				vowelp(s1);
				printf("\nVowels in String 2: ");				
				vowelp(s2);
				}break;
			case 10:break;
			default:{printf("\n Wrong Choice");	
				}break;
		}
	}while(o1!=10);
return 0;
}
