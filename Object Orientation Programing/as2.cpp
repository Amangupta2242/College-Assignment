#include<bits/stdc++.h>
using namespace std;
class book
{
	private:
	string title,auth,publ;
	float price;
	int stock,purc;
	static int suc,unsuc;
	public:
	book()
	{
		title="None";
		auth="None";
		publ="None";
		price=0;
		stock=0;
	}
	int add()
	{
		cout<<" Enter Book Title ";
		cin>>title;
		cout<<" Enter Author Name ";
		cin>>auth;
		cout<<" Enter Publication ";
		cin>>publ;
		cout<<" Enter Price ";
		cin>>price;
		cout<<" Enter Stock ";
		cin>>stock;
		return 0;
	}
	int update()
	{
		cout<<" Enter Book Title ";
		cin>>title;
		cout<<" Enter Author Name ";
		cin>>auth;
		cout<<" Enter Publication ";
		cin>>publ;
		cout<<" Enter New Price ";
		cin>>price;
		cout<<" Enter New Stock ";
		cin>>stock;
		return 0;
	}
	int show()
	{
		cout<<"\n Book Title ";
		cout<<title;
		cout<<"\n Author Name ";
		cout<<auth;
		cout<<"\n Publication ";
		cout<<publ;
		cout<<"\n Price "<<price<<"\n Stock "<<stock;
		return 0;
	}

	int purchase()
	{
		cout<<" Enter Quantaties of Puchase ";
		cin>>purc;
		if(purc<=stock)
		{
			cout<<" Price to Paid "<<price*purc;
			stock=stock-purc;
			cout<<" \n Puchase Successful";
			suc++;
		}
		else
		{
			cout<<" \n Puchase Unsuccessful ( WE HAVE SHORTAGE OF BOOKS )";
			unsuc++;
		}

	}
	int cases()
	{
		cout<<"Total Succesful Transaction ";
		cout<<suc;
		cout<<"\nTotal Succesful Transaction ";
		cout<<unsuc;
		return 0;
	}

};
int book::suc=0;
int book::unsuc=0;
int main()
{
	int n=0,i,o,x,s;
	book *b[20];
	do{
		cout<<"\n\nEnter Your Choice from Following \n 1.Add\n 2.Update\n 3.Show\n 4.Purchase\n 5.Total Cases\n 6.Exit\n";
		cin>>o;
		switch(o)
		{
			case 1:	cout<<"\n Enter data of Book \n";
					b[n]=new book;
					b[n]->add();
					n++;
					break;
			case 2:	cout<<" Select Book number to Update ";
					cin>>x;
					b[x-1]->update();
					break;
			case 3:	for(i=0;i<n;i++)
					{
						cout<<"\nDetails of Book "<<i+1<<" :\n";
						b[i]->show();
					}
					break;
			case 4:	cout<<" Select Book number to Show Details ";
					cin>>x;
					b[x-1]->show();
					b[x-1]->purchase();
					break;
			case 5:	b[0]->cases();
					break;
			case 6: break;
			default:{cout<<"Wrong Choice";}
		}
	}while(o!=6);

return 0;
}
