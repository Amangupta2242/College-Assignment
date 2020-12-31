#include<iostream>
#include<string.h>
using namespace std;
void show(string model,int screen,float cost)
{
	cout<<"\nModel no : "<<model;
	cout<<"\nScreen : "<<screen;
	cout<<"\nCost : "<<cost;
}
void input(string &model,int &screen,float &cost,int o)
{
	if(o==1)
	{
		cout<<"Enter Model no.(4 Digits) ";
		cin>>model;
		try
		{
			if(model.size()!=4)
			{			
				throw model;
			}
			else
			{input(model,screen,cost,2);}
		}
		catch(string model)
		{
				cout<<"Wrong Model no. \n";
				input(model,screen,cost,1);
		}
	}	
	if(o==2)
	{
		cout<<"Enter Screen Size(b/w 12 and 70) ";
		cin>>screen;
		try
		{
			if(screen<12||screen>70)
			{			
				throw screen;
			}
			else
			{input(model,screen,cost,3);}
		}
		catch(int screen)	
		{
			cout<<"Wrong Screen size \n";
			input(model,screen,cost,2);	
		}
	}
	if(o==3)
	{
			cout<<"Enter Cost(max. 7000) ";
			cin>>cost;
			try
			{
				if(cost>7000)
				{			
				throw cost;
				}
			}
			catch(float cost)
			{
				cout<<"Wrong Correct Cost \n";
				input(model,screen,cost,3);						
			}
	}
}
int main()
{
	string model="0000";
	int screen=0;
	float cost=0;
	input(model,screen,cost,1);
	show(model,screen,cost);
	return 0;
}
