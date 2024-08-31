#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

int m;
const int n=3,k=4;
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void random_gen(int mat[][n])
	{
		for (int i=0;i<m;i++)
			{
				for (int j=0;j<n;j++)
					{
						mat[i][j]=rand()%(10);
					}
			}
		return;
	}
void random_gen1(int mat[][k])
	{
		for (int i=0;i<m;i++)
			{
				for (int j=0;j<n;j++)
					{
						mat[i][j]=rand()%(10);
					}
			}
		return;
	}
void print_m(int matrix[][n])
	{
		for (int i=0;i<m;i++)
			{
				for (int j=0;j<n;j++)
					{
						cout<<matrix[i][j]<<"\t";
					}
				cout<<endl;
			}		
	}
void print_m1(int matrix[n][k])
	{
		for (int i=0;i<n;i++)
			{
				for (int j=0;j<k;j++)
					{
						cout<<matrix[i][j]<<"\t";
					}
				cout<<endl;
			}			
	}
void print_m2(int matrix[][k])
	{
		for (int i=0;i<m;i++)
			{
				for (int j=0;j<k;j++)
					{
						cout<<matrix[i][j]<<"\t";
					}
				cout<<endl;
			}			
	}
void cau1()
{
	int t;
	cout<<"Please insert m: ";cin>>m;
	int mat[n];
	for (int i=0;i<m;i++) {mat[i]=rand()%100;cout<<mat[i]<<"\t";}
	cout<<endl;
	for (int i=0;i<m/2;i++) 
		{
			t=mat[i];
			mat[i]=mat[m-i-1];
			mat[m-i-1]=t;
		}
	for (int i=0;i<m;i++) cout<<mat[i]<<"\t";cout<<endl;
}
void cau2()
{
	cout<<"Please insert the number of rows: ";cin>>m;
	int A[m][n],B[m][n],C[m][n];
	random_gen(A);
	random_gen(B);
	cout<<"Matrix A: \n";print_m(A);
	cout<<"Matrix B: \n";print_m(B);
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];
	cout<<"C=A+B= \n";
	print_m(C);
}
void cau3()
{
	cout<<"Please insert the number of rows: ";cin>>m;
	int A[m][n],B[n][k],C[m][k];
	random_gen(A);
	random_gen1(B);
	cout<<"Matrix A: \n";print_m(A);
	cout<<"Matrix B: \n";print_m1(B);
	for (int i=0;i<m;i++)
		for (int j=0;j<k;j++) 
			for (int l=0;l<n;l++) C[i][j]=C[i][j]+A[i][l]*B[l][j];
	cout<<"C=A*B= \n";
	print_m2(C);	
}
int main(int argc, char** argv) 
{
	srand(time(NULL));
	cau3();
	/*
	int a,t;
	char again;
	do
	{
		system("CLS");
		t=0;
		random_gen();
		cout<<"Rearrange from smallest to largest...\n";Sleep(400);
		arrange_arr();
		for (int i=0;i<10;i++)
			{
				if (a==mat[i]) t++;
			}
		if (t>0) cout<<"The number "<<a<<" appeared "<<t<<" times"<<endl;
		else cout<<"The number "<<a<<" does not appear in this array\n";
		Sleep(1000);
		cout<<"Do you want to try again?[y/n] ";cin>>again;
	}
	while(again=='y'||again=='Y');
	system("CLS");
	*/
	return 0;
}

	
