#include<iostream>
using namespace std;
class weather
{	
	private:
	int day;
	float mint,maxt,snow,rain;
	static float min,max,sno,rai;
	public:
	
	weather()
	{	
		mint=20;
		maxt=30;
		snow=25;
		rain=25;
	}
	int days(int d)
	{
		day=d;
		return 0;
	}
	int input()
	{
		cout<<" Enter Minimum Temperature ";
		cin>>mint;
		cout<<" Enter Maximum Temperature ";
		cin>>maxt;
		cout<<" Enter Snow Fall ";
		cin>>snow;
		cout<<" Enter Rain Fall ";
		cin>>rain;
		min+=mint-20;
		max+=maxt-30;
		sno+=snow-25;
		rai+=rain-25;
		return 0;
	}
	int show()
		{	
		cout<<"\n Day \t\t Minimum  Temperature \t Maximum Temperature \t Snow Fall \t Rain Fall  ";
		return 0;
	}
	int output()
	{	if(day>9)
		cout<<" \n Day "<<day<<" \t "<<mint<<" \t\t\t "<<maxt<<" \t\t\t "<<snow<<" \t\t "<<rain;
		else
		cout<<" \n Day "<<day<<" \t\t "<<mint<<" \t\t\t "<<maxt<<" \t\t\t "<<snow<<" \t\t "<<rain;
		return 0;
	}
	int average()
	{	
		cout<<" \n Average \t "<<min/31<<" \t\t\t "<<max/31<<" \t\t\t "<<sno/31<<" \t\t "<<rai/31;
		return 0;
	}
};
float weather::min=(20*31);
float weather::max=(30*31);
float weather::sno=(25*31);
float weather::rai=(25*31);
int main()
{	
	int n,na,z,i,x,o,flag=0,da=0;
	weather d[31];
	for(i=0;i<31;i++)
	{
		d[i].days(i+1);	
	}
	for(z=0;;z++)
	{
		cout<<"\n\nEnter Your Choice from Following \n 1.Insert\n 2.Insert Selected\n 3.Display\n 4.Display All\n 5.Edit\n 6.Average\n 7.Exit   ";
		cin>>o;
		switch(o)
		{
			case 1:	{	
					cout<<" Insert total number of Days from 0(Max 31) ";
					cin>>n;	
					for(i=0;i<n;i++)
					{
						d[i].input();
					}			
				}break;	
			case 2:	{	
					cout<<" Select Day to Enter ";
					cin>>x;
					d[x-1].input();
				}break;
			case 3:	{	
					cout<<" Select Day to Show Details ";
					cin>>x;
					d[0].show();
					d[x-1].output();
				}break;
			case 4:	{	d[0].show();
					for(i=0;i<31;i++)
					{
						d[i].output();
					}
					d[0].average();			
				}break;
			case 5:	{	
					cout<<" Select Day to Edit ";
					cin>>x;
					d[x-1].input();
				}break;
			case 6: {
					d[0].show();
					d[0].average();
				}break;
			case 7: {
					flag=1;
				}break;		
		}
		if(flag==1)
		{
			break;
		}
	}
return 0;	
}
