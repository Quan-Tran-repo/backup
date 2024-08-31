#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// ADDING 2 MATRIX (using pointer)

//Swapping 2 pointer
void swap_p(int *pa,int *pb)
{
	int t;
	*pa=t;*pa=*pb;*pb=t;
}

//Creating a matrix using pointer
int** cre_arr(int **arr,int rows, int columns)
{
	for (int i=0;i<rows;i++) 
		{
			arr[i]=new int[columns];		
		}
	return arr;	
}

//Generating random matrix value for a matrix
void rand_gen(int **arr,int rows,int columns)
{
	for (int i=0;i<rows;i++)
		for (int j=0;j<columns;j++) arr[i][j]=rand()%150-50;
}

//Print matrix
void print_m(int **arr,int rows, int columns)
{
	for (int i=0;i<rows;i++)
		{
			for (int j=0;j<columns;j++) cout<<arr[i][j]<<"\t";
			cout<<endl;
		}
}

//Find the maximum value in the matrix
int find_max(int **arr,int rows,int columns)
{
	int m;
	m=arr[0][0];
	for (int i=0;i<rows;i++)
		for (int j=0;j<columns;j++) if (arr[i][j]>m) m=arr[i][j];
	return m;
}

//Add 2 matrix 
int** add_matrix(int **C,int **A,int **B,int rows, int columns)
{
	for (int i=0;i<rows;i++)
		for (int j=0;j<columns;j++) C[i][j]=A[i][j]+B[i][j];
	return C;		
}

//Full program adding 2 matrix
void ex_75()
{
	srand(time(NULL));
	int rows,columns,max;
	
	//Recive the number of row and columns for the 2 matrixs
	cout<<"Please insert the rows: ";cin>>rows;
	cout<<"Please insert the columns: ";cin>>columns;
	
	//Creating the matrix A B C
	int **A,**B,**C;
	A=new int*[rows];
	B=new int*[rows];
	C=new int*[rows];
	A= cre_arr(A,rows,columns);
	B= cre_arr(B,rows,columns);
	C= cre_arr(C,rows,columns);
	
	//Given value to matrix A and B
	rand_gen(A,rows,columns);
	rand_gen(B,rows,columns);
	cout<<"A= \n";
	print_m(A,rows,columns);
	cout<<"B= \n";
	print_m(B,rows,columns);
	
	//Adding 2 matrix A and B
	cout<<"C = A + B = \n";
	C= add_matrix(C,A,B,rows,columns);
	print_m(C,rows,columns);
	delete A,B,C;
}
int main(int argc, char** argv) 
{
	ex_75();
	return 0;
}
