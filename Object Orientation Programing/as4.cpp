#include<iostream>
using namespace std;
class info
{
	protected:
	string name,blood,dob;
	public:
	info()
	{
		name="None";
		blood="None";
		dob="None";
	}
	info(string nam,string bloo,string db)
	{
		name=nam;
		blood=bloo;
		dob=db;
	}
 	void editna()
	{
		cout<<"\nNew    Name :";
		cin>>name;
	}
 	void editgr()
	{
		cout<<"\nBlood Group :";
		cin>>blood;
	}
 	void editdob()
	{
		cout<<"\nDate Of Birth :";
		cin>>dob;
	}
 	void showi()
	{
		cout<<"\nName :"<<name;
		cout<<"\nBlood Group :"<<blood;
		cout<<"\nDate Of Birth :"<<dob;
	}
};
class body
{
	protected:
	float height,weight;
	public:
	body()
	{
		height=0.0;
		weight=0.0;
	}
	body(float hei,float wei)
	{
		height=hei;
		weight=wei;
	}

 	void edithe()
	{
		cout<<"\nNew Height :";
		cin>>height;
	}
	void editwe()
	{
		cout<<"\nNew Weight :";
		cin>>weight;
	}
 	void showb()
	{
		cout<<"\nHeight :"<<height;
		cout<<"\nWeight :"<<weight;
	}
};
class detail
{
	protected:
	int insure;
	string contact;
	public:
	detail()
	{
		insure=0;
		contact="None";
	}
	detail(int ins,string con)
	{
		insure=ins;
		contact=con;
	}
 	void editco()
	{
		cout<<"\nContact Address :";
		cin>>contact;
	}
 	void showd()
	{
		cout<<"\nInsurance Policy Number :"<<insure;
		cout<<"\nContact Address :"<<contact;
	}
};
class num: public info, public body, public detail
{
	protected:
	long long int tele,dl;
	public:
	num()
	{
		info();
		body();
		detail();
		tele=0;
		dl=0;
	}
	num(string nam,string bloo,string db,float hei,float wei,int ins,string con,long long int tel, long long int dls):info(nam,bloo,db),body(hei,wei),detail(ins,con)
	{
		tele=tel;
		dl=dls;
	}
 	void edit()
	{
		int o;
		cout<<"\nEnter Your Choice from Following \n 1.Name\n 2.Blood Group\n 3.DOB\n 4.Height\n 5.Wieght\n 6.Contact Address\n 7.Telephone Number\n 8.Driving Licence";
		cin>>o;
		switch(o)
		{
			case 1:editna();
					break;
			case 2:editgr();
					break;
			case 3:editdob();
					break;
			case 4:edithe();
					break;
			case 5:editwe();
					break;
			case 6:editco();
					break;
			case 7:cout<<"\nTelephone Number :";
					cin>>tele;
					break;
			case 8:cout<<"\nDriving Licence :";
					cin>>dl;
					break;
			default :cout<<"Wrong Option";
					break;
		}
	}
 	void show()
	{
		showi();
		showb();
		showd();
		cout<<"\nTelephone Number :"<<tele;
		cout<<"\nDriving Licence :"<<dl;
	}
};
int finds(int a[],int m,int c)
{
	int i=0,j=-1;
	for(i=0;i<m;i++)
	{
		if(a[i]==c)
		{
			return i;
		}
	}
	return j;
}
int main()
{
	int o,i,j,x=-1,a[100],b=0;
	long long int tel,dls;
	int ins;
	string con,nam,bloo,db;
	float hei,wei;
	num *n[20];
	do{
		cout<<"\nEnter Your Choice from Following \n 1.Add\n 2.Update\n 3.Show Selective\n 4.Show all\n 5.Delete\n 6.Exit\n";
		cin>>o;
		switch(o)
		{
			case 1:	{cout<<"\nInsert Detail of Member : ";
					vn:
					cout<<"\nInsurance Policy Number(5 Digit): ";
					cin>>ins;
					x=finds(a,b,ins);
					if(x!=-1)
					{cout<<"Policy Number Repeated";
					goto vn;}
					a[b]=ins;
					cout<<"\nName : ";
					cin>>nam;
					cout<<"\nBlood Group : ";
					cin>>bloo;
					cout<<"\nDate Of Birth : ";
					cin>>db;
					cout<<"\nHeight : ";
					cin>>hei;
					cout<<"\nWeight : ";
					cin>>wei;
					cout<<"\nContact Address : ";
					cin>>con;
					cout<<"\nTelephone Number : ";
					cin>>tel;
					cout<<"\nDriving Licence : ";
					cin>>dls;
					n[b]=new num(nam,bloo,db,hei,wei,ins,con,tel,dls);
					b++;
					}break;
			case 2:	{cout<<"\nSelect Policy no. to Update ";
					cin>>ins;
					x=finds(a,b,ins);
					if(x==-1)
					cout<<"Member not Found";
					else
					n[x]->edit();
					}break;
			case 3:	{cout<<"Enter Policy no. to Show Details ";
					cin>>ins;
					x=finds(a,b,ins);
					if(x==-1)
					cout<<"Member not Found";
					else
					n[x]->show();
					}break;
			case 4:	for(i=0;i<b;i++)
					{
						cout<<"\nDetails of Members : \n";
						n[i]->show();
					}
					break;
			case 5:	cout<<" Select Policy no. to delete ";
					cin>>ins;
					x=finds(a,b,ins);
					if(x==-1)
					cout<<"Member not Found";
					else
					{
						for(i=x;i<b;i++)
						{
							n[i]=n[i+1];
							a[i]=a[i+1];
						}
						a[b]=0;
						delete n[b];
						b--;
					}
					break;
			case 6:	break;
			default:{cout<<"Wrong Choice";}
		}
	}while(o!=6);
return 0;
}
