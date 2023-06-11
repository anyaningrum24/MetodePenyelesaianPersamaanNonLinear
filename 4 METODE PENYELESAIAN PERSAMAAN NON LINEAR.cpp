#include<iostream>
#include<math.h>
#include<iomanip>
#define f(x) x*x*x-6*x*x+11*x-5.9
#define g(x) 3*x*x-12*x+11

using namespace std;

double a = 2.5;
double b = 3.5;
double c,e;
double fa,fb,fc;
double x0 = 3.5; //nilai awal metode newton raphson
double s0=2.5;
double s1=3.5; //dua nilai awal metode secant
double x1,f0,f1,f2,g0,s2;
int iterasi=1;
int pilihan;

int main()
{
	cout<<"======= Menu Penyelesaian Fungsi Persamaan Non Linier =========="<<endl;
	cout<<"1. Bisection Method\n2. Regula Falsi Method\n3. Newton Raphson Method\n4. Secant Method"<<endl<<endl;
	cout<<"Masukkan Pilihan Menu : ";
	cin>>pilihan;
	system("cls");
	cout<< setprecision(3)<< fixed;
	if(pilihan==1)
	{
		cout<<"Welcome To Program Bisection Method"<<endl<<endl;
		cout<<"masukkan nilai error : ";
		cin>>e;
	
		fa=f(a);
		fb=f(b);
		if(fa*fb>0)
		{
			cout<<"tidak terdapat akar pada interval ["<<a<<","<<b<<"]"<<endl<<endl;
			exit(0);
		}
		cout<<"\n\n                                    BISECTION METHODE                                 ";
	    cout<<"\n==============================================================================================\n";
	    cout<<"  No  |     a     |     b      |      f(a)     |     f(b)      |      c      |      f(c)     |\n";
	    cout<<"----------------------------------------------------------------------------------------------\n";
		do
		{
			//mencari nilai tengah 
			c=(a+b)/2;
			fc=f(c);
			fa=f(a);
			fb=f(b);
			cout<<setw(3)<<iterasi<<setw(4)<<" |"<<setw(10)<<a<<" |"<<setw(11)<<b<<" |"<<setw(14)<<fa<<" |"<<setw(14)<<fb<<" |"<<setw(12);
		        cout<<c<<" |"<<setw(14)<<fc<<" |"<<endl;
			if(fa*fc< 0)
				  {
					b=c;
				  }
				  else
				  {
					a=c;
				  }	
			iterasi=iterasi+1;
		}
		while(fabs(fc)>e);
		cout<<"solusi persamaan non linear : "<<c<<endl;
	}
	
	else if(pilihan==2)
	{
		//input
		cout<<"Welcome To Program Regula Falsi Method"<<endl<<endl;
		cout<<"masukkan nilai error : ";
		cin>>e;
	
		fa=f(a);
		fb=f(b);
		if(fa*fb>0)
		{
			cout<<"tidak terdapat akar pada interval ["<<a<<","<<b<<"]"<<endl<<endl;
			exit(0);
		}
			
		cout<<"\n\n                                 	 REGULA FALSI METHOD                                   ";
	    cout<<"\n==============================================================================================\n";
	    cout<<"  No  |     a     |     b      |      f(a)     |     f(b)      |      c      |      f(c)     |\n";
	    cout<<"----------------------------------------------------------------------------------------------\n";
		do
		{
			//mencari nilai c
			fa=f(a);
			fb=f(b);
			c= a - (fa*((b-a)/(fb-fa)));
			fc=f(c);
			cout<<setw(3)<<iterasi<<setw(4)<<" |"<<setw(10)<<a<<" |"<<setw(11)<<b<<" |"<<setw(14)<<fa<<" |"<<setw(14)<<fb<<" |"<<setw(12);
		    cout<<c<<" |"<<setw(14)<<fc<<" |"<<endl;
			if(fa*fc< 0)
				  {
					b=c;
				  }
				  else
				  {
					a=c;
				  }
			iterasi=iterasi+1;
		}
		while(fabs(fc)>e);
		cout<<"Solusi Persamaan Non Linear : "<<c<<endl;
	}
	
	else if(pilihan==3)
	{
     //input
     cout<<"Welcome To Program Newton Raphson Method"<<endl<<endl;
	 cout<<"Masukkan nilai error : ";
	 cin>>e;
	 

		cout<<"\n\n                   NEWTON RAPHSON METHODE                  ";
	    cout<<"\n============================================================\n";
	    cout<<"  No  |    x(i)   |   x(i+1)   |    f(xi)    |    f(xi+1)   |\n";
	    cout<<"-------------------------------------------------------------\n";
	 do
	 {
		g0 = g(x0);
		f0 = f(x0);
		if(g0==0.0)
		{
			cout<<"Mathematical Error.";
			exit(0);
		}

		x1 = x0 - (f0/g0);
		f1 = f(x1);
		cout<<setw(3)<<iterasi<<setw(4)<<" |"<<setw(10)<<x0<<" |"<< setw(11)<<x1<<" |"<<setw(12)<<f0<<" |"<<setw(13)<<f1<<" |" <<endl;
		x0 = x1;
			
		
		iterasi=iterasi+1;
	 }
	 while(fabs(f1)>e);
	 cout<< endl<<"Solusi Persamaan Non Linier : "<<x1;	
	}
	
	else if(pilihan==4)
	{
	//input
     cout<<"Welcome To Program Secant Method"<<endl<<endl;
	 cout<<"Masukkan nilai error : ";
	 cin>>e;	
	 
	cout<<"\n\n                                 	 SECANT METHOD                                   ";
	cout<<"\n================================================================================================\n";
	cout<<"  No  |     s0     |     s1      |     s2      |      f(s0)     |     f(s1)     |      f(s2)    |\n";
	cout<<"-------------------------------------------------------------------------------------------------\n";
	
	do
	{
	f0 = f(s0);
	f1 = f(s1);
	if(f0 == f1)
		{
			cout<<"Mathematical Error.";
			exit(0);
		}

	s2 = s1 - ((f1*(s1 - s0))/(f1-f0));
	f2 = f(s2);

	cout<<setw(3)<<iterasi<<setw(4)<<" |"<<setw(11)<<s0<<" |"<<setw(12)<<s1<<" |"<<setw(12)<<s2<<" |"<<setw(15)<<f0<<" |"<<setw(14);
	cout<<f1<<" |"<<setw(14)<<f2<<" |"<<endl;

	s0 = s1;
	f0 = f1;
	s1 = s2;
	f1 = f2;

	iterasi = iterasi + 1;
	 }
	 while(fabs(f2)>e);
	 cout<< endl<<"Solusi Persamaan Non Linier : "<< s2;	
	}

	else 
	{
		cout<<"Menu yang Anda masukkan salah!";
	}
	return 0;
}
