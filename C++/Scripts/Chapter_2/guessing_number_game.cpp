#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void Sleep_g(int t)
{
	for (int i=0;i<t;i++)
		{
			Sleep(1);
			if (i%50==25) system("COLOR 07");
			if (i%50==0) system("COLOR 0A");
		}
}
void Sleep_r(int t)
{
	for (int i=0;i<t;i++)
		{
			Sleep(1);
			if (i%50==25) system("COLOR 07");
			if (i%50==0) system("COLOR 0C");
		}
}
int main(int argc, char** argv) {
	char play='y';
	int g,a;
	do
	{
		system("CLS");a=0;
		srand(time(NULL));
		int r=rand()%100;
		cout<<"		GUESS THE NUMBER	\n";
		cout<<"The game is simple, I will think of a number and is your job to guess it, you will have 8 attempts to guess\n";
		Sleep(5000);
		cout<<"Are you ready?\n";
		Sleep(2000);
		cout<<"Please guess the number from 0-100: ";
		cin>>g;
		do
		{	
			if (g>r) cout<<"LOWER\n";
			else if(g<r) cout<<"HIGHER\n";
			else break;
			if (a<7) cout<<"Attempt "<<++a<<":";
			else {cout<<"Last attemp: ";a++;}
			cin>>g;
		}
		while (a<8);
		if (a<8) {cout<<"Congratulation you guessed my number: "<<r<<endl;Sleep_g(500);}
		else {cout<<"Better luck next time :), my number was: "<<r<<endl;Sleep_r(500);}
		cout<<"Do you want to play again?[y/n]"<<flush;cin>>play;
	}
	while(play=='y');
	system("CLS");
	return 0;
}
