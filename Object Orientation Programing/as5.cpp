#include<iostream>
using namespace std;
class shapes
{
	private:
	double m,n;
	public:
	void input()
	{
		cin>>m>>n;
	}
	double getm()
	{
		return m;
	};
	double getn()
	{
		return n;
	}
	virtual	void area() =0;
};
class triangle:public shapes
{
	public:
	void area()
	{
		double areas,x,y;
		x=getm();
		y=getn();
		areas=(x*y)/2;
		cout<<"Area of Triangle : "<<areas;
	}
};
class rectangle:public shapes
{
	public:
	void area()
	{
		double areas,x,y;
		x=getm();
		y=getn();
		areas=(x*y);
		cout<<"Area of rectangle : "<<areas;
	}
};
int main()
{
	shapes *s1,*s2;
	triangle t;
	rectangle r;
	cout<<"\nInput 2 Measurement Of Triangle ";
	s1=&t;
	s1->input();
	s1->area();
	cout<<"\nInput 2 Measurement Of Rectangle ";
	s2=&r;
	s2->input();
	s2->area();
return 0;
}
