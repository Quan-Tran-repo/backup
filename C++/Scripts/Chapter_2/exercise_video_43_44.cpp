#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int A[10];
void random_gen()
	{
		srand(time(NULL));
		for (int i=0;i<10;i++)
			{
				A[i]=rand()%(10);
				cout<<A[i]<<"\t";
			}
		cout<<endl;
	}
void arrange_arr()
{
	int t;
	for (int i=0;i<10;i++)
		{
			for (int j=i;j<9;j++)
				{
					if (A[i]>A[j+1])
					{
						t=A[i];
						A[i]=A[j+1];
						A[j+1]=t;
					}
				}
			cout<<A[i]<<"\t";
		}
	cout<<endl;
	
}
int main(int argc, char** argv) 
{
	int a,t;
	char again;
	do
	{
		system("CLS");
		t=0;
		cout<<"Insert a number (from 1 to 10): ";cin>>a;
		random_gen();
		cout<<"Rearrange from smallest to largest...\n";Sleep(400);
		arrange_arr();
		for (int i=0;i<10;i++)
			{
				if (a==A[i]) t++;
			}
		if (t>0) cout<<"The number "<<a<<" appeared "<<t<<" times"<<endl;
		else cout<<"The number "<<a<<" does not appear in this array\n";
		Sleep(1000);
		cout<<"Do you want to try again?[y/n] ";cin>>again;
	}
	while(again=='y'||again=='Y');
	system("CLS");
	return 0;
}
