#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class personal
{
    string name;
    string address;
    long long int mob_no;
public:
    personal()
    {
        name="Aman\0";
        address="Allahbad\0";
        mob_no=7011251516;
    }
    personal(string nam,string addres,long long int mobn)
    {
        name=nam;
        address=addres;
        mob_no=mobn;
    }
    void display()
    {
        cout<<"THe name is:: ";
        cout<<name<<"\n";
        cout<<"Address:: ";
        cout<<address<<"\n";
        cout<<"The mobile no is:: ";
        cout<<mob_no<<"\n";
    }
};
class academic
{
    int sgpa;
    string school;
    string college;

public:
    academic()
    {
        school="Army Public School\0";
        college="AIT PUNE\0";
        sgpa=10;
    }
    academic(string schl,string colleg,int x)
    {
        school=schl;
        college=colleg;
        sgpa=x;
    }
    void display()
    {
        cout<<"THE SCHOOL NAME AND COLLEGE NAMES ARE::\n";
        cout<<school<<"\n"<<college<<"\n";
        cout<<"THE cummulative score is :: ";
        cout<<sgpa<<" "<<"sgpa"<<"\n";
    }
};
class professinal
{
    int salary;
    string position;
public:
    professinal()
    {
        salary=50000;
        position="CEO\0";
    }
    professinal(int a,string b)
    {
        salary=a;
        position=b;
    }
    void display()
    {
        cout<<"\nThe current salary is::"<<salary<<"per month\n";
        cout<<"current position is::"<<position<<"\n";

    }
};
class biodata:public personal,public academic,public professinal
{
    int experience;
public:
    biodata()
    {
        experience=10;
    }
    biodata(string nam,string addres,long long int mobn,string schl,string colleg,int x,int a,string k,int m):personal(nam,addres,mobn),academic(schl,colleg,x),professinal(a,k)
    {
        experience=m;
    }
    void displaydata()
    {
        cout<<"\nTHE DETAILS ARE\n";
        personal::display();
        academic::display();
        professinal::display();
        cout<<"EXPERIENCE::"<<experience<<" "<<"years\n";
    }
};
int main()
{
    int x,m,w;
 	long long int mob;
	string name,address,school,college,position;
    cout<<"Report:\n";
    cout<<"Enter MOBILE_NO:";
    cin>>mob;
    cout<<"\n"<<"ENTER NAME AND ADDRESS: \n";
    cin>>name;
    cout<<"\n";
    cin>>address;
    cout<<"\nENTER--SCHOOL NAME,COLLEGE NAME,SGPA :\n";
    cin>>school;
    cout<<"\n";
    cin>>college;
    cout<<"\n";
    cin>>x;
    cout<<"\nENTER THE SALARY AND POSITION\n";
    cin>>w;
    cin>>position;
    cout<<"\nENTER THE NO OF YEARS OF EXPERIENCE\n";
    cin>>m;
    biodata *b1;
    b1=new biodata(name,address,mob,school,college,x,w,position,m);
    b1->displaydata();
}
