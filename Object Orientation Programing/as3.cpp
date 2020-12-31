#include<iostream>
using namespace std;
class complex
{
    float real,img;
    public:
    friend complex operator +(complex &, complex &);
    friend complex operator -(complex &, complex &);
    friend istream & operator >>(istream &, complex &);
    friend ostream & operator <<(ostream &, complex &);
    complex operator *(complex &c)
    {
        complex d;
        d.real=(real*(c.real))-(img*(c.img));
        d.img=(img*(c.real))+(real*(c.img));
        return d;
    }
    complex operator /(complex &c)
    {
		float s;
        complex d;
		s=((c.real*c.real)-(c.img*c.img));
		d.real=(real*(c.real))+(img*(c.img))/s;
        d.img=(img*(c.real))-(real*(c.img))/s;
        return d;
    }
    complex()
    {
        real=0;
        img=0;
    }
    complex(int&n,int&m)
    {
        real=n;
        img=m;
    }
};
complex operator +(complex &c1, complex &c2)
{
    complex c;
    c.real= c1.real+c2.real;
    c.img= c1.img+c2.img;
    return c;
}
complex operator -(complex &c1, complex &c2)
{
   complex c;
   c.real= c1.real-c2.real;
   c.img= c1.img-c2.img;
   return c;
}
istream & operator >>(istream &in, complex &c)
{
    in>>c.real>>c.img;
    return in;
}
ostream & operator <<(ostream &out, complex &c)
{
    out<<c.real<<" +i"<<c.img;
    return out;
}
int main()
{
    complex c1,c2,c3;
    int ch;
    cout<<"\nEnter the Real part and Imaginary part of First complex no.";
    cin>>c1;
	cout<<"\nEnter the Real part and Imaginary part of Second complex no.";
    cin>>c2;
    do
    {
        cout<<"\nSelect the Following Option :";
        cout<<"\n1.Addition";
        cout<<"\n2.Subtraction";
        cout<<"\n3.Multiplcation";
        cout<<"\n4.Divide";
        cout<<"\n5.Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:     c3= c1+c2;
                        cout<<"\nAddtion "<<c3;
                        break;
            case 2:     c3= c1-c2;
                        cout<<"\nSubtration "<<c3;
                        break;
            case 3:     c3= c1*c2;
                        cout<<"\nMultiplication "<<c3;
                        break;
            case 4:     c3= c1/c2;
                        cout<<"\nDivision "<<c3;
                        break;
           	case 5:		break;
            default:    cout<<"\nWrong Option";
                        break;
        }
    }while(ch!=5);
    return 0;
}
