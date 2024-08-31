#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void swap_pointer(int *pa,int *pb)
{
	int t;
	t=*pa;
	*pa=*pb;
	*pb=t;
}

int main(int argc,char ** argv)
{
	int a,b;
	cout<<"Please insert a: ";cin>>a;
	cout<<"Please insert b: ";cin>>b;
	int *pa=&a,*pb=&b;
	swap_pointer(pa,pb);
	cout<<"a = "<<a<<"\n"<<"b = "<<b<<endl;
	delete pa,pb;
	return 0;
}
