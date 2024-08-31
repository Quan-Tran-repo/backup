#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void cau1()
{
	int n,flag;
	cout<<"Please insert number n: ";
	cin>>n;
	for (int i=2;i<n;i++)
		{
			if (n%i==0) {flag=1;break;}
		}
	if (flag==1) cout<<n<<" is not a prime number\n";
	else cout<<n<< " is a prime number\n";
}
void cau2()
{
	int n,j;
	cout<<"Please insert number n: ";
	cin>>n;
	if (n==1) cout<<"There are no prime number";
	else cout<<"The prime numbers are: 2";
	for (int i=3;i<=n;i++)
		{
			for (j=2;j<=i;j++)
				if(i%j==0) break;
			if (j==i) cout<<", "<<i;
		}
	cout<<endl;
}
void cau3()
// s(x,n)=x+(x^3)/3!+x^5/5!+...+(x^(2*n+1))/(2*n+1)!
{
	int x,n,N;
	int num=1,deno=1;
	double s=0;
	cout<<"Please insert number x,n:";cin>>x;cin>>n;
	N=2*n+1;
	for (int i=1;i<=N;i++)
	{
		if(i%2==1)
			{	
				num=pow(x,i);
				deno=1;
				for (int j=1;j<=i;j++)
					{
						deno*=j;
					}
				s+=double(num)/deno;
				//cout<<s<<endl;
				//cout<<"num: "<<num<<", deno: "<<deno<<endl; //TEST
			}
	}
	cout<<"The result for the series is: \n"<<s;
}
void cau4()
{
	int n;
	double s;
	cout<<"Please insert number n: ";
	cin>>n;
	for (int i=n;i>0;i--)
		{
			s=sqrt(s+i);
		}
	cout<<"The result of the series is: "<<s<<endl;
}
void cau5()
{
	int x,tram,chuc,dv;
	cout<<"Please insert a 3 digit number x: ";
	cin>>x;
	tram=x/100;
	chuc=x/10%10;
	dv=x%10;
	cout<<"The invert of "<<x<<" is: "<<dv*100+chuc*10+tram<<flush;
}
int main(int argc, char** argv) 
{
	int t,r;
	while(1)
	{
		cout<<"Which question you want to check?\n";
		cout<<"1 for finding the prime number\n";
		cout<<"2 for finding the lower prime number\n";
		cout<<"3 for calculating a series\n";
		cout<<"4 for calculating a series\n";
		cout<<"5 for inverting a 3 digit number\n"<<flush;cin>>t;
		system("CLS");
		if (t==1) cau1();
		else if(t==2) cau2();
		else if(t==3) cau3();
		else if(t==4) cau4();
		else if(t==5) cau5();
		else break;
		cin>>r;
		cout<<endl<<"Reset in ";
		Sleep(1000);cout<<"3...";
		Sleep(1000);cout<<"2...";
		Sleep(1000);cout<<"1...\n"<<flush;
		system("CLS");
	}
	system("CLS");
	return 0;
}
