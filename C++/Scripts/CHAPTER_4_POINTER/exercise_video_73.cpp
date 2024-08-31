#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void swap_pointer(int *pa,int *pb)
{
	int t;
	t=*pa;
	*pa=*pb;
	*pb=t;
}

void rand_gen(int *arr,int size)
{
	for (int i=0;i<size;i++) 
	{
		*(arr+i)=rand()%10;
		cout<<*(arr+i)<<"\t";
	}
	cout<<endl;
}

void arrange(int *arr,int size)
{
	cout<<"Rearranging..."<<endl;
	Sleep(500);
	for (int i=0;i<size;i++)
	{
		for (int j=i+1;j<size;j++) 
		{
			if (*(arr+i)<*(arr+j)) swap_pointer(arr+i,arr+j);	
		}
		cout<<*(arr+i)<<"\t";
	}
	cout<<endl;
}
int main(int argc,char ** argv)
{
	int size;
	srand(time(NULL));
	cout<<"Please insert size of array: ";cin>>size;
	int *arr;
	arr=new int[size];
	rand_gen(arr,size);
	arrange(arr,size);
	delete arr;
	return 0;
}
