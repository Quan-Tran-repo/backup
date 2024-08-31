#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main(int argc,char ** argv)
{
	int a,b,t;
	cout<<"Please insert a: ";cin>>a;
	cout<<"Please insert b: ";cin>>b;
	int *pa=&a,*pb=&b;
	t=*pa;
	*pa=*pb;
	*pb=t;
	cout<<a<<"\n"<<b<<endl;
	delete pa,pb;
	return 0;
}
