#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int row=3,col=4;
void random_gen(int mat[row][col])
	{
		srand(time(NULL));
		for (int i=0;i<row;i++)
			{
				for (int j=0;j<col;j++)
					{
						mat[i][j]=rand()%(100);
					}
			}
		return;
	}
void print_m(int matrix[row][col])
	{
		for (int i=0;i<row;i++)
			{
				for (int j=0;j<col;j++)
					{
						cout<<matrix[i][j]<<"\t";
					}
				cout<<endl;
			}		
	}
void print_m1(int matrix[col][row])
	{
		for (int i=0;i<col;i++)
			{
				for (int j=0;j<row;j++)
					{
						cout<<matrix[i][j]<<"\t";
					}
				cout<<endl;
			}	
	}
void transpose_mat(int matrix[row][col],int matrix1[col][row])
	{
		int t;
		random_gen(matrix);
		for (int i=0;i<col;i++)
			{
				for (int j=0;j<row;j++)
					{
						matrix1[i][j]=matrix[j][i];
					}
			}
		cout<<"Original matrix: \n";
		print_m(matrix);
		cout<<"Transposed matrix: \n";
		print_m1(matrix1);
	}
int main(int argc, char** argv) 
{
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
	int mat[row][col];
	int mat_t[col][row];
	transpose_mat(mat,mat_t);
	return 0;
}

	
