#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

int s,e;
const int cost_under_100=600;
const int cost_under_150=700;
const int cost_under_200=900;
const int cost_above_200=1100;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void calculate_bill()
{
	if (e>100)
		s=s+100*cost_under_100;
	else 
		s=e*cost_under_100;
	if (e>150)
		s=s+50*cost_under_150;
	else if (e>100)
		s=s+(e-100)*cost_under_150;
	if (e>200)
		s=s+50*cost_under_200+(e-200)*cost_above_200;
	else if (e>150)
		s=s+(e-150)*cost_under_200;
}
int main(int argc, char** argv) 
{
	while(true)
	{
		cout<<"Please insert the electric number: ";
		cin>>e;
		calculate_bill();
		cout<<"The amount you need to pay for is: "<<s<<flush;
		Sleep(2000);
		s=0;e=0;
		system("CLS");
	}
	return 0;
}
