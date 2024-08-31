#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// FIND THE LARGEST ELEMENT IN A SQUARE MATRIX (using pointer)
void swap_p(int *pa,int *pb)
{
	int t;
	*pa=t;*pa=*pb;*pb=t;
}
void rand_gen(int **arr,int size)
{
	for (int i=0;i<size;i++)
		for (int j=0;j<size;j++) arr[i][j]=rand()%150-50;
}
void print_m(int **arr,int size)
{
	for (int i=0;i<size;i++)
		{
			for (int j=0;j<size;j++) cout<<arr[i][j]<<"\t";
			cout<<endl;
		}
}
int find_max(int **arr,int size)
{
	int m;
	m=arr[0][0];
	for (int i=0;i<size;i++)
		for (int j=0;j<size;j++) if (arr[i][j]>m) m=arr[i][j];
	return m;
}
int main(int argc, char** argv) 
{
	srand(time(NULL));
	int size,max;
	cout<<"Please insert the size of the matrix: ";cin>>size;
	int **arr;
	arr=new int*[size];
	for (int i=0;i<size;i++) 
		{
			arr[i]=new int[size];			
		}
	rand_gen(arr,size);
	print_m(arr,size);
	max=find_max(arr,size);
	cout<<"The largest number in the matrix is: "<<max<<endl;
	delete arr;
	return 0;
}
