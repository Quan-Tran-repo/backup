#include <iostream>
#include <windows.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void reenter()
{
	cout<<"That's not a valid date"<<"\n"<<"Please insert again: "<<flush;
	Sleep(1000);
	system("CLS");
}

void cau1()//Find the maximum number
{
	int a,b,c;
	cout<<"Please insert 3 number a,b,c: ";
	cin>>a;cin>>b;cin>>c;
	if (a>b)
		{
			if (a>c) cout<<"The maximum number is: "<<a;
			else cout<<"The maximum number is: "<<c;
		}
	else 
		{
			if (b>c) cout<<"The maximum number is: "<<b;
			else cout<<"The maximum number is: "<<c;
		}		
}
void cau2()//Find out how many days in t month
{
	int t,y;
	// Test if a valid month
	do
	{
		t=0;
		cout<<"Please insert desire month: ";
		cin>>t;
		if(t>12) reenter();
	}
	while(t>12);
	// Check which month and print out the number of days in that specific month
	if ((t%2==1)&&(t!=2))
		{
			if (t<8) cout<<"This month has 31 days";
			else cout<<"This month has 30 days";
		}
	else if ((t<8)&&(t!=2)) cout<<"This month has 30 days";
	else if ((t>=8)&&(t!=2)) cout<<"This month has 31 days";
	if (t==2)
		{
			//Check if it is a leap year or not
			cout<<"Please insert the year: ";cin>>y;
			if ((y%4==0)&&(y%100!=0)) cout<<"This month has 29 days";
			else if(y%400==0) cout<<"This month has 29 days";
			else cout<<"This month has 28 days";		
		}
}
void cau4()
{
	int d,m,y;//d=day,m=month,y=year
	int l,v,f;//l = leap year, v = valid, f=flag
	do
	{
		cout<<"Please insert the year: ";cin>>y;
		//Test if it leap year or not?
		if ((y%4==0)&&(y%100!=0)) l=1;
		else if(y%400==0) l=1;
		else l=0;
		cout<<"Please insert the month: ";cin>>m;
		cout<<"Please insert the date: ";cin>>d;
		// Test if the date was valid or not?
		if (m>12) v=0;
		else if ((m%2==1)&&(m<8)||(m%2==0)&&(m>7)) 
		{
			if (d>31) v=0;
			else v=1;
		}
		else if((m!=2)&&(d>30)) v=0;
		else if((m==2)&&(d>28)&&(l==0)) v=0;
		else if((m==2)&&(d>29)&&(l==1)) v=0;
		else v=1;
		if (v==0) reenter();
	}
	while(v==0);
	cout<<"The date is: "<<d<<"/"<<m<<"/"<<y<<"\n";
	//Test if last day of the month
	if ((m%2==1)&&(m<8)||(m%2==0)&&(m>7)) 
		{
			if (d==31) f=1;
			else f=0;
		}
	else if((m!=2)&&(d==30)) f=1;
	else if((m==2)&&(d==28)&&(l==0)) f=1;
	else if((m==2)&&(d==29)&&(l==1)) f=1;
	else f=0;
	//Print the next day
	if (f==1) cout<<"The next date is: "<<1<<"/"<<++m<<"/"<<y;
	else cout<<"The next date is: "<<++d<<"/"<<m<<"/"<<y;
		
}
int main(int argc, char** argv) 
	{
		int t;
		while(1)
		{
			cout<<"Which question you want to check?\n";
			cout<<"1 for finding max number between 3 numbers\n";
			cout<<"2 for printing the number of days in a month\n";
			cout<<"3 for printing the following date\n"<<flush;cin>>t;
			system("CLS");
			if (t==1) cau1();
			else if(t==2) cau2();
			else if(t==3) cau4();
			else if(t==4) break;
			cout<<endl<<"Reset in ";
			Sleep(1000);cout<<"3...";
			Sleep(1000);cout<<"2...";
			Sleep(1000);cout<<"1...\n"<<flush;
			system("CLS");
		}
		return 0;
	}
