#include <iostream>
using namespace std; 


void fn(void){
	extern int val = 0;
	static int i = 0;
	cout<< "static fn"<< endl;
	cout << i <<endl;
	i++;
}

int main(int argc, char *argv[])
{
	
	fn();
	fn();
	fn();
	return 0;
}
