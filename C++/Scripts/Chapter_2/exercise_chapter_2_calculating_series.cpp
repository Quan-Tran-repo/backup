#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

int x,n;
double s;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// s(x,n)=x+(x^2)/2!+x^3/3!+...+(x^n)/n!
void calculate_series()
{
	int num=1;
	int deno=1;
	for (int i=1;i<n+1;i++)
		{
			num=1;deno=1;
			for (int j=1;j<i+1;j++) 
				{
					num*=x;
					deno*=j;
				}
			s+=double(num)/deno;
			//cout<<s;
			//cout<<"num: "<<num<<" deno: "<<deno<<endl; //TEST
		}
}
int main(int argc, char** argv) 
{
	while(true)
	{
		s=0;
		cout<<"Please insert x,n: ";
		cin>>x;cin>>n;
		calculate_series();
		cout<<"The result of the series is: "<<s<<flush;
		Sleep(2000);
		system("CLS");
	}
	return 0;
}
