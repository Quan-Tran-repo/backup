#include <iostream>
#include <math.h>
#include<windows.h>
#include<stdlib.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void caua()
{
	char x,B;
	int A;
	cout<<"Please insert the character: ";
	cin>>x;
	A=int(x);
	B=char(++A);
	cout<<"The character you type in is: "<<x<<"\n";
	cout<<"The ASCII for that character is: "<<--A<<"\n";
	cout<<"And the character after "<<x<<" is "<<B<<flush;
}
void caub()
{
	int x,n,A;
	cout<<"Please insert x and n: \n";
	cin>>x;cin>>n;
	A=pow(x*x+x+1,n)+pow(x*x-x+1,n);
	cout<<"The answer is: "<<A<<flush;
}
void cauc()
{
	double xa,ya,xb,yb,dis;
	cout<<"Please insert the coordinate for A: \n";
	cin>>xa;cin>>ya;
	cout<<"Please insert the coordinate for B: \n";
	cin>>xb;cin>>yb;
	dis=sqrt(pow(xb-xa,2)+pow(yb-ya,2));
	cout<<"The distance between A and B is: "<<dis<<flush;
}
void caud()
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
	char w;
	while(true)
	{
		cout<<"Please insert task want to do: "<<flush;cin>>w;
		switch(int(w))
			{
				case int('a'):
					caua();Sleep(3000);break;
				case int('b'):
					caub();Sleep(3000);break;
				case int('c'):
					cauc();Sleep(3000);break;
				case int('d'):
					caud();Sleep(3000);break;
				case int('B'):
					break;
				default:
					cout<<"Please insert again: "<<flush;
					Sleep(2000);
					break;
			}
		if (int(w)==int('B')) break;
		system("CLS");
	}
	return 0;
}
