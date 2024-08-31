#include <iostream>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int var1=1;
	int *var2;
	unsigned char var3[12]={"Hello World"};
	int **var4;
	unsigned char *var5[2];
	var2=&var1;
	var4=&var2;
	cout<<*var2<<endl;
	var5[1]=&var3[0]+*var2;
	var5[0]=(unsigned char) var4[0];
	cout<<*var4[0]<<endl;
	var3[2]=*var5[0];
	
	cout<<*var5[1]<<endl;
	for (int i=0;i<12;i++)
	cout<<var3[i];
	return 0;
}
