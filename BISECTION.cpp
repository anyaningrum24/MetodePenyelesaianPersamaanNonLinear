#include<iostream>
#include<math.h>
#include<iomanip>
#define func(x) x*x-x-2
using namespace std;

double a,b,c,e;
double fa,fb,fc;
int step=1;

int main()
{
	up:
	cout<<"masukkan batas bawah : ";
	cin>>a;
	cout<<"masukkan batas atas : ";
	cin>>b;
	cout<<"masukkan nilai error : ";
	cin>>e;
	
	fa=func(a);
	fb=func(b);
	if(fa*fb>0)
	{
		cout<<"tidak terdapat akar pada interval ["<<a<<","<<b<<"]"<<endl<<endl;
		goto up;
	}
	cout<<"\n\n                             BISECTION METHODE                                 ";
    cout<<"\n==============================================================================================\n";
    cout<<"  No  |     a     |     b      |      f(a)     |     f(b)      |      c      |      f(c)     |\n";
    cout<<"----------------------------------------------------------------------------------------------\n";
	do
	{
	//mencari nilai tengah 
	c=(a+b)/2;
	fc=func(c);
	fa=func(a);
	fb=func(b);
	cout<<setw(3)<<step<<setw(4)<<" |"<<setw(10)<<a<<" |"<<setw(11)<<b<<" |"<<setw(14)<<fa<<" |"<<setw(14)<<fb<<" |"<<setw(12);
        cout<<c<<" |"<<setw(14)<<fc<<" |"<<endl;
	if(fa*fc< 0)
		  {
			b=c;
		  }
		  else
		  {
			a=c;
		  }	
	step=step+1;
	}
	while(fabs(fc)>e);
	cout<<"solusi persamaan linear : "<<c<<endl;
	return 0;
}
