#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void cau1() //f(x)=A[0]*x^n+A[1)*x^(n-1)+...+A[n]*x
{
	int x,n,fx;
	
	//Delcaring x and n
	cout<<"Please insert the value n: \n";cin>>n;
	cout<<"Please insert the value x: \n";cin>>x;
	double* A;
	A=new double[n];
	
	//Generating random value for array A
	srand(time(NULL));
	cout<<"A=\n";
	for (int i=0;i<n;i++)
	{
		A[i]=rand()%10;
		cout<<A[i]<<"\t";
	}
	cout<<endl;
	
	//Calculating fx
	for (int i=0;i<n;i++)
	{
		fx+=(A[i])*pow(x,n-i-1);
	}
	
	//Printing the result
	cout<<"The result for f(x)= "<<fx<<flush;
	delete A;
}
void cau2() //Calculatind the distance between 2 vectors with N-dimensions
{
	double *p1,*p2;
	int N,d;
	
	//Delcaring N and p1 p2
	cout<<"Please insert the value N: ";cin>>N;
	p1=new double[N];
	p2=new double[N];
	
	//Generating random value for 2 vectors p1 and p2
	srand(time(NULL));
	cout<<"p1="<<endl;
	for (int i=0;i<N;i++)
	{
		p1[i]=rand()%10;
		p2[i]=rand()%10;
		cout<<p1[i]<<"\t";
	}
	cout<<endl<<"p2=\n";
	
	//Calculating the distance between 2 vectors
	for (int i=0;i<N;i++)
	{
		d+=pow(p2[i]-p1[i],2);
		cout<<p2[i]<<"\t";
	}
	cout<<endl;
	cout<<"d(p,q)= "<<float(sqrt(d))<<flush;
	delete p1,p2;
}
int main(int argc, char** argv) {
	cau2();
	return 0;
}
