#include <iostream>
using namespace std; 

void fn();
int main(int argc, char *argv[])
{
	fn();
	cout << "hello " <<endl;
	return 0;
}


void fn(){

L2: int sz = 10,i = 0;	
	while(i < sz){
		cout << "in fn: " << i << endl;
		++i;
		if ( i == 5 ){
			goto L1;

		}
	}
L1: cout << "outside loop: " << i <<endl;
}
